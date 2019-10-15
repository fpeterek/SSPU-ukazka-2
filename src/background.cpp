//
// Created by fpeterek on 15.10.19.
//

#include <iostream>
#include "background.hpp"

Background::Background(const ResourceManager & resourceManager, const sf::Vector2u windowSize, const float scale) :
    rm(resourceManager), winSize(windowSize), scale(scale), txt(rm.getTexture("cloud")) {

    bg.setFillColor(background);
    bg.setPosition(0, 0);
    bg.setSize({(float)windowSize.x, (float)windowSize.y});

    randomizeClouds();

}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const {

    target.draw(bg);
    for (const Cloud & cloud : clouds) {
        target.draw(cloud);
    }

}

void Background::update() {

    moveClouds();
    removeClouds();
    randomCloud();

}

void Background::moveClouds() {

    for (Cloud & cloud : clouds) {
        cloud.move(cloud.forces);
    }

}

void Background::removeClouds() {

    for (auto iter = clouds.begin(); iter != clouds.end();) {

        if (cloudOutsideBouds(*iter)) {
            clouds.erase(iter);
        } else {
            ++iter;
        }

    }

}

bool Background::cloudOutsideBouds(const Cloud & cloud) {

    const bool outOfBoundsLeft = cloud.getGlobalBounds().left + cloud.getGlobalBounds().width < 0;
    const bool outOfBoundsRight = cloud.getGlobalBounds().left > winSize.x;

    return outOfBoundsLeft or outOfBoundsRight;
}

bool Background::shouldCreateCloud() {
    return clouds.size() < maxClouds and Random::randInt(1, cloudChance) == cloudChance;
}

void Background::randomCloud() {

    if (shouldCreateCloud()) {
        createCloud();
    }

}

void Background::createCloud() {

    const float v = -1 * (0.3f + (Random::randInt(0, 10) * 0.1f));

    const float scaleMod = Random::randInt(0, 6) * 0.1f - 0.3f;

    clouds.emplace_back(sf::Vector2f(v, 0.f));

    Cloud & cloud = clouds.back();
    cloud.setTexture(txt);
    cloud.setScale((1.5f + scaleMod) * scale, (1.5f + scaleMod) * scale);

    const int64_t x = winSize.x;
    const int64_t y = Random::randInt(0, winSize.y - cloud.getGlobalBounds().height);

    cloud.setPosition(x, y);

}

void Background::randomizeClouds() {

    for (int i = 0; i < maxClouds / 4; ++i) {
        createCloud();
        Cloud & cloud = clouds.back();
        const auto pos = cloud.getPosition();
        uint64_t randomX = Random::randInt(0, winSize.x - cloud.getGlobalBounds().width);
        cloud.setPosition(randomX, pos.y);
    }

}

Cloud::Cloud(sf::Vector2f forces) : forces(forces) { }
