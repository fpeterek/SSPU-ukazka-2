//
// Created by Peterek, Filip on 16/09/2019.
//

#include "projectile.hpp"

const sf::Color Projectile::fill = sf::Color(0, 255, 255);
const sf::Color Projectile::outline = sf::Color(0, 0, 0);
const uint64_t Projectile::radius = 5;

const sf::Vector2f & Projectile::position() const {
    return bullet.getPosition();
}

void Projectile::update() {

}

sf::FloatRect Projectile::globalBounds() const {
    return bullet.getGlobalBounds();
}

Projectile::Projectile(const sf::Vector2f & position, const float scale) {
    bullet.setRadius(radius);
    bullet.setFillColor(fill);
    bullet.setOutlineColor(outline);
    bullet.setOutlineThickness(1);
    bullet.setScale(scale, scale);
    bullet.setOrigin(bullet.getGlobalBounds().width / 2, bullet.getGlobalBounds().height / 2);
    bullet.setPosition(position);
}

void Projectile::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(bullet);
}

float Projectile::scale() const {
    return bullet.getScale().x;
}

uint64_t Projectile::damage() {
    return 1;
}
