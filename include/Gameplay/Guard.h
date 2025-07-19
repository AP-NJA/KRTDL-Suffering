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
    Guard * mGuardData;
    HP * mHPData;
    hero::Invincible * mInvincibleData;
    Particle * mParticleData;
    State * mStateData;

    u32 mGuardFrames;
    u32 mResetFrames;
    u32 mCooldownFrames;
    u8 mSuccessfulBlock;
    u8 mParticleEffectPlayed;

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
