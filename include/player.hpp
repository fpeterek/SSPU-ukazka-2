//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PLAYER_HPP
#define SSPU_UKAZKA_2_PLAYER_HPP

#include <iostream>
#include "aircraft.hpp"
#include "health_bar.hpp"

class Player : public Aircraft {

    static const int64_t maxHealth;
    static const uint64_t verticalVelocity;

    uint64_t _score = 0;

    HealthBar healthBar;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:

    void update() override;
    Player(Weapon weapon, const ParticleCreator & particleCreator, float scale);

    void moveUp();
    void moveDown();

    bool setForRemoval() const override;
    void onCrash() override;

    uint64_t score() const;
    void incScore();

    void move(sf::Vector2f diff) override;
    void setPosition(sf::Vector2f pos) override;

    void onHit() override;

    void init(const sf::Texture & texture, const sf::Vector2f & pos);

};


#endif //SSPU_UKAZKA_2_PLAYER_HPP
