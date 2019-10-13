//
// Created by fpeterek on 13.10.19.
//

#include "particle_creator.hpp"

ParticleCreator::ParticleCreator(ParticleCreator::Spawner && spawnFunction, const ResourceManager & resourceManager)
    : spawner(spawnFunction), rm(resourceManager) { }

void ParticleCreator::createExplosion(sf::Vector2f pos) const {
    spawner(rm.getTexture("explosion"), 12, 5, pos);
}
