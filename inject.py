import os
import subprocess
import shutil

hookAddress = hex(0x808D120C)

dolLocation = os.path.join("DOL", "main.dol")
patchXML = os.path.join("patch.xml")
linkerScript = os.path.join("execute.ld")

includeFolder = os.path.join("include")

compilerFlags = [
    "-isystem", f"{includeFolder}",
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
    os.path.join("src", "GuardOverhaul.cc"),
    os.path.join("src", "InvincibleTweaks.cc"),
    os.path.join("src", "RemoveAbility.cc"),
    os.path.join("src", "main.cc")
    # os.path.join("src", "abilitymodifier.cc")
]

objectFiles = []

# Utility


def cut(source: str, destination: str, file: str):
    shutil.move(os.path.join(source, file), os.path.join(destination, file))


def splitExtension(file: str):
    baseName = os.path.basename(file)
    pre, ext = os.path.splitext(baseName)
    return pre


class CMDCommands:
    def __init__(self, program):
        self.program = program

    def execute(self, args: str):
        subprocess.run(f"{self.program} {args}", shell=True)


# commands

assembler = CMDCommands("powerpc-eabi-as")
compiler = CMDCommands("powerpc-eabi-g++")
linker = CMDCommands("powerpc-eabi-ld")
WIT = CMDCommands("wit")


def createCodeHook():
    print("[1/5]: Creating code hook...")
    assembler.execute(f"{hookFile} -o hook.o")


def compileSourceFiles():
    print("[2/5]: Compiling source files...")

    for sourceFiles in codeFiles:
        compiler.execute(f"{sourceFiles} {compilerFlagsString}")


def linkObjectFiles():
    print("[3/5]: Linking object files...")

    if not os.path.exists("build"):
        os.mkdir("build")

    if os.path.exists("objects"):
        shutil.rmtree("objects", ignore_errors=True)
    os.mkdir("objects")

    for sourceFiles in codeFiles:
        prefix = splitExtension(sourceFiles)
        objectFiles.append(f"{prefix}.o")

    for key, objects in enumerate(objectFiles):
        cut(".", "objects", f"{objects}")
        objectFiles[key] = os.path.join("objects", f"{objects}")

    objectFilesString = " ".join([*objectFiles])

    print(objectFilesString)

    linker.execute(
        f"{linkerFlagsString} hook.o {
            objectFilesString} -o build/linked_output.elf"
    )

    os.remove("hook.o")


def patchELFIntoDOL():
    print("[4/5]: Patching ELF into DOL file...")

    shutil.copy(f"{dolLocation}", "build")
    WIT.execute(
        f"dolpatch build/main.dol new=text,AUTO xml={
            patchXML} entry={hookAddress} --source ."
    )


def replaceDumpDOL():
    print("[5/5]: Replacing DOL in game dump...")

    buildDirectory = os.path.join("build", "main.dol")
    dumpDirectory = os.path.join("Dump", "sys")

    shutil.copy(buildDirectory, dumpDirectory)


def injectMain():
    createCodeHook()
    compileSourceFiles()
    linkObjectFiles()
    patchELFIntoDOL()
    replaceDumpDOL()
    print("Done :)")


injectMain()
