#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "Common/Vector.h"

typedef struct Position
{
    Vec3f mCurrentPosition;
    Vec3f mPreviousPosition;
} Position;

typedef struct Movement
{
    Position * mPositionData;
    Vec3f mVelocity;
    f32 mMovementFactor;
} Movement;

#endif
