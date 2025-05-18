#include "Gameplay/Hero/Hero.h"

// Main function responsible for disabling intangibility
void hero::Invincible::disableIntangibility()
{
    mIntangibleData.mIntangibleFrames = 0;
    if (mIntangibleData.mUsingIntangibleMove == TRUE)
    {
        mIntangibleData.mUsingIntangibleMove = FALSE;
    }

    return;
}

// Function responsible for enabling intangibility
void hero::Invincible::enableIntangibility(u32 frames)
{
    State * stateData = mHeroData->mStateData.loadPointer();

    mIntangibleData.mIntangibleFrames = frames;
    stateData->mIsVulnerable = FALSE;
    mEnableIntangibleFlash = TRUE;

    return;
}
