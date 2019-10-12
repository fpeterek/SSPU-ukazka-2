//
// Created by Filip Peterek on 12/10/2019.
//

#ifndef SSPU_UKAZKA_2_PROJECTILE_FACTORY_HPP
#define SSPU_UKAZKA_2_PROJECTILE_FACTORY_HPP

#include <functional>

#include "projectile.hpp"

class ProjectileFactory {

public:
    typedef std::function<void(sf::Vector2f, Shooter, sf::Vector2f, sf::Color)> Spawner;

private:

    Spawner spawner;
    float scale;

public:

    ProjectileFactory(Spawner && spawnFunction, float scale);

    void setScale(float scale);
    void spawnProjectile(sf::Vector2f pos, Shooter shooter) const;

};

#endif //SSPU_UKAZKA_2_PROJECTILE_FACTORY_HPP
