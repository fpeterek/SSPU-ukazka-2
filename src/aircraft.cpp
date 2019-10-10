//
// Created by Peterek, Filip on 16/09/2019.
//

#include "aircraft.hpp"

Aircraft::Aircraft(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) {
    sprite.setPosition(pos);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(scale, scale);
}

void Aircraft::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(sprite);
}

sf::FloatRect Aircraft::globalBounds() const {
    return sprite.getGlobalBounds();
}

const sf::Vector2f & Aircraft::position() const {
    return sprite.getPosition();
}

float Aircraft::scale() const {
    return sprite.getScale().x;
}

void Aircraft::rotate(const float val) {
    sprite.setRotation(val);
}

void Aircraft::move(const sf::Vector2f diff) {
    sprite.move(diff);
}

void Aircraft::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::Vector2f Aircraft::forces() const {
    return forceVector;
}
