//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PLAYER_HPP
#define SSPU_UKAZKA_2_PLAYER_HPP


#include "aircraft.hpp"

class Player : public Aircraft {

    static const int64_t maxHealth;

public:

    Projectile shoot() override;
    void update() override;
    Player(const sf::Texture & texture, const sf::Vector2f & pos, float scale);

    bool onHit() override;

    bool onCrash() override;

};


#endif //SSPU_UKAZKA_2_PLAYER_HPP
