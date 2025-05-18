#include "Gameplay/Hero/Hero.h"
#include <Gameplay/Guard.h>
#include <Gameplay/Hero/Invincible.h>

#define GUARD_INTERVAL 30
#define GUARD_SUCCESS 120
#define GUARD_PENALTY 120

// Check if currently guarding
u8 GuardOverhaul::guardCheck(Guard * guardData)
{
    u8 result = FALSE;

    if (guardData->mEnableGuardState == TRUE)
    {
        result = TRUE;
    }

    return result;
}

// Check if player has blocked during guard
u8 GuardOverhaul::blockStateHandler(hero::Invincible * invincibleData)
{
    u8 result = FALSE;

    if (invincibleData->mIntangibleData.mIntangibleFrames == 0)
    {
        mSuccessfulBlock = FALSE;
    }

    if (mSuccessfulBlock == TRUE)
    {
        result = TRUE;
    }

    return result;
}

// Handle guard interval
void GuardOverhaul::guardTimer(Guard * guardData)
{
    u8 guardState = guardCheck(guardData);

    if ((guardState == FALSE) && (mCooldownFrames == 0))
    {
        mGuardFrames = 0;
        return;
    }

    if (mGuardFrames > GUARD_INTERVAL)
    {
        onMiss(guardData);
        return;
    }

    mGuardFrames++;

    return;
}

// Handle guard success effect
void GuardOverhaul::onSuccess(hero::Invincible * invincibleData)
{
    mSuccessfulBlock = TRUE;
    invincibleData->enableIntangibility(GUARD_SUCCESS);
}

// Handle guard miss punishment
void GuardOverhaul::onMiss(Guard * guardData)
{
    if (mCooldownFrames > GUARD_PENALTY)
    {
        mCooldownFrames = 0;
        return;
    }

    guardData->mEnableGuardState = FALSE;
    mCooldownFrames++;

    return;
}

// Main function responsible for running the guard overhaul
void GuardOverhaul::runGuardOverhaul(Hero * heroData)
{
    Guard * guardData = heroData->mGuardData.loadPointer();
    hero::Invincible * invincibleData = heroData->mInvincibleData.loadPointer();
    State * stateData = heroData->mStateData.loadPointer();

    guardTimer(guardData);

    u8 blockState = blockStateHandler(invincibleData);
    u8 guardState = guardCheck(guardData);

    if (blockState == TRUE)
    {
        return;
    }

    if ((guardState == TRUE) && (stateData->mIsVulnerable == FALSE))
    {
        onSuccess(invincibleData);
        return;
    }

    invincibleData->disableIntangibility();
    return;
}
