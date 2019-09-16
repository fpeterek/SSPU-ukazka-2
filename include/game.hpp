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
#include "texture_manager.hpp"

class Game {

    static const sf::Color background;

    sf::RenderWindow win;
    TextureManager textureManager;
    float scale;


    Player player;

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    void loadTextures();

    void createEnemy(const sf::Vector2f & position);

    void tick();
    void handleEvents();
    void draw();

public:

    Game();
    void run();

};


#endif //SSPU_UKAZKA_2_GAME_HPP
