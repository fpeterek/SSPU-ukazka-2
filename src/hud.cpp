//
// Created by fpeterek on 14.10.19.
//

#include "hud.hpp"

void HUD::draw(sf::RenderTarget & target, sf::RenderStates states) const {

    target.draw(hText);
    target.draw(sText);

    if (isOver) {
        target.draw(goText);
    }

}

HUD::HUD(const sf::Vector2u windowSize, const float scale, const ResourceManager & resourceManager) :
    dim(windowSize), scale(scale), rm(resourceManager) {

    goText = sf::Text("Game Over", rm.getFont("main"), 36 * scale);
    goText.setPosition(dim.x / 2 - goText.getLocalBounds().width / 2,
                     dim.y / 2 - goText.getLocalBounds().height / 2);

    hText = sf::Text("", resourceManager.getFont("main"), 12 * scale);
    sText = sf::Text("", resourceManager.getFont("main"), 12 * scale);

    hText.setPosition(5, 0);

    hText.setFillColor(sf::Color::Black);
    sText.setFillColor(sf::Color::Black);

}

void HUD::gameOver() {
    isOver = true;
}

void HUD::update(const int64_t hp, const int64_t sc) {

    health = hp;
    score = sc;

    std::stringstream ss;
    ss << "Health: " << health << std::endl;

    std::stringstream ss2;
    ss2 << "Score: " << score << std::endl;

    hText.setString(ss.str());
    sText.setString(ss2.str());

    sText.setPosition(dim.x - sText.getLocalBounds().width - 5, 0);

}
