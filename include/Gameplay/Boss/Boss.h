#ifndef BOSS_H_
#define BOSS_H_

#include "Common/Array.h"
#include "Gameplay/Boss/Invincible.h"
#include "Gameplay/HP.h"

typedef struct Boss
{
    u8 x0[0x204 - 0x0];
    ExplicitScopedPointer<boss::Invincible> mInvincibleData; // x204
    ExplicitScopedPointer<CooldownPeriod> mCooldownPeriodData; // x20C
    u8 x214[0x21C - 0x214];
    ExplicitScopedPointer<HP> mHPData;

    boss::Invincible * getInvincData(); // 8025187C
    CooldownPeriod * getCooldownPeriodData(); // 8025188C
    HP * getHPData(); // 80251894
} Boss;

typedef MutableArray<Boss *, 4> MutableBossArray;

#endif
