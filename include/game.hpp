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
#include "enemy_factory.hpp"
#include "projectile_factory.hpp"
#include "weapon_factory.hpp"

class Game {

    static const sf::Color background;
    static constexpr uint64_t spawnChance = 30;

    sf::RenderWindow win;
    TextureManager textureManager;
    std::shared_ptr<EnemyFactory> enemyFactory;
    ProjectileFactory projectileFactory;
    WeaponFactory weaponFactory;
    const float scale;

    Player player;

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    void loadTextures();

    void spawnEnemies();
    void deleteEntities();
    void handleCollisions();
    void tick();
    void handleEvents();
    void draw();
    void handleMovement();
    void moveEntity(Moveable & mv);
    void spawnBullet(sf::Vector2f pos, Shooter shooter, sf::Vector2f forces, sf::Color fill);

public:

    Game();
    void run();

};


#endif //SSPU_UKAZKA_2_GAME_HPP
