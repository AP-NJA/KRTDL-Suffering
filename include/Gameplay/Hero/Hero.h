#ifndef HERO_H_
#define HERO_H_

#include "Gameplay/Guard.h"
#include "Gameplay/HP.h"
#include "Gameplay/Hero/Ability.h"
#include "Gameplay/Hero/Invincible.h"
#include "Gameplay/Input.h"
#include "Gameplay/Movement.h"
#include "Gameplay/Particle.h"
#include "Gameplay/State.h"
#include <Common/Common.h>

typedef struct Hero
{
    u8 x0[0x67 - 0x0];
    u8 mDisplayHeroModel; // x67
    u8 x68[0xA4 - 0x68];
    ExplicitScopedPointer<Movement> mMovementData; // xA4
    u8 xAC[0xB4 - 0xAC];
    ExplicitScopedPointer<ParticleLoader> mParticleLoader; // xB4;
    ExplicitScopedPointer<u32> mUnkPtr; // xBC
    u8 xC4[0xDC - 0xC4];
    ExplicitScopedPointer<Input> mInputData; // xDC
    u8 xE4[0xEC - 0xE4];
    ExplicitScopedPointer<State> mStateData; // xEC
    u8 xF4[0x11C - 0xF4];
    ExplicitScopedPointer<Ability> mAbilityData; // x11C
    ExplicitScopedPointer<hero::Invincible> mInvincibleData; // x124
    u8 x12C[0x134 - 0x12C];
    ExplicitScopedPointer<HP> mHPData; // x134
    u8 x13C[0x174 - 0x13C];
    ExplicitScopedPointer<Guard> mGuardData; // x174
    u8 x17C[0x18C - 0x17C];
    ExplicitScopedPointer<u32> mUnkPtr2; // x18C
} Hero;

typedef MutableArray<Hero *, 4> MutableHeroArray;

#endif
