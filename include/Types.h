#ifndef TYPES_H_
#define TYPES_H_

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;

template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;
};

typedef Vec3<f32> Vec3f;
typedef Vec3<s32> Vec3i;

#define TRUE 1
#define FALSE 0

#endif
