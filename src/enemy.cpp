//
// Created by Peterek, Filip on 16/09/2019.
//

#include "enemy.hpp"

const int64_t Enemy::maxHealth = 1;

Projectile Enemy::shoot() {
    return Projectile(position(), scale());
}

void Enemy::update() {

}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) :
        Aircraft(texture, pos, scale) {

    health = maxHealth;
    rotate(-90);

}

bool Enemy::onHit() {
    health = 0;
    return true;
}

bool Enemy::onCrash() {
    health = 0;
    return true;
}
