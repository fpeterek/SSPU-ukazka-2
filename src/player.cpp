//
// Created by Peterek, Filip on 16/09/2019.
//

#include "player.hpp"

Projectile Player::shoot() {
    return Projectile(position(), scale());
}

void Player::update() {

}

Player::Player(const sf::Texture & texture, const sf::Vector2f & pos, const float scale) :
        Aircraft(texture, pos, scale) {

    rotate(90);

}
