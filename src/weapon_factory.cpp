//
// Created by Filip Peterek on 12/10/2019.
//

#include "weapon_factory.hpp"

WeaponFactory::WeaponFactory(ProjectileFactory & pf) : pf(pf) { }

Weapon WeaponFactory::createPlayerWeapon() {
    return Weapon(pf, playerCooldown, Shooter::Player);
}

Weapon WeaponFactory::createEnemyWeapon() {
    return Weapon(pf, enemyCooldown, Shooter::Enemy);
}



