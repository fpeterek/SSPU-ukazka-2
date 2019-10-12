//
// Created by Filip Peterek on 12/10/2019.
//

#include "weapon.hpp"

Weapon::Weapon(ProjectileFactory & pf, uint64_t cooldown, Shooter owner)
        : pf(pf), cooldown(cooldown), owner(owner) {

}

bool Weapon::canShoot() const {
    return not counter;
}

void Weapon::shoot(sf::Vector2f position) {
    if (canShoot()) {
        pf.get().spawnProjectile(position, owner);
        counter = cooldown;
    }
}

void Weapon::tick() {
    if (counter) {
        --counter;
    }
}
