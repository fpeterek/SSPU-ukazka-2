//
// Created by Peterek, Filip on 16/09/2019.
//

#include "aircraft.hpp"

Aircraft::Aircraft(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) {
    sprite.setPosition(pos);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(scale, scale);

    wingBox.setScale(scale, scale);
    wingBox.setSize(sf::Vector2f(10, texture.getSize().y - 3*scale));
    wingBox.setOrigin(6*scale, (texture.getSize().y - 3*scale) / 2);
    wingBox.setPosition(pos.x + sprite.getTexture()->getSize().x / 2 * scale, pos.y);
    wingBox.setFillColor(sf::Color::Cyan);

    fuselageBox.setScale(scale, scale);
    fuselageBox.setSize(sf::Vector2f(texture.getSize().x, 10));
    fuselageBox.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    fuselageBox.setPosition(pos.x, pos.y + texture.getSize().y / 2 * scale - 3.5*scale);

    fuselageBox.setFillColor(sf::Color::Magenta);



}

void Aircraft::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(sprite);
    //target.draw(wingBox);
    //target.draw(fuselageBox);
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
    wingBox.move(diff);
    fuselageBox.move(diff);
}

void Aircraft::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
    wingBox.setPosition(pos);
    fuselageBox.setPosition(pos);
}

sf::Vector2f Aircraft::forces() const {
    return forceVector;
}

int64_t Aircraft::hp() {
    return health;
}

void Aircraft::onHit() {
    --health;
}

void Aircraft::onCrash() {
    health = 0;
}

bool Aircraft::setForRemoval() {
    return health <= 0;
}

bool Aircraft::hitboxHitDetection(const Entity & e) {
    return wingBox.getGlobalBounds().intersects(e.globalBounds()) or
            fuselageBox.getGlobalBounds().intersects(e.globalBounds());
}

bool Aircraft::hitboxHitDetection(const Aircraft & e) {
    return wingBox.getGlobalBounds().intersects(e.wingBox.getGlobalBounds()) or
           wingBox.getGlobalBounds().intersects(e.fuselageBox.getGlobalBounds()) or
           fuselageBox.getGlobalBounds().intersects(e.wingBox.getGlobalBounds()) or
            fuselageBox.getGlobalBounds().intersects(e.fuselageBox.getGlobalBounds());
}
