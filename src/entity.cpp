//
// Created by Peterek, Filip on 16/09/2019.
//

#include "entity.hpp"

bool Entity::intersects(const Entity & ac) const {
    return globalBounds().intersects(ac.globalBounds());
}

bool Entity::onHit() {
    return false;
}

bool Entity::onCrash() {
    return false;
}
