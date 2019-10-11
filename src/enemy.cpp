//
// Created by Peterek, Filip on 16/09/2019.
//

#include "enemy.hpp"
#include "random.hpp"

const int64_t Enemy::maxHealth = 1;

Projectile Enemy::shoot() {
    return Projectile(position(), scale());
}

void Enemy::update() {

}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) :
        Aircraft(texture, pos, scale) {

    forceVector.x = Random::randInt(-7, -4);
    health = maxHealth;
    rotate(-90);

}
