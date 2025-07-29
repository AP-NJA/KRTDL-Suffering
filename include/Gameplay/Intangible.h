#ifndef INTANGIBLE_H_
#define INTANGIBLE_H_

#include "Common/Common.h"

typedef struct Intangible
{
    u32 mIntangibleFrames; // x0
    u32 mFlashCycle; // x4
    u8 mUsingIntangibleMove; // x8
    u8 mGrabbedCandy; // x9
} Intangible;

#endif
