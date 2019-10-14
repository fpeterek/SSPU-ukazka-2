//
// Created by Peterek, Filip on 16/09/2019.
//

#include <random.hpp>
#include <sstream>
#include <memory>
#include "game.hpp"

using namespace std::placeholders;

const sf::Color Game::background = sf::Color(46, 203, 255);

void Game::draw() {

    win.clear(background);
    for (const Projectile & p : projectiles) {
        win.draw(p);
    }
    for (const Enemy & e : enemies) {
        win.draw(e);
    }
    win.draw(player);
    for(const Particle & p : particles) {
        win.draw(p);
    }
    win.draw(*hud);
    win.display();

}

void Game::handleEvents() {

    sf::Event ev;
    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            win.close();
        }
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
            win.close();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and not gameOver()) {
        player.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and not gameOver()) {
        player.moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and not gameOver()) {
        player.shoot();
    }

}

void Game::tick() {

    if (not gameOver()) {
        spawnEnemies();
    }

    handleEvents();
    handleMovement();

    if (not gameOver()) {
        handleCollisions();
    }
    
    update();

    deleteEntities();

    draw();
}

void Game::update() {

    hud->update(player.hp(), player.score());

    if (not gameOver()) {
        player.update();
        for (auto &e : enemies) {
            e.update();
        }
    }

    if (gameOver()) {
        hud->gameOver();
    }

    for (auto & p : particles) {
        p.update();
    }

}

void Game::run() {

    while (win.isOpen()) {
        tick();
    }

}

Game::Game() :
        win(sf::VideoMode::getDesktopMode(), "Aircraft", sf::Style::Fullscreen),
        scale(win.getSize().x / 800.f),
        projectileFactory(std::bind(&Game::spawnBullet, this, _1, _2, _3, _4), 1.f),
        resourceManager(),
        weaponFactory(projectileFactory),
        particleCreator(std::bind(&Game::spawnParticle, this, _1, _2, _3, _4), resourceManager),
        player(weaponFactory.createPlayerWeapon(), particleCreator, scale) {

    win.setFramerateLimit(60);

    loadTextures();
    loadFonts();

    player.init(resourceManager.getTexture("player"),
            sf::Vector2f(win.getSize().x / 15, win.getSize().y / 2));

    enemyFactory = std::make_shared<EnemyFactory>(resourceManager.getTexture("enemy"), win.getSize(),
            scale, weaponFactory, particleCreator);
    hud = std::make_shared<HUD>(win.getSize(), scale, resourceManager);
    projectileFactory.setScale(scale);

}

void Game::loadTextures() {
    resourceManager.loadTexture("player", "resources/player.png");
    resourceManager.loadTexture("enemy", "resources/enemy.png");
    resourceManager.loadTexture("explosion", "resources/explosion.png");
}

void Game::handleMovement() {

    moveEntity(player);
    for (auto & e : enemies) {
        moveEntity(e);
    }
    for (auto & p : projectiles) {
        moveEntity(p);
    }

}

void Game::moveEntity(Moveable & mv) {

    sf::Vector2f forces = mv.forces();
    mv.move(forces);

    sf::FloatRect bounds = mv.globalBounds();

    if (bounds.top < 0) {
        mv.move(sf::Vector2f(0, bounds.top * -1));
    }
    if (bounds.top > win.getSize().y - bounds.height) {
        mv.move(sf::Vector2f(0, win.getSize().y - (bounds.top + bounds.height)));
    }

}

void Game::deleteEntities() {

    for (auto iter = enemies.begin(); iter != enemies.end();) {

        const auto bounds = iter->globalBounds();
        if (bounds.left < bounds.width * -1 or iter->setForRemoval()) {
            enemies.erase(iter);
        } else {
            ++iter;
        }

    }

    for (auto iter = projectiles.begin(); iter != projectiles.end();) {

        const auto bounds = iter->globalBounds();
        if (bounds.left < bounds.width * -1 or bounds.left > win.getSize().x - bounds.width or iter->setForRemoval()) {
            projectiles.erase(iter);
        } else {
            ++iter;
        }

    }

    for (auto iter = particles.begin(); iter != particles.end();) {
        if (iter->setForRemoval()) {
            particles.erase(iter);
        } else {
            ++iter;
        }
    }

}

void Game::spawnEnemies() {

    if (Random::randInt(1, spawnChance) == spawnChance) {
        enemies.emplace_back(enemyFactory->randomEnemy());
    }

}

void Game::handleCollisions() {
    for (Enemy & e : enemies) {
        if (e.hitboxHitDetection(player)) {
            e.onCrash();
            player.onCrash();
        }
    }

    for (Projectile & p : projectiles) {
        if (p.shooter() == Shooter::Enemy) {
            if (player.hitboxHitDetection(p)) {
                player.onHit();
                p.onCrash();
            }
        } else {
            for (Enemy & e : enemies) {
                if (e.hitboxHitDetection(p)) {
                    player.incScore();
                    e.onHit();
                    p.onCrash();
                    continue;
                }
            }
        }
    }

}

void Game::spawnBullet(sf::Vector2f pos, Shooter shooter, sf::Vector2f forces, sf::Color fill) {
    projectiles.emplace_back(pos, scale, shooter, forces, fill);
}

void Game::loadFonts() {
    resourceManager.loadFont("main", "resources/LCD_Solid.ttf");
}

void Game::spawnParticle(const sf::Texture & txt, const uint64_t count, const uint64_t period, sf::Vector2f pos) {
    particles.emplace_back(txt, count, period, scale, pos);
}

bool Game::gameOver() const {
    return player.hp() <= 0;
}
