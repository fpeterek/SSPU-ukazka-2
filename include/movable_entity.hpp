//
// Created by Peterek, Filip on 19/09/2019.
//

#ifndef SSPU_UKAZKA_2_MOVABLE_ENTITY_HPP
#define SSPU_UKAZKA_2_MOVABLE_ENTITY_HPP

#include "entity.hpp"
#include "velocity.hpp"

namespace sspu {

    class MovableEntity : public Entity {

    protected:

        Velocity velocity;

    public:

        void setVelocity(const Velocity & newV);
        void setVelocity(double x, double y);
        void setVelocityX(double x);
        void setVelocityY(double y);
        const Velocity & getVelocity() const;

    };

}

#endif //SSPU_UKAZKA_2_MOVABLE_ENTITY_HPP
