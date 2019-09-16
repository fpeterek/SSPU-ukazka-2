//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_GAME_HPP
#define SSPU_UKAZKA_2_GAME_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"

class Game {

    sf::RenderWindow win;
    static const sf::Color background;

    Player player;

    std::vector<sf::Texture> textures;
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    void draw();

public:

    void run();

};


#endif //SSPU_UKAZKA_2_GAME_HPP
