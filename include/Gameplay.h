#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

#include "Hero.h"

extern u32 * gMainPointer;

typedef struct MutableHeroArray
{
    u32 mArrayCount;
    Hero * mArrays[4];
} MutableHeroArray;

typedef struct Gameplay
{
    u8 x0[0x9C - 0x0];
    MutableHeroArray mHeroData;
    u8 xB0[0x16C - 0xB0];
    u8 mInvulnerableState;

public:
    static Gameplay * getProtagData(u32 * pointer);
} Gameplay;

#endif
