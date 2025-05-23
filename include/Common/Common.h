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

typedef unsigned char BOOL;

#define TRUE 1
#define FALSE 0

extern u32 * gMainPointer;

template <typename T>
struct ScopedPointer
{
    T * mBuffer;
};

template <typename T>
struct ExplicitScopedPointer
{
    u32 * mUnk0;
    T * mBuffer;

    inline T * loadPointer();
};

template <typename T>
inline T * ExplicitScopedPointer<T>::loadPointer()
{
    return mBuffer;
}

template <typename T>
struct MaxMin
{
    T maximum;
    T minimum;
};

#endif
