# KRTDL-Suffering
A mod of RTDL that adds a bit more challenge to the gameplay. Greatly a WIP, but updates will be constant.

# How to Build
**Prerequisites:**
- [devkitpro](https://devkitpro.org/wiki/Getting_Started "devkitpro")
- [Wiimm's ISO Tools](https://wit.wiimm.de/ "Wiimm's ISO Tools")
- [Python](https://www.python.org/ "Python")

Place a fresh *main.dol* of Return to Dream Land in the DOL folder, then run inject.py. The output will be generated in the *build* folder. However, the DOL that you use must meet two criteria:
- It must be the **NTSC** version of RTDL. To verify, check that your game has Game ID `SUKE01`.
- The dump must be produced from an **ISO** of RTDL. Before dumping, make sure that your game is an ISO. If not, you can convert with Wiimm's Tools (check Prerequisities).
