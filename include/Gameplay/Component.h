#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Gameplay/Boss/Boss.h"
#include "Gameplay/Hero/Hero.h"

typedef struct HeroLoader
{
    u8 x0[0x9C - 0x0];
    MutableHeroArray mMutableHeroArray; // x9C
    u8 xB0[0x16C - 0xB0];
    u8 mInvulnerableState;
} HeroLoader;

typedef struct BossLoader
{
    u8 x0[0xE4 - 0x0];
    MutableBossArray mMutableBossArray;
} BossLoader;

typedef struct Component
{
public:
    static HeroLoader * loadProtagInfo(u32 * mainPointer); // 8023F2F4
    static BossLoader * loadBossInfo(u32 * mainPointer); // 8023F364
} Component;

#endif
