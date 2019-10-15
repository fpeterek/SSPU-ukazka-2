//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_GAME_HPP
#define SSPU_UKAZKA_2_GAME_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "projectile.hpp"
#include "enemy.hpp"
#include "player.hpp"
#include "resource_manager.hpp"
#include "enemy_factory.hpp"
#include "projectile_factory.hpp"
#include "weapon_factory.hpp"
#include "particle.hpp"
#include "particle_creator.hpp"
#include "hud.hpp"
#include "background.hpp"

class Game {

    static constexpr uint64_t spawnChance = 30;

    sf::RenderWindow win;
    ResourceManager resourceManager;
    std::shared_ptr<Background> background;
    std::shared_ptr<EnemyFactory> enemyFactory;
    ProjectileFactory projectileFactory;
    WeaponFactory weaponFactory;
    ParticleCreator particleCreator;
    std::shared_ptr<HUD> hud;
    const float scale;

    Player player;

    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    std::vector<Particle> particles;

    bool gameOver() const;

    void loadTextures();
    void loadFonts();

    void spawnEnemies();
    void deleteEntities();
    void handleCollisions();
    void tick();
    void update();
    void handleEvents();
    void draw();
    void handleMovement();
    void moveEntity(Moveable & mv);
    void spawnBullet(sf::Vector2f pos, Shooter shooter, sf::Vector2f forces, sf::Color fill);
    void spawnParticle(const sf::Texture & txt, uint64_t spriteCount, uint64_t period, sf::Vector2f pos);

public:

    Game();
    void run();

};


#endif //SSPU_UKAZKA_2_GAME_HPP
