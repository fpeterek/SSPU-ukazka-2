//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_ENTITY_HPP
#define SSPU_UKAZKA_2_ENTITY_HPP

#include <SFML/Graphics.hpp>

#include "moveable.hpp"

class Entity : public sf::Drawable {

protected:

    float velocity;

public:

    virtual bool intersects(const Entity & entity) const;
    virtual sf::FloatRect globalBounds() const = 0;

    virtual const sf::Vector2f & position() const = 0;
    virtual float scale() const = 0;
    virtual void update() = 0;
    virtual void onHit() = 0;
    virtual void onCrash() = 0;
    virtual bool setForRemoval() const = 0;

};

#endif //SSPU_UKAZKA_2_ENTITY_CPP
