//
// Created by Peterek, Filip on 16/09/2019.
//

#include "enemy.hpp"
#include "random.hpp"

const int64_t Enemy::maxHealth = 1;

void Enemy::update() {
    weapon.shoot(position());
    weapon.tick();
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f & pos, const float scale, Weapon weapon) :
        Aircraft(texture, pos, scale, weapon) {

    forceVector.x = Random::randInt(-7, -4);
    health = maxHealth;
    rotate(-90);

}
