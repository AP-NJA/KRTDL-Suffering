#ifndef ARRAY_H_
#define ARRAY_H_

#include "Common.h"

template <typename T, u32 entries>
struct Array
{
    T mData[entries];
};

template <typename T, u32 entries>
struct MutableArray
{
    u32 mArrayCount;
    Array<T, entries> mArray;
};

// To summarize, grab the array and then grab its data.

#endif
