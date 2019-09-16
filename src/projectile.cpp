//
// Created by Peterek, Filip on 16/09/2019.
//

#include "projectile.hpp"

sf::Color Projectile::fill = sf::Color(0, 255, 255);
sf::Color Projectile::outline = sf::Color(0, 0, 0);

const sf::Vector2f & Projectile::position() const {
    return bullet.getPosition();
}

void Projectile::update() {

}

sf::FloatRect Projectile::globalBounds() const {
    return bullet.getGlobalBounds();
}

Projectile::Projectile(const sf::Vector2f & position, const float scale) {

}
