.global HOOK
HOOK:
    lis %r3, (_Z8mainHookv+0x48000001-0x8035dae4)@ha
    addi %r3, %r3, (_Z8mainHookv+0x48000001-0x8035dae4)@l
    lis %r4, 0x8036
    stw %r3, -0x251C (%r4)

    b start
