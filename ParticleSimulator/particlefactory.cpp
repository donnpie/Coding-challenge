#include "particlefactory.h"

ParticleFactory::ParticleFactory() : _particlesCreatedCount(0)
{
    qDebug() << "ParticleFactory::ParticleFactory() constructor called on " << this;
}

ParticleFactory::~ParticleFactory()
{
    qDebug() << "ParticleFactory::~ParticleFactory() destructor called on " << this;
}

Particle *ParticleFactory::newParticle()
{
    _particlesCreatedCount++;
    return new Particle;
}

Particle *ParticleFactory::newParticle(double mass, AbstractForceType *ft)
{
    qDebug() << "Particle *ParticleFactory::newParticle(double mass, AbstractForceType *ft) called on " << this;
    _particlesCreatedCount++;
    return new Particle(mass, 0, ft);
}



Particle *ParticleFactory::newParticle(double mass, double massToSizeRatio)
{
    _particlesCreatedCount++;
    return new Particle(mass, massToSizeRatio);
}

Particle *ParticleFactory::newParticle(double mass, double massToSizeRatio, AbstractForceType *ft, dp::Vector *position, dp::Vector *velocity, dp::Vector *acceleration, dp::Vector *netForce)
{
    _particlesCreatedCount++;
    return new Particle(mass, massToSizeRatio);
}
