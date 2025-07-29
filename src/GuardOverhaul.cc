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
    mParticleEffectPlayed = FALSE;
}

// Reset guard overhaul data
void GuardOverhaul::resetGuardVariables()
{
    mGuardFrames = 0;
    mResetFrames = 0;
    mCooldownFrames = 0;
    mParticleEffectPlayed = FALSE;
}

// Set variables for overhauled guard particle effects
void GuardOverhaul::setGuardParticleEffect()
{
    ParticleSpawn particleSpawn;

    Vec3f offset = { 0.0f, 0.0f, 0.5f };
    Vec3f position = { -1.0f, 0.0f, 0.0f };
    Vec3f scale = { 0.0f, 1.0f, 0.0f };
    Vec3f skew = { 0.0f, 0.0f, 1.0f };

    setVariables(particleSpawn, position, scale, skew);
    mParticleEffectPlayed = TRUE;
    mParticleData->spawnParticleEffect(PIGGYBACK_CHARGE, 0, &particleSpawn, &offset);
}

// Check if guarding
inline u8 GuardOverhaul::guardCheck()
{
    return mGuardData->mEnableGuardState;
}

// Check if guard resulted in successful block
u8 GuardOverhaul::blockCheck()
{
    if (mInvincibleData->mIntangibleData.mIntangibleFrames == 0)
    {
        mSuccessfulBlock = FALSE;
    }

    return mSuccessfulBlock;
}

// Run if guard block was successful
void GuardOverhaul::onSuccess()
{
    mSuccessfulBlock = TRUE;

    if (mParticleEffectPlayed == FALSE)
    {
        setGuardParticleEffect();
    }

    if (mHPData->mCurrentHP < mHPData->mPreviousHP)
    {
        mHPData->mCurrentHP++;
    }

    mInvincibleData->enableIntangibility(GUARD_SUCCESS);
    return;
}

// Run if guard timer ran out before block
void GuardOverhaul::onMiss()
{
    if (mCooldownFrames > GUARD_PENALTY)
    {
        resetGuardVariables();
        return;
    }

    mCooldownFrames++;
    mGuardData->mEnableGuardState = FALSE;
    return;
}

// Restore the guard timer to zero if not under cooldown
void GuardOverhaul::restoreGuard()
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

// Handle guard timer
void GuardOverhaul::guardTimer()
{
    u8 guardState = guardCheck();

    switch (guardState)
    {
        case FALSE:
        {
            if (mCooldownFrames == 0)
            {
                restoreGuard();
                return;
            }

            break;
        }
        case TRUE:
        {
            if ((mSuccessfulBlock == FALSE) && (mStateData->mIsVulnerable == FALSE))
            {
                onSuccess();
                return;
            }

            break;
        }
    }

    if (mGuardFrames > GUARD_INTERVAL)
    {
        onMiss();
        return;
    }

    mGuardFrames++;
    return;
}

// Start the guard overhaul
void GuardOverhaul::runGuardOverhaul(Hero * heroData)
{
    mGuardData = heroData->mGuardData.loadPointer();
    mHPData = heroData->mHPData.loadPointer();
    mInvincibleData = heroData->mInvincibleData.loadPointer();
    mParticleData = &heroData->mParticleLoader.loadPointer()->mStatusParticles;
    mStateData = heroData->mStateData.loadPointer();

    guardTimer();

    if (blockCheck() == TRUE)
    {
        return;
    }

    mInvincibleData->disableIntangibility();
    return;
}
