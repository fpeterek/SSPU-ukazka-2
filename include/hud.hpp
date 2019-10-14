//
// Created by fpeterek on 14.10.19.
//

#ifndef SSPU_UKAZKA_2_HUD_HPP
#define SSPU_UKAZKA_2_HUD_HPP

#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "resource_manager.hpp"

class HUD : public sf::Drawable {

    const float scale;
    const sf::Vector2u dim;

    int64_t health = 0;
    int64_t score = 3;

    sf::Text hText;
    sf::Text sText;
    sf::Text goText;

    bool isOver = false;

    const ResourceManager & rm;

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

public:

    HUD(sf::Vector2u windowSize, float scale, const ResourceManager & resourceManager);

    void update(int64_t health, int64_t score);
    void gameOver();

};

#endif //SSPU_UKAZKA_2_HUD_HPP
