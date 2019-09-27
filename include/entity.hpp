//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_ENTITY_HPP
#define SSPU_UKAZKA_2_ENTITY_HPP

#include <SFML/Graphics.hpp>

namespace sspu {

    class Entity : public sf::Drawable {

    protected:
        virtual sf::FloatRect globalBounds() const = 0;

    public:

        bool intersects(const Entity & ac) const;

        virtual const sf::Vector2f & position() const = 0;
        virtual float scale() const = 0;
        virtual void update() = 0;

    };

}

#endif //SSPU_UKAZKA_2_ENTITY_CPP
