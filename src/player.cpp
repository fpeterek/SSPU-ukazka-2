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

void Player::moveUp(uint64_t upperBound) {

    move(sf::Vector2f(0, -velocity));
    std::cout << globalBounds().top << std::endl;
    if (globalBounds().top < upperBound) {
        auto newPos = position();
        newPos.y = (globalBounds().top - upperBound) * -1;
        setPosition(sf::Vector2f(newPos));
    }

}
