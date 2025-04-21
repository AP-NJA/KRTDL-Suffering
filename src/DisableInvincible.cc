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
