//
// Created by Peterek, Filip on 16/09/2019.
//

#include "projectile.hpp"

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

Projectile::Projectile(const sf::Vector2f & position, const float scale,
        const Shooter shooter, sf::Vector2f forces, sf::Color fill) :
        sh(shooter), forceVector(forces), fill(fill) {

    bullet.setRadius(radius);
    bullet.setFillColor(fill);
    bullet.setOutlineColor(outline);
    bullet.setOutlineThickness(1);
    bullet.setScale(scale, scale);
    bullet.setOrigin(radius / 2, radius / 2);
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

void Projectile::onHit() {
    keepAlive = false;
}

void Projectile::onCrash() {
    keepAlive = false;
}

bool Projectile::setForRemoval() const {
    return not keepAlive;
}

void Projectile::setPosition(sf::Vector2f newPos) {
    bullet.setPosition(newPos);
}

void Projectile::move(sf::Vector2f diff) {
    bullet.move(diff);
}

sf::Vector2f Projectile::forces() const {
    return forceVector;
}

Shooter Projectile::shooter() {
    return sh;
}
