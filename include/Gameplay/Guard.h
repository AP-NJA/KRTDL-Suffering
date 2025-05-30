#ifndef GUARD_H_
#define GUARD_H_

#include "Common/Common.h"
#include "Gameplay/Hero/Invincible.h"

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
    u32 mGuardFrames;
    u32 mResetFrames;
    u32 mCooldownFrames;
    u8 mSuccessfulBlock;

    GuardOverhaul();
    void resetGuardVariables();
    u8 guardCheck(Guard * guardData);
    u8 blockStateHandler(hero::Invincible * invincibleData);
    void guardTimer(Guard * guardData);
    void onSuccess(hero::Invincible * invincibleData);
    void onMiss(Guard * guardData);
    void runGuardOverhaul(Hero * heroData);
} GuardOverhaul;

extern GuardOverhaul overhaulTable[4];

#endif
