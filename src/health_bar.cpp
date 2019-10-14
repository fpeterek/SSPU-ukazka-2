//
// Created by fpeterek on 14.10.19.
//

#include "health_bar.hpp"

void HealthBar::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(healthBar);
    target.draw(healthOutline);
}

HealthBar::HealthBar(const int64_t maxHp, const float s) : maxHealth(maxHp), scale(s) {

    healthBar.setScale(scale, 1.f);
    healthBar.setFillColor(sf::Color::Green);

    healthOutline.setScale(scale, scale);
    healthOutline.setFillColor(sf::Color(0, 0, 0, 0));
    healthOutline.setOutlineColor(sf::Color::Black);
    healthOutline.setOutlineThickness(1.f);

}

sf::Vector2f HealthBar::calcHealthBarSize(const sf::FloatRect acBounds, const int64_t health) {
    uint64_t height = (float)acBounds.height * health / maxHealth;
    return sf::Vector2f(3, height);
}

sf::Vector2f HealthBar::calcHealthOutlineSize(const sf::FloatRect acBounds) {
    uint64_t height = (float)acBounds.height / scale;
    return sf::Vector2f(3, height);
}

sf::Vector2f HealthBar::calcHealthBarPos(const sf::FloatRect acBounds) {
    return sf::Vector2f(acBounds.left - 10,
                        acBounds.top + acBounds.height - healthBar.getLocalBounds().height);
}

sf::Vector2f HealthBar::calcHealthOutlinePos(const sf::FloatRect acBounds) {
    return sf::Vector2f(acBounds.left - 10, acBounds.top);
}

sf::Color HealthBar::calcHealthBarColor(const int64_t health) {
    const uint8_t r = 255.f * (1.f - ((float)(health - 1) / (maxHealth - 1)));
    const uint8_t g = 255.f * ((float)(health - 1) / (maxHealth - 1));
    const uint8_t b = 0;
    return sf::Color(r, g, b);
}

void HealthBar::updatePos(const sf::FloatRect acBounds) {

    healthBar.setPosition(calcHealthBarPos(acBounds));
    healthOutline.setPosition(calcHealthOutlinePos(acBounds));

}

void HealthBar::updateHealth(const sf::FloatRect acBounds, const int64_t health) {

    healthBar.setSize(calcHealthBarSize(acBounds, health));
    healthOutline.setSize(calcHealthOutlineSize(acBounds));
    healthBar.setPosition(calcHealthBarPos(acBounds));
    healthBar.setFillColor(calcHealthBarColor(health));

}
