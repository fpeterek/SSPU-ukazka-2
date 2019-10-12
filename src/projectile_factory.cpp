//
// Created by Filip Peterek on 12/10/2019.
//

#include <projectile_factory.hpp>

ProjectileFactory::ProjectileFactory(Spawner && spawnFunction, float scale) :
        spawner(spawnFunction), scale(scale) { }

void ProjectileFactory::setScale(const float s) {
    scale = s;
}

void ProjectileFactory::spawnProjectile(const sf::Vector2f pos, const Shooter shooter) const {
    sf::Vector2f forces(0, 0);
    forces.x = Projectile::velocity * (-1 + (2 * (shooter == Shooter::Player)));
    sf::Color fill(255, (shooter == Shooter::Player) * 255, 0);
    spawner(pos, shooter, forces, fill);
}

