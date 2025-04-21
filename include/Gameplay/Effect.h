#ifndef EFFECT_H_
#define EFFECT_H_

#include "Gameplay.h"

typedef struct Effect
{
    Hero * mHeroData;
    u32 * mUnk4;
    u32 * mGlobalObjectData;
    u8 xC[0x54 - 0xC];
    u8 mIsVulnerable; // x54
    // u8 mDisableIntangibleHitbox;

public:
    static Effect * getEffectData(Hero * heroData); // 804EDAF4
} Effect;

#endif
