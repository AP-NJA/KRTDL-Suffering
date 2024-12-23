#include "include/Hero.h"

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
    HeroLoader * heroLoaderData = Component::loadProtagInfo(gMainPointer);

    for (u32 i = 0; i < heroLoaderData->mMutableHeroArray.mArrayCount; i++)
    {
        Hero * heroData = heroLoaderData->mMutableHeroArray.mArray.mData[i];
        Invincible * invincibleData = heroData->getInvincData();

        invincibleData->disableIntangibility();

        invincibleData->mIntangibleData.updateFlashCycle(); // hook: 804F054C
    }

    return;
}
