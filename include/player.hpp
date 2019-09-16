//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_PLAYER_HPP
#define SSPU_UKAZKA_2_PLAYER_HPP


#include "aircraft.hpp"

class Player : public Aircraft {
public:
    Projectile shoot() override;

    void update() override;
};


#endif //SSPU_UKAZKA_2_PLAYER_HPP
