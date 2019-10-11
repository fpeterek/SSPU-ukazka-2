//
// Created by Filip Peterek on 11/10/2019.
//

#ifndef SSPU_UKAZKA_2_ENEMY_FACTORY_HPP
#define SSPU_UKAZKA_2_ENEMY_FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "enemy.hpp"
#include "random.hpp"

class EnemyFactory {

    const sf::Texture & texture;
    const sf::Vector2u dim;
    const float scale;
    const uint64_t yBound;

public:
    EnemyFactory(const sf::Texture & texture, sf::Vector2u dim, float scale);
    Enemy randomEnemy();

};

#endif //SSPU_UKAZKA_2_ENEMY_FACTORY_HPP
