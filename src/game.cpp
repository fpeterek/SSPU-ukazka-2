//
// Created by Peterek, Filip on 16/09/2019.
//

#include <random.hpp>
#include <sstream>
#include "game.hpp"

using namespace std::placeholders;

const sf::Color Game::background = sf::Color(255, 255, 255);

void Game::draw() {

    win.clear(background);
    for (const Projectile & p : projectiles) {
        win.draw(p);
    }
    for (const Enemy & e : enemies) {
        win.draw(e);
    }
    win.draw(player);
    displayInfo();
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player.moveDown();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.shoot();
    }

}

void Game::tick() {
    spawnEnemies();
    handleEvents();
    handleMovement();
    handleCollisions();
    deleteEntities();
    player.update();
    for (auto & e : enemies) {
        e.update();
    }
    draw();
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
        weaponFactory(projectileFactory),
        player(sf::Texture(),
                sf::Vector2f(win.getSize().x / 15, win.getSize().y / 2),
                scale,
                weaponFactory.createPlayerWeapon()
                ) {

    win.setFramerateLimit(60);

    loadTextures();
    loadFonts();

    player.setTexture(resourceManager.getTexture("player"));
    enemyFactory = std::make_shared<EnemyFactory>(resourceManager.getTexture("enemy"), win.getSize(), scale, weaponFactory);
    projectileFactory.setScale(scale);

}

void Game::loadTextures() {
    resourceManager.loadTexture("player", "resources/player.png");
    resourceManager.loadTexture("enemy", "resources/enemy.png");
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

void Game::displayInfo() {

    std::stringstream ss;
    ss << "Health: " << player.hp() << std::endl;

    std::stringstream ss2;
    ss2 << "Score: " << player.score() << std::endl;

    sf::Text left(ss.str(), resourceManager.getFont("main"), 12 * scale);
    sf::Text right(ss2.str(), resourceManager.getFont("main"), 12 * scale);

    left.setPosition(5, 0);
    right.setPosition(win.getSize().x - right.getLocalBounds().width - 5, 0);

    left.setFillColor(sf::Color::Black);
    right.setFillColor(sf::Color::Black);

    win.draw(left);
    win.draw(right);

}
