#ifndef INVINCIBLE_H_
#define INVINCIBLE_H_

#include "Gameplay/Intangible.h"

struct Hero;

namespace hero
{
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
        void enableIntangibility(u32 frames);
        void invincibleTweaks();
    } Invincible;
};
#endif
