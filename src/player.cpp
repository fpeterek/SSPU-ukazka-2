//
// Created by Peterek, Filip on 16/09/2019.
//

#include "player.hpp"

const int64_t Player::maxHealth = 3;
const uint64_t Player::verticalVelocity = 3;

Projectile Player::shoot() {
    return Projectile(position(), scale());
}

void Player::update() {
    forceVector.x = 0;
    forceVector.y = 0;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) :
        Aircraft(texture, pos, scale) {

    velocity = verticalVelocity;
    health = maxHealth;
    rotate(90);

}

bool Player::onHit() {
    return Entity::onHit();
}

bool Player::onCrash() {
    return Entity::onCrash();
}

void Player::moveUp() {
    forceVector.y = -1 * velocity;
}

void Player::moveDown() {
    forceVector.y = 1 * velocity;
}

