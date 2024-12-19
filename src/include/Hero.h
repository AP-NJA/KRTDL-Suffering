#ifndef HERO_H_
#define HERO_H_

#include "Array.h"

typedef struct Hero
{
    u8 x0[0x67 - 0x0];
    u8 mDisplayHeroModel; // x67
    u8 x68[0x18C - 0x68];
    ExplicitScopedPointer<u32> mUnkPtr; // x18C
} Hero;

typedef MutableArray<Hero *, 4> MutableHeroArray;

typedef struct HeroLoader
{
    u8 x0[0x9C - 0x0];
    MutableHeroArray mMutableHeroArray;
    u8 xB0[0x16C - 0xB0];
    u8 mInvulnerableState;
} HeroLoader;

#endif
