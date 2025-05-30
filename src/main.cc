#include "Gameplay/Component.h"

GuardOverhaul overhaulTable[4] = {};

// Hook into 8035DAE4
void mainHook(void)
{
    HeroLoader * heroLoader = Component::loadProtagInfo(gMainPointer);
    u32 playerCount = heroLoader->mMutableHeroArray.mArrayCount;

    for (u32 i = 0; i < playerCount; i++)
    {
        Hero * heroData = heroLoader->mMutableHeroArray[i];
        Ability * abilityData = heroData->mAbilityData.loadPointer();

        abilityData->removeAbility();
        overhaulTable[i].runGuardOverhaul(heroData);
    }

    HeroLoader * exitData = Component::loadProtagInfo(gMainPointer);
    return;
}
