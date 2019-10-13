//
// Created by Filip Peterek on 11/10/2019.
//

#include "enemy_factory.hpp"

EnemyFactory::EnemyFactory(const sf::Texture & texture,
        const sf::Vector2u dim,
        const float scale,
        WeaponFactory & factory,
        const ParticleCreator & particleCreator) : texture(texture), dim(dim), scale(scale), factory(factory),
        yBound(dim.y - (texture.getSize().y * scale)), pc(particleCreator) {

}

Enemy EnemyFactory::randomEnemy() {
    const uint64_t x = dim.x;
    const uint64_t y = Random::randUInt(0, yBound);
    return Enemy(texture, sf::Vector2f(x, y), scale, factory.createEnemyWeapon(), pc);
}
