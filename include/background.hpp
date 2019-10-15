//
// Created by fpeterek on 15.10.19.
//

#ifndef SSPU_UKAZKA_2_BACKGROUND_HPP
#define SSPU_UKAZKA_2_BACKGROUND_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "resource_manager.hpp"
#include "random.hpp"

struct Cloud : public sf::Sprite {

    sf::Vector2f forces;
    Cloud(sf::Vector2f forces);

};

class Background : public sf::Drawable {

    static constexpr int64_t cloudChance = 120;
    static constexpr uint64_t maxClouds = 40;

    const ResourceManager & rm;
    const sf::Vector2u winSize;
    const float scale;
    const sf::Color background = sf::Color(46, 203, 255);

    std::vector<Cloud> clouds;
    const sf::Texture & txt;
    sf::RectangleShape bg;

    void moveClouds();
    void removeClouds();
    void createCloud();
    void randomCloud();
    bool shouldCreateCloud();
    bool cloudOutsideBouds(const Cloud & cloud);

    void randomizeClouds();

protected:

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

public:

    Background(const ResourceManager & resourceManager, sf::Vector2u windowSize, float scale);
    void update();

};

#endif //SSPU_UKAZKA_2_BACKGROUND_HPP
