//
// Created by fpeterek on 13.10.19.
//

#include <SFML/Graphics/Rect.hpp>
#include <entity.hpp>
#include <particle.hpp>


sf::FloatRect Particle::globalBounds() const {
    return sprite.getGlobalBounds();
}

const sf::Vector2f & Particle::position() const {
    return sprite.getPosition();
}

float Particle::scale() const {
    return sprite.getScale().x;
}

void Particle::update() {

    ++counter;
    spriteIndex = counter / period;
    updateSprite();

}

void Particle::onHit() { }


void Particle::onCrash() { }

bool Particle::intersects(const Entity & entity) const {
    return globalBounds().intersects(entity.globalBounds());
}

bool Particle::setForRemoval() const {
    return spriteIndex >= spriteCount;
}

void Particle::init(const sf::Texture & txt, const uint64_t count, const uint64_t per, const float scale,
        sf::Vector2f pos) {

    spritesheet = txt;
    spriteCount = count;
    period = per;

    const sf::Texture & sheet = spritesheet.get();

    spriteHeight = sheet.getSize().y;
    spriteWidth = sheet.getSize().x / spriteCount;

    sprite.setTexture(sheet);
    updateSprite();
    sprite.setScale(scale, scale);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(pos);

}

Particle::Particle(const sf::Texture & txt, const uint64_t spriteCount, const uint64_t period,
        const float scale, sf::Vector2f pos) : spritesheet(txt), spriteCount(spriteCount), period(period) {

    init(txt, spriteCount, period, scale, pos);

}

Particle & Particle::operator=(const Particle &orig) {
    init(orig.spritesheet.get(), orig.spriteCount, orig.period, orig.scale(), orig.position());
    counter = orig.counter;
    spriteIndex = orig.spriteIndex;
    return *this;
}

void Particle::draw(sf::RenderTarget & target, sf::RenderStates states) const {

    if (not setForRemoval()) {
        target.draw(sprite);
    }

}

void Particle::updateSprite() {
    sf::IntRect rect(spriteIndex * spriteWidth, 0, spriteWidth, spriteHeight);
    sprite.setTextureRect(rect);
}
