#include "Gameplay/Component.h"
#include <Common/Array.h>

// Savestate savestateData = { 0 };

GuardOverhaul overhaulTable[4] = { 0, 0, 0, 0 };

// Hook into 804E9F44
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

    HeroLoader * exitData = Component::loadProtagInfo(gMainPointer); // hook: 8035DAE4
    return;
}
