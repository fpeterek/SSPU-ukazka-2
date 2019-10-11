//
// Created by Peterek, Filip on 16/09/2019.
//

#include <random.hpp>
#include "game.hpp"

const sf::Color Game::background = sf::Color(255, 255, 255);

void Game::draw() {

    win.clear(sf::Color::White);
    for (const Projectile & p : projectiles) {
        win.draw(p);
    }
    for (const Enemy & e : enemies) {
        win.draw(e);
    }
    win.draw(player);
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

}

void Game::tick() {
    spawnEnemies();
    handleEvents();
    handleMovement();
    handleCollisions();
    deleteEnemies();
    player.update();
    draw();
}

void Game::run() {

    while (win.isOpen()) {
        tick();
    }

}

Game::Game() :
        win(sf::VideoMode::getDesktopMode(), "Aircraft", sf::Style::Fullscreen),
        player(sf::Texture(), sf::Vector2f(0, 0), 1.f) {

    win.setFramerateLimit(60);
    scale = win.getSize().x / 800.f;

    loadTextures();

    const auto playerPos = sf::Vector2f(win.getSize().x / 15, win.getSize().y / 2);
    player = Player(textureManager.getTexture("player"), playerPos, scale);

    enemyFactory = std::make_shared<EnemyFactory>(textureManager.getTexture("enemy"), win.getSize(), scale);

}

void Game::loadTextures() {
    textureManager.loadTexture("player", "resources/player.png");
    textureManager.loadTexture("enemy", "resources/enemy.png");
}

void Game::handleMovement() {

    moveEntity(player);
    for (auto & e : enemies) {
        moveEntity(e);
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

void Game::deleteEnemies() {

    for (auto iter = enemies.begin(); iter != enemies.end();) {

        const auto bounds = iter->globalBounds();
        if (bounds.left < bounds.width * -1 or iter->setForRemoval()) {
            enemies.erase(iter);
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
}

