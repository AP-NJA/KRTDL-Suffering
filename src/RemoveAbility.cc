#include "Gameplay/Hero/Hero.h"

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
    InhaledItemData * entityData = &inhaleArray->mArray.mData[0];

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
    InhaledItemData * itemData = &inhaleArray->mArray.mData[0];

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
    }

    return;
}
