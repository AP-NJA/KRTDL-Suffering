#ifndef ARRAY_H_
#define ARRAY_H_

#include "Common.h"

template <typename T, u32 entries>
struct Array
{
    T mData[entries];

    inline T & operator[](u32 index);
};

template <typename T, u32 entries>
struct MutableArray
{
    u32 mArrayCount;
    Array<T, entries> mArray;

    inline T & operator[](u32 index);
};

template <typename T, u32 entries>
inline T & Array<T, entries>::operator[](u32 index)
{
    return mData[index];
}

template <typename T, u32 entries>
inline T & MutableArray<T, entries>::operator[](u32 index)
{
    return mArray[index];
}

// To summarize, grab the array and then grab its data.

#endif
