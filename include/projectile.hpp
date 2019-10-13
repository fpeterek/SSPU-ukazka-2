//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PROJECTILE_HPP
#define SSPU_UKAZKA_2_PROJECTILE_HPP


#include "entity.hpp"

enum class Shooter {
    Player,
    Enemy
};

class Projectile : public Entity, public Moveable {

    sf::Color fill;
    static const sf::Color outline;
    static const uint64_t radius;

    sf::CircleShape bullet;

    sf::Vector2f forceVector;
    bool keepAlive = true;
    Shooter sh;

public:

    sf::FloatRect globalBounds() const override;

    static constexpr int64_t velocity = 10;

    const sf::Vector2f & position() const override;
    void update() override;
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

    uint64_t damage();

    float scale() const override;

    void onHit() override;
    void onCrash() override;
    bool setForRemoval() const override;

    void setPosition(sf::Vector2f newPos) override;
    void move(sf::Vector2f diff) override;
    sf::Vector2f forces() const override;

    Projectile(const sf::Vector2f & position, float scale, Shooter shooter, sf::Vector2f forces, sf::Color fill);

    Shooter shooter();

};


#endif //SSPU_UKAZKA_2_PROJECTILE_HPP
