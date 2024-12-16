#ifndef HEROLOADER_H_
#define HEROLOADER_H_

#include "Array.h"
#include "Hero.h"

extern u32 * gMainPointer;

typedef MutableArray<Hero *, 4> MutableHeroArray;

typedef struct HeroLoader
{
    u8 x0[0x9C - 0x0];
    MutableHeroArray mHeroData;
    u8 xB0[0x16C - 0xB0];
    u8 mInvulnerableState;

public:
    static HeroLoader * getProtagData(u32 * pointer);
} HeroLoader;

#endif
