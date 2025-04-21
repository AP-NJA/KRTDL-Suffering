#ifndef BOSS_INVINC_H_
#define BOSS_INVINC_H_

#include "Gameplay/Intangible.h"

struct Boss;

namespace boss
{
    typedef struct Invincible
    {
        Boss * mBossData;
        Intangible mIntangibleData;
    } Invincible;
};

typedef struct CooldownPeriod
{
    Boss * mBossData;
    u32 mCooldownFrames;
} CooldownPeriod;

#endif
