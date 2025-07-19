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
    Vec3f position = { -1.0f, 0.0f, 0.0f };
    Vec3f scale = { 0.0f, 1.0f, 0.0f };
    Vec3f skew = { 0.0f, 0.0f, 1.0f };
    setVariables(particleSpawn, position, scale, skew);

    Vec3f offset = { 0.0f, 0.0f, 0.5f };

    mParticleEffectPlayed = TRUE;
    mParticleData->spawnParticleEffect(PIGGYBACK_CHARGE, 0, &particleSpawn, &offset);
}

// Check if guarding
u8 GuardOverhaul::guardCheck()
{
    u8 result = FALSE;

    if (mGuardData->mEnableGuardState == TRUE)
    {
        result = TRUE;
    }

    return result;
}

// Check if guard resulted in successful block
u8 GuardOverhaul::blockStateHandler()
{
    u8 result = FALSE;

    if (mInvincibleData->mIntangibleData.mIntangibleFrames == 0)
    {
        mSuccessfulBlock = FALSE;
    }

    if (mSuccessfulBlock == TRUE)
    {
        result = TRUE;
    }

    return result;
}

// Handle guard timer
void GuardOverhaul::guardTimer()
{
    u8 guardState = guardCheck();

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
        onMiss();
        return;
    }

    mGuardFrames++;
    return;
}

// Run if guard block was successful
void GuardOverhaul::onSuccess()
{
    mSuccessfulBlock = TRUE;

    if (mParticleEffectPlayed == FALSE)
    {
        setGuardParticleEffect();
        mParticleEffectPlayed = TRUE;
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

void GuardOverhaul::runGuardOverhaul(Hero * heroData)
{
    mGuardData = heroData->mGuardData.loadPointer();
    mHPData = heroData->mHPData.loadPointer();
    mInvincibleData = heroData->mInvincibleData.loadPointer();
    mParticleData = &heroData->mParticleLoader.loadPointer()->mStatusParticles;
    State * stateData = heroData->mStateData.loadPointer();

    guardTimer();

    u8 blockState = blockStateHandler();
    u8 guardState = guardCheck();

    if (blockState == TRUE)
    {
        return;
    }

    if ((guardState == TRUE) && (stateData->mIsVulnerable == FALSE))
    {
        onSuccess();
        return;
    }

    mInvincibleData->disableIntangibility();
    return;
}
