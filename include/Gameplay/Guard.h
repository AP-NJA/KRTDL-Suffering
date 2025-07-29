#ifndef GUARD_H_
#define GUARD_H_

#include "Common/Common.h"
#include "Gameplay/HP.h"
#include "Gameplay/Hero/Invincible.h"
#include "Gameplay/Particle.h"
#include <Gameplay/State.h>

struct Hero;

typedef struct Guard
{
    Hero * mHeroData; // x0
    u8 mEnableGuardState; // x4
    u8 mEnableGuardStateFlash; // x5
    u8 x6[0x8 - 0x6];
    u32 mGuardFlashCycle; // x8
} Guard;

typedef struct GuardOverhaul
{
    Guard * mGuardData; // x0
    HP * mHPData; // x4
    hero::Invincible * mInvincibleData; // x8
    Particle * mParticleData; // xC
    State * mStateData; // x10

    u32 mGuardFrames; // x14
    u32 mResetFrames; // x18
    u32 mCooldownFrames; // x1C
    u8 mSuccessfulBlock; // x20
    u8 mParticleEffectPlayed; // x21

    GuardOverhaul();
    void resetGuardVariables();
    void setGuardParticleEffect();
    inline u8 guardCheck();
    u8 blockCheck();
    void onSuccess();
    void onMiss();
    void restoreGuard();
    void guardTimer();
    void runGuardOverhaul(Hero * heroData);
} GuardOverhaul;

#endif
