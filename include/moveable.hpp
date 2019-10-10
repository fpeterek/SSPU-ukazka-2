//
// Created by fpeterek on 10.10.19.
//

#ifndef SSPU_UKAZKA_2_MOVEABLE_HPP
#define SSPU_UKAZKA_2_MOVEABLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Moveable {

public:
    virtual sf::FloatRect globalBounds() const = 0;
    virtual void setPosition(sf::Vector2f newPos) = 0;
    virtual void move(sf::Vector2f diff) = 0;
    virtual sf::Vector2f forces() const = 0;
};

#endif //SSPU_UKAZKA_2_MOVEABLE_HPP
