#include "include/Ability.h"

// Boolean that checks if the method of gaining ability is anything but swallowing
u8 Ability::checkAbility()
{
    u8 result = FALSE;

    if ((mCurrentAbility > NORMAL) && (mCurrentAbility != SLEEP) && (mCurrentAbility < LANDIA))
    {
        result = TRUE;
    }

    return result;
}

// Boolean that checks if the method of gaining ability is by swallowing
u8 Ability::onSwallowGain()
{
    u8 result = FALSE;
    MutableInhaleArray * inhaleArray = &mInhaleData.mAbilityEntity;
    InhaledItemData * entityData = &inhaleArray->mArray[0];

    if ((inhaleArray->mArrayCount != 0) && (entityData->mAbilityOnInhale != SLEEP))
    {
        result = TRUE;
    }

    return result;
}

// Main function responsible for removing abilities
void Ability::removeAbility()
{
    MutableInhaleArray * inhaleArray = &mInhaleData.mAbilityEntity;
    InhaledItemData * itemData = &inhaleArray->mArray[0];

    // Disables mixing
    if (inhaleArray->mArrayCount >= 3)
    {
        inhaleArray->mArrayCount = 1;
    }

    // Logic that removes ability depending on method
    if (onSwallowGain() == TRUE)
    {
        itemData->mAbilityOnInhale = NORMAL;
    }
    else if (checkAbility() == TRUE)
    {
        mDiscardAbility = TRUE;
        mNextAbility = NORMAL;
        mUpdateState = TRUE;
    }

    return;
}

// Hook into address 804E9F44
void abilityHook(void)
{
    HeroLoader * heroLoaderData = HeroLoader::getProtagData(gMainPointer);

    for (u32 i = 0; i < heroLoaderData->mHeroData.mArrayCount; i++)
    {
        Hero * heroData = heroLoaderData->mHeroData.mArray[i];
        Ability * abilityData = Ability::getAbilityData(heroData);

        abilityData->removeAbility();
        abilityData->mUpdateState = FALSE; // To reset the variable for later uses

        u32 * exitData = (u32 *)getStructData(&heroData->mUnkPtr); // hook: 804E9F44
    }

    return;
}
