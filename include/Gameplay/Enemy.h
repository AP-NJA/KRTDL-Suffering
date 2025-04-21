#ifndef ENEMY_H_
#define ENEMY_H_

#include "Array.h"

typedef struct Enemy
{

} Enemy;

typedef MutableArray<Enemy *, 32> MutableEnemyArray;

typedef struct EnemyLoader
{
    u8 x0[0x94 - 0x0];
    MutableEnemyArray mMutableEnemyArray;

public:
    static EnemyLoader * loadEnemyInfo(u32 * pointerData);
} EnemyLoader;

#endif
