#ifndef VECTOR_H_
#define VECTOR_H_

#include "Common.h"

template <typename T>
struct Vec2
{
    T x;
    T y;
};

typedef Vec2<f32> Vec2f;
typedef Vec2<s32> Vec2i;

template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;
};

typedef Vec3<f32> Vec3f;
typedef Vec3<s32> Vec3i;

#endif
