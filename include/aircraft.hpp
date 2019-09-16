//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_AIRCRAFT_HPP
#define SSPU_UKAZKA_2_AIRCRAFT_HPP

#include <SFML/Graphics.hpp>

#include "projectile.hpp"
#include "entity.hpp"

class Aircraft : public Entity {

    sf::Sprite sprite;

protected:

    sf::FloatRect globalBounds() const override;
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

    Aircraft(const sf::Texture & texture, const sf::Vector2f & pos, float scale);

public:

    virtual Projectile shoot() = 0;
    const sf::Vector2f & position() const override;

};


#endif //SSPU_UKAZKA_2_AIRCRAFT_HPP
