#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "Hero.h"

typedef struct Component
{
public:
    static HeroLoader * loadProtagInfo(u32 * mainPointer);
} Component;

#endif
