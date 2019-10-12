//
// Created by Filip Peterek on 12/10/2019.
//

#ifndef SSPU_UKAZKA_2_WEAPON_FACTORY_HPP
#define SSPU_UKAZKA_2_WEAPON_FACTORY_HPP

#include "weapon.hpp"

class WeaponFactory {

    ProjectileFactory & pf;

public:

    static constexpr uint64_t playerCooldown = 30;
    static constexpr uint64_t enemyCooldown = 120;

    explicit WeaponFactory(ProjectileFactory & pf);
    Weapon createPlayerWeapon();
    Weapon createEnemyWeapon();

};

#endif //SSPU_UKAZKA_2_WEAPON_FACTORY_HPP
