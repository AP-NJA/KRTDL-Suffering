#ifndef HP_H_
#define HP_H_

#include "Common/Common.h"

typedef struct HP
{
    volatile u32 mCurrentHP;
    MaxMin<u32> mLimits;
    u32 mCorpseHP;
    u32 mPreviousHP;
} HP;

#endif
