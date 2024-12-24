#ifndef HERO_H_
#define HERO_H_

#include "Ability.h"
#include "Component.h"
#include "Invincible.h"

typedef struct Hero
{
    u8 x0[0x67 - 0x0];
    u8 mDisplayHeroModel; // x67
    u8 x68[0x11C - 0x68];
    ExplicitScopedPointer<Ability> mAbilityData; // x11C
    ExplicitScopedPointer<Invincible> mInvincibleData; // x124
    u8 x12C[0x18C - 0x12C];
    ExplicitScopedPointer<u32> mUnkPtr; // x18C

    Ability * getAbilityData(); //
    Invincible * getInvincData(); // 804EDB1C
} Hero;

typedef MutableArray<Hero *, 4> MutableHeroArray;

typedef struct HeroLoader
{
    u8 x0[0x9C - 0x0];
    MutableHeroArray mMutableHeroArray; // x9C
    u8 xB0[0x16C - 0xB0];
    u8 mInvulnerableState;
} HeroLoader;

#endif
