#ifndef GUARD_H_
#define GUARD_H_

#include "Common/Common.h"

struct Hero;

typedef struct Guard
{
    Hero * mHeroData;
    u8 mEnableGuardState;
    u8 mEnableGuardStateFlash;
    u8 x6[0x8 - 0x6];
    u32 mGuardFlashCycle;

    u8 guardCheck();
} Guard;

#endif
