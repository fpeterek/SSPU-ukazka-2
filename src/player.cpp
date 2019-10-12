//
// Created by Peterek, Filip on 16/09/2019.
//

#include "player.hpp"

const int64_t Player::maxHealth = 3;
const uint64_t Player::verticalVelocity = 6;

void Player::update() {
    weapon.tick();
    forceVector.x = 0;
    forceVector.y = 0;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f & pos, const float scale, Weapon weapon) :
        Aircraft(texture, pos, scale, weapon) {

    velocity = verticalVelocity;
    health = maxHealth;
    rotate(90);

}

void Player::moveUp() {
    forceVector.y = -1 * velocity;
}

void Player::moveDown() {
    forceVector.y = 1 * velocity;
}

bool Player::setForRemoval() {
    return false;
}

void Player::onCrash() {
    --health;
}

