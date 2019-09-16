//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PROJECTILE_HPP
#define SSPU_UKAZKA_2_PROJECTILE_HPP


#include "entity.hpp"

class Projectile : public Entity {

    static sf::Color fill;
    static sf::Color outline;
    sf::CircleShape bullet;

public:

    const sf::Vector2f & position() const override;
    void update() override;

    Projectile(const sf::Vector2f & position, const float scale);

protected:
    sf::FloatRect globalBounds() const override;
};


#endif //SSPU_UKAZKA_2_PROJECTILE_HPP
