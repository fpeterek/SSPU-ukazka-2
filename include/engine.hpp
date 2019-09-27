//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_ENGINE_HPP
#define SSPU_UKAZKA_2_ENGINE_HPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "texture_manager.hpp"

namespace sspu {

    class Engine {

        static const sf::Color background;

        sf::RenderWindow win;
        TextureManager textureManager;
        float scale;


        Player player;

        std::vector<Enemy> enemies;
        std::vector<Projectile> projectiles;

        void tick();
        void handleEvents();
        void draw();

    public:

        Engine();

        void run();

    };

}


#endif //SSPU_UKAZKA_2_ENGINE_HPP
