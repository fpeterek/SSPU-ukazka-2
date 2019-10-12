//
// Created by Filip Peterek on 12/10/2019.
//

#ifndef SSPU_UKAZKA_2_WEAPON_HPP
#define SSPU_UKAZKA_2_WEAPON_HPP

#include "projectile_factory.hpp"

class Weapon {

    std::reference_wrapper<ProjectileFactory> pf;
    uint64_t cooldown;
    Shooter owner;

    uint64_t counter = 0;

public:

    Weapon(ProjectileFactory & pf, uint64_t cooldown, Shooter owner);

    bool canShoot() const;
    void shoot(sf::Vector2f position);
    void tick();

};

#endif //SSPU_UKAZKA_2_WEAPON_HPP
