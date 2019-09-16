//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PROJECTILE_HPP
#define SSPU_UKAZKA_2_PROJECTILE_HPP


#include "entity.hpp"

class Projectile : public Entity {

    static const sf::Color fill;
    static const sf::Color outline;
    static const uint64_t radius;
    sf::CircleShape bullet;

    sf::FloatRect globalBounds() const override;

public:

    const sf::Vector2f & position() const override;
    void update() override;
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

    float scale() const override;

    Projectile(const sf::Vector2f & position, float scale);

};


#endif //SSPU_UKAZKA_2_PROJECTILE_HPP
