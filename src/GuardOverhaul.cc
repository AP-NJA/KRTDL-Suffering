#include "Gameplay/Hero/Hero.h"

#define GUARD_INTERVAL 30
#define GUARD_RESET 60
#define GUARD_SUCCESS 120
#define GUARD_PENALTY 120

// Initialize guard overhaul data
GuardOverhaul::GuardOverhaul()
{
    mGuardFrames = 0;
    mResetFrames = 0;
    mCooldownFrames = 0;
    mSuccessfulBlock = FALSE;
}

// Reset guard overhaul data
void GuardOverhaul::resetGuardVariables()
{
    mGuardFrames = 0;
    mResetFrames = 0;
    mCooldownFrames = 0;
}

// Check if character is guarding
u8 GuardOverhaul::guardCheck(Guard * guardData)
{
    u8 result = FALSE;

    if (guardData->mEnableGuardState == TRUE)
    {
        result = TRUE;
    }

    return result;
}

// Check if guard resulted in successful block
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

// Handle character guard timer
void GuardOverhaul::guardTimer(Guard * guardData)
{
    u8 guardState = guardCheck(guardData);

    if ((guardState == FALSE) && (mCooldownFrames == 0))
    {
        if (mGuardFrames == 0)
        {
            return;
        }

        if (mResetFrames > GUARD_RESET)
        {
            resetGuardVariables();
            return;
        }

        mResetFrames++;
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

// Run if guard block was successful
void GuardOverhaul::onSuccess(hero::Invincible * invincibleData)
{
    mSuccessfulBlock = TRUE;
    invincibleData->enableIntangibility(GUARD_SUCCESS);
    return;
}

// Run if guard timer ran out before block
void GuardOverhaul::onMiss(Guard * guardData)
{
    if (mCooldownFrames > GUARD_PENALTY)
    {
        resetGuardVariables();
        return;
    }

    mCooldownFrames++;
    guardData->mEnableGuardState = FALSE;
    return;
}

// Integrate the guard overhaul
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
