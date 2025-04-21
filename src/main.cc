#include "Gameplay/Component.h"
#include <Common/Common.h>

void mainHook(void)
{
    HeroLoader * heroLoader = Component::loadProtagInfo(gMainPointer);

    for (u32 i = 0; i < heroLoader->mMutableHeroArray.mArrayCount; i++)
    {
        Hero * hero = heroLoader->mMutableHeroArray[i];

        Ability * abilityData = hero->mAbilityData.mBuffer;
        hero::Invincible * invincibleData = hero->mInvincibleData.mBuffer;

        abilityData->removeAbility();
        invincibleData->disableIntangibility();

        u32 * exitData = hero->mUnkPtr.loadScopedData();
    }

    return;
}
