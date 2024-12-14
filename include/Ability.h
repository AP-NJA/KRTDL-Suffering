#ifndef ABILITY_H_
#define ABILITY_H_

#include "Gameplay.h"
#include "Inhale.h"

#define NORMAL 0
#define SWORD 1
#define CUTTER 2
#define LEAF 3
#define WHIP 4
#define FIRE 5
#define NEEDLE 6
#define BEAM 7
#define SPARK 8
#define STONE 9
#define SLEEP 10
#define PARASOL 11
#define WATER 12
#define HIGH_JUMP 13
#define TORNADO 14
#define BOMB 15
#define SPEAR 16
#define HAMMER 17
#define ICE 18
#define WING 19
#define NINJA 20
#define FIGHTER 21
#define CRASH 22
#define MIKE 23
#define LANDIA 24
#define ULTRA_SWORD 25
#define MONSTER_FLAME 26
#define FLARE_BEAM 27
#define GRAND_HAMMER 28
#define SNOW_BOWL 29
#define MIKE_TWO 30
#define MIKE_FINALE 31
#define META_KNIGHT 32
#define KING_DEDEDE 33
#define BANDANA_DEE 34

typedef struct Ability
{
    Hero * mHeroData; // x0
    u8 x4[0x18 - 0x4];
    u32 mCurrentAbility; // x18
    u8 x1C[0x4C - 0x1C];
    u8 mDiscardAbility; // x4C
    u32 mNextAbility; // x50
    u8 mUpdateState; // x54, not sure what this variable does at the moment
    u8 x55[0x90 - 0x55];
    Inhale mInhaleData; // x90

    u8 hasUniqueGuard(); // 804D2CB4

    // Custom functions
    u8 checkAbility();
    u8 onSwallowGain();
    void removeAbility();
    void randomizeAbility();

public:
    static Ability * getAbilityData(Hero * heroData); // 804EDB0C
} Ability;
#endif
