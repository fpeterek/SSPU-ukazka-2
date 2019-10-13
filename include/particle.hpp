//
// Created by fpeterek on 13.10.19.
//

#ifndef SSPU_UKAZKA_2_PARTICLE_HPP
#define SSPU_UKAZKA_2_PARTICLE_HPP

#include <functional>

#include "entity.hpp"

class Particle : public Entity {

    uint64_t counter = 0;
    uint64_t period = 0;
    uint64_t spriteIndex = 0;
    uint64_t spriteCount = 0;
    uint64_t spriteHeight = 0;
    uint64_t spriteWidth = 0;

    std::reference_wrapper<const sf::Texture> spritesheet;

    sf::Sprite sprite;

    void updateSprite();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:

    void init(const sf::Texture & txt, uint64_t spriteCount, uint64_t period, float scale, sf::Vector2f pos);

    Particle(const sf::Texture & txt, uint64_t spriteCount, uint64_t period, float scale, sf::Vector2f pos);
    Particle & operator=(const Particle & orig);


    sf::FloatRect globalBounds() const override;
    const sf::Vector2f & position() const override;
    float scale() const override;
    void update() override;
    void onHit() override;
    void onCrash() override;
    bool intersects(const Entity &entity) const override;
    bool setForRemoval() const override;

};

#endif //SSPU_UKAZKA_2_PARTICLE_HPP
