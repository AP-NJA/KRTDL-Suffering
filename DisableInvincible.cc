#include "include/Invincible.h"

// Main function responsible for disabling intangibility
void Invincible::disableIntangibility()
{
    mIntangibleData.mIntangibleFrames = 0;
    if (mIntangibleData.mUsingIntangibleMove == TRUE)
    {
        mIntangibleData.mUsingIntangibleMove = FALSE;
    }

    return;
}

// Hook into address 804F054C
void disableHook(void)
{
    Gameplay * gameplay = Gameplay::getProtagData(gMainPointer);

    for (u32 i = 0; i < gameplay->mHeroData.mArrayCount; i++)
    {
        Hero * heroData = gameplay->mHeroData.mArrays[i];
        Invincible * invincibleData = Invincible::getInvincData(heroData);

        invincibleData->disableIntangibility();

        invincibleData->mIntangibleData.updateFlashCycle(); // hook: 804F054C
    }

    return;
}
