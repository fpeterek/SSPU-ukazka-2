//
// Created by fpeterek on 14.10.19.
//

#ifndef SSPU_UKAZKA_2_HEALTH_BAR_HPP
#define SSPU_UKAZKA_2_HEALTH_BAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class HealthBar : public sf::Drawable {

    sf::RectangleShape healthBar;
    sf::RectangleShape healthOutline;
    sf::Vector2f calcHealthBarSize(sf::FloatRect acBounds, int64_t health);
    sf::Vector2f calcHealthOutlineSize(sf::FloatRect acBounds);
    sf::Vector2f calcHealthBarPos(sf::FloatRect acBounds);
    sf::Vector2f calcHealthOutlinePos(sf::FloatRect acBounds);
    sf::Color calcHealthBarColor(int64_t health);

    const float scale;
    const int64_t maxHealth;

protected:
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

public:

    HealthBar(int64_t maxHealth, float scale);
    void updatePos(sf::FloatRect acBounds);
    void updateHealth(sf::FloatRect acBounds, int64_t health);

};

#endif //SSPU_UKAZKA_2_HEALTH_BAR_HPP
