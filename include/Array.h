#ifndef ARRAY_H_
#define ARRAY_H_

#include "Types.h"

template <typename T, u32 entries>
struct Array
{
    T mArray[entries];
};

template <typename T, u32 entries>
struct MutableArray
{
    u32 mArrayCount;
    T mArray[entries];
};

#endif
