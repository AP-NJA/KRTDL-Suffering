#ifndef INHALE_H_
#define INHALE_H_

#include "Common/Array.h"

typedef struct InhaledItemData
{
    s32 mAbilityOnInhale;

    void safeGuard();
} InhaledItemData;

typedef MutableArray<InhaledItemData, 10> MutableInhaleArray;

typedef struct Inhale
{
    u8 x0[0x18 - 0x0];
    u32 mInhaleCount; // x18
    u8 x1C[0x838 - 0x1C];
    MutableInhaleArray mSuperAbilityEntity; // x838
    MutableInhaleArray mAbilityStar; // x864
    MutableInhaleArray mPlayer; // x890
    MutableInhaleArray mAbilityEntity; // x8BC
    u8 x8E8[0x940 - 0x8E8];
    u8 mActionSwallow; // x940
    //

    InhaledItemData * getInstance(MutableInhaleArray & inhaleArray, u32 i)
    {
        return &inhaleArray.mArray[i];
    }
} Inhale;

#endif
