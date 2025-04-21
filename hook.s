.global HOOK
HOOK:
    lis %r3, (_Z8mainHookv+0x48000001-0x804e9f44)@ha
    addi %r3, %r3, (_Z8mainHookv+0x48000001-0x804e9f44)@l
    lis %r4, 0x804F
    stw %r3, -0x60BC (%r4)

   # lis %r3, (_Z11disableHookv+0x48000001-0x804f054c)@ha
   # addi %r3, %r3, (_Z11disableHookv+0x48000001-0x804f054c)@l
   # lis %r4, 0x804F
   # stw %r3, 0x054C (%r4)
    b start
