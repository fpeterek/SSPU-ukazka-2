//
// Created by fpeterek on 13.10.19.
//

#ifndef SSPU_UKAZKA_2_PARTICLE_CREATOR_HPP
#define SSPU_UKAZKA_2_PARTICLE_CREATOR_HPP

#include "particle.hpp"
#include "resource_manager.hpp"

class ParticleCreator {

    const ResourceManager & rm;

public:

    typedef std::function<void(const sf::Texture &, uint64_t, uint64_t, sf::Vector2f)> Spawner;

private:

    Spawner spawner;

public:

    ParticleCreator(Spawner && spawnFunction, const ResourceManager & resourceManager);

    void createExplosion(sf::Vector2f pos) const;

};

#endif //SSPU_UKAZKA_2_PARTICLE_CREATOR_HPP
