#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Common/Vector.h"

#define PIGGYBACK_CHARGE 0x4AC

typedef struct ParticleSpawn
{
    Vec3f mPosition;
    Vec3f mScale;
    Vec3f mSkew;
} ParticleSpawn;

typedef struct Particle
{
    void spawnParticleEffect(u32 particleID, u32 format, ParticleSpawn * particleSpawn, Vec3f * offset);
} Particle;

typedef struct ParticleLoader
{
    u8 x0[0x8 - 0x0];
    Particle mStatusParticles;
} ParticleLoader;

inline void setVariables(ParticleSpawn & particleSpawn, Vec3f & pos, Vec3f & scale, Vec3f & skew)
{
    particleSpawn.mPosition = pos;
    particleSpawn.mScale = scale;
    particleSpawn.mSkew = skew;
}

#endif
