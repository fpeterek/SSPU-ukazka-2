//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_ENEMY_HPP
#define SSPU_UKAZKA_2_ENEMY_HPP


#include "aircraft.hpp"

class Enemy : public Aircraft {

    static const int64_t maxHealth;

public:

    void update() override;
    Enemy(const sf::Texture & texture, const sf::Vector2f & pos, float scale, Weapon weapon);

};


#endif //SSPU_UKAZKA_2_ENEMY_HPP
