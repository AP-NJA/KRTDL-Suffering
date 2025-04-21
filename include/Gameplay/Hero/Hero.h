#ifndef HERO_H_
#define HERO_H_

#include "Gameplay/Guard.h"
#include "Gameplay/HP.h"
#include "Gameplay/Hero/Ability.h"
#include "Gameplay/Hero/Invincible.h"
#include "Gameplay/Input.h"
#include "Gameplay/Movement.h"

typedef struct Hero
{
    u8 x0[0x67 - 0x0];
    u8 mDisplayHeroModel; // x67
    u8 x68[0xA4 - 0x68];
    ExplicitScopedPointer<Movement> mMovementData; // xA4
    u8 xAC[0xDC - 0xAC];
    ExplicitScopedPointer<Input> mInputData; // xDC
    u8 xE4[0x11C - 0xE4];
    ExplicitScopedPointer<Ability> mAbilityData; // x11C
    ExplicitScopedPointer<hero::Invincible> mInvincibleData; // x124
    u8 x12C[0x134 - 0x12C];
    ExplicitScopedPointer<HP> mHPData; // x134
    u8 x13C[0x18C - 0x13C];
    ExplicitScopedPointer<u32> mUnkPtr; // x18C

    Movement * getVelocityData(); // 804EDAA4
    Input * getInputData(); // 804EDAE4
    Ability * getAbilityData(); // 804EDB0C
    hero::Invincible * getInvincData(); // 804EDB1C
    HP * getHPData(); // 804EDB24
} Hero;

typedef MutableArray<Hero *, 4> MutableHeroArray;

#endif
