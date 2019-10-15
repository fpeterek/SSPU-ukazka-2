//
// Created by Peterek, Filip on 16/09/2019.
//

#include "player.hpp"

const int64_t Player::maxHealth = 30;
const uint64_t Player::verticalVelocity = 6;

void Player::update() {
    weapon.tick();
    forceVector.x = 0;
    forceVector.y = 0;
}

Player::Player(Weapon weapon, const ParticleCreator & pc, const float scale) :
        Aircraft(sf::Texture(), sf::Vector2f(), scale, weapon, pc),
        healthBar(maxHealth, scale) {

}

void Player::moveUp() {
    forceVector.y = -1 * velocity;
}

void Player::moveDown() {
    forceVector.y = 1 * velocity;
}

bool Player::setForRemoval() const {
    return false;
}

void Player::onCrash() {
    onHit();
}

uint64_t Player::score() const {
    return _score;
}

void Player::incScore() {
    ++_score;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    if (health > 0) {
        Aircraft::draw(target, states);
        target.draw(healthBar);
    }
}

void Player::move(sf::Vector2f diff) {
    Aircraft::move(diff);
    healthBar.updatePos(globalBounds());
}

void Player::setPosition(sf::Vector2f pos) {
    Aircraft::setPosition(pos);
    healthBar.updatePos(globalBounds());
}

void Player::onHit() {
    Aircraft::onHit();
    healthBar.updateHealth(globalBounds(), health);
}

void Player::init(const sf::Texture & texture, const sf::Vector2f & pos) {

    setPosition(pos);
    setTexture(texture);

    velocity = verticalVelocity;
    health = maxHealth;
    rotate(90);

    healthBar.updateHealth(globalBounds(), health);
    healthBar.updatePos(globalBounds());

}


