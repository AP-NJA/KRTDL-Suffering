import os
import subprocess
import shutil

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
    os.path.join("src", "RemoveAbility.cc"),
    os.path.join("src", "DisableInvincible.cc")
]

objectFiles = []

# Utility functions


def splitExtension(file: str):
    baseName = os.path.basename(file)
    pre, ext = os.path.splitext(baseName)
    return pre


def createCodeHook():
    print("[1/4]: Creating code hook...")
    subprocess.run(
        f"powerpc-eabi-as {hookFile} -o hook.o", shell=True
    )


def compileSourceFiles():
    print("[2/4]: Compiling source files...")

    for sourceFiles in codeFiles:
        subprocess.run(
            f"powerpc-eabi-g++ {sourceFiles} {compilerFlagsString}", shell=True
        )


def linkObjectFiles():
    print("[3/4]: Linking object files...")

    if os.path.join("build") is False:
        os.mkdir("build")

    for sourceFiles in codeFiles:
        prefix = splitExtension(sourceFiles)
        objectFiles.append(f"{prefix}.o")

    objectFilesString = " ".join([*objectFiles])
    subprocess.run(
        f"powerpc-eabi-ld hook.o {linkerFlagsString} {objectFilesString} -o build/linked_output.elf", shell=True
    )

    os.remove("hook.o")

    for objects in objectFiles:
        os.remove(f"{objects}")


def patchELFIntoDOL():
    print("[4/4]: Patching ELF into DOL file...")

    shutil.copy(f"{dolLocation}", "build")
    subprocess.run(
        f"wit dolpatch build/main.dol new=text,AUTO xml={patchXML} entry={hookAddress} --source .", shell=True
    )


def injectMain():
    createCodeHook()
    compileSourceFiles()
    linkObjectFiles()
    patchELFIntoDOL()
    print("Done :)")


injectMain()
