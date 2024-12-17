import sys
import os
import subprocess


def getPlatformCommands() -> tuple:
    copyCommand = ""
    deleteCommand = ""

    if (sys.platform == "win32"):
        copyCommand = "copy"
        deleteCommand = "del"
    else:
        copyCommand = "cp"
        deleteCommand = "rm"
    return copyCommand, deleteCommand


copyCommand, deleteCommand = getPlatformCommands()


hookAddress = hex(0x808D120C)

dolLocation = os.path.join("DOL", "main.dol")
patchXML = os.path.join("patch.xml")
linkerScript = os.path.join("execute.ld")

compilerFlags = [
    "-O0",
    "-c"
]
compilerFlagsString = " ".join([*compilerFlags])

linkerFlags = [
    f"-T {linkerScript}"
]
linkerFlagsString = " ".join([*linkerFlags])

hookFile = os.path.join("hook.s")

codeFiles = [
    os.path.join("RemoveAbility.cc"),
    os.path.join("DisableInvincible.cc")
]

objectFiles = []

print("[1/4]: Creating code hook...")
subprocess.run(f"powerpc-eabi-as {hookFile} -o hook.o", shell=True)

print("[2/4]: Compiling source files...")
for sourceFiles in codeFiles:
    subprocess.run(
        f"powerpc-eabi-g++ {sourceFiles} {compilerFlagsString}", shell=True)

print("[3/4]: Linking object files...")
subprocess.run("mkdir build", shell=True)

for sourceFiles in codeFiles:
    objects = os.path.basename(sourceFiles)
    pre, ext = os.path.splitext(objects)
    objectFiles.append(f"{pre}.o")

objectFilesString = " ".join([*objectFiles])
subprocess.run(f"powerpc-eabi-ld hook.o {linkerFlagsString} {
               objectFilesString} -o build/linked_output.elf", shell=True)
subprocess.run(f"{deleteCommand} hook.o {objectFilesString}", shell=True)

print("[4/4]: Patching ELF into DOL file...")
subprocess.run(f"{copyCommand} {dolLocation} build", shell=True)
subprocess.run(
    f"wit dolpatch build/main.dol new=text,AUTO xml={patchXML} entry={hookAddress} --source .", shell=True)

print("Done :)")
