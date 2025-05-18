#ifndef STATE_H_
#define STATE_H_

#include "Common/Common.h"

struct Hero;

typedef struct State
{
    Hero * mHeroData; // x0
    u8 x4[0x8 - 0x4];
    u32 * mGlobalObject; // x8
    u8 xC[0x54 - 0xC];
    u8 mIsVulnerable; // x54
    // u8 mDisableIntangibleHitbox;
} State;

#endif
