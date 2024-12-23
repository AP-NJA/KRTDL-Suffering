#ifndef INVINCIBLE_H_
#define INVINCIBLE_H_

#include "Common.h"

struct Hero;

typedef struct Intangible
{
    u32 mIntangibleFrames; // x0
    u32 mFlashCycle; // x4
    u8 mUsingIntangibleMove; // x8, no guarantee but from what I saw in memory this could be true
    u8 mGrabbedCandy; // x9, somehow causes entities to not take knockback upon collision

    void updateFlashCycle(); // 8034F8F0
} Intangible;

typedef struct Invincible
{
    Hero * mHeroData; // x0
    Intangible mIntangibleData; // x4
    u8 mEnableIntangibleFlash; // x10
    u8 mMightyEffect; // x11
    u8 mCandyEffect; // x12
    u32 mCandyTimer; // x14
    u32 mRainbowTimer; // x18
    u32 mRainbowCycle; // x1C
    u8 mRGBRedValue; // x20
    u8 mRGBGreenValue; // x21
    u8 mRGBBlueValue; // x22

    // Custom functions
    void disableIntangibility();
} Invincible;

#endif
