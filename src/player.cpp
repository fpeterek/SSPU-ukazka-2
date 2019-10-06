//
// Created by Peterek, Filip on 16/09/2019.
//

#include "player.hpp"

const int64_t Player::maxHealth = 3;

Projectile Player::shoot() {
    return Projectile(position(), scale());
}

void Player::update() {

}

Player::Player(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) :
        Aircraft(texture, pos, scale) {
    health = maxHealth;
    rotate(90);

}

bool Player::onHit() {
    return Entity::onHit();
}

bool Player::onCrash() {
    return Entity::onCrash();
}
