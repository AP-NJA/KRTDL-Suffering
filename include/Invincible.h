#ifndef INVINCIBLE_H_
#define INVINCIBLE_H_

#include "Gameplay.h"

typedef struct Intangible
{
    u32 mIntangibleFrames;
    u32 mFlashCycle;
    u8 mUsingIntangibleMove; // no guarantee but from what I saw in memory this could be true
    u8 mGrabbedCandy; // somehow causes entities to not take knockback upon collision

    void updateFlashCycle(); // 8034F8F0
} Intangible;

typedef struct Invincible
{
    Hero * mHeroData;
    Intangible mIntangibleData;
    u8 mEnableIntangibleFlash;
    u8 mMightyEffect;
    u8 mCandyEffect;
    u32 mCandyTimer;
    u32 mRainbowTimer;
    u32 mRainbowCycle;
    u8 mRGBRedValue;
    u8 mRGBGreenValue;
    u8 mRGBBlueValue;

    // Custom functions
    void disableIntangibility();

public:
    static Invincible * getInvincData(Hero * heroData); // 804EDB1C
} Invincible;

#endif
