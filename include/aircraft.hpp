//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_AIRCRAFT_HPP
#define SSPU_UKAZKA_2_AIRCRAFT_HPP

#include <SFML/Graphics.hpp>

#include "projectile.hpp"
#include "entity.hpp"

class Aircraft : public Entity, public Moveable {

    sf::Sprite sprite;
    sf::RectangleShape wingBox;
    sf::RectangleShape fuselageBox;

protected:

    int64_t health = 0;
    sf::Vector2f forceVector;

    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

    Aircraft(const sf::Texture & texture, const sf::Vector2f & pos, float scale);

public:

    int64_t hp();
    void move(sf::Vector2f diff) override;
    void setPosition(sf::Vector2f pos) override;
    sf::FloatRect globalBounds() const override;
    virtual Projectile shoot() = 0;
    const sf::Vector2f & position() const override;
    float scale() const override;
    void rotate(float val);
    sf::Vector2f forces() const override;
    void onHit() override;
    void onCrash() override;
    bool setForRemoval() override;
    bool hitboxHitDetection(const Entity & e);
    bool hitboxHitDetection(const Aircraft & e);

};


#endif //SSPU_UKAZKA_2_AIRCRAFT_HPP
