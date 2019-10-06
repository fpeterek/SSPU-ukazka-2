//
// Created by Peterek, Filip on 16/09/2019.
//

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.moveUp();
    }

}

void Game::tick() {
    handleEvents();
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

    createEnemy(sf::Vector2f(win.getSize().x - win.getSize().x / 10, win.getSize().y / 4));
    createEnemy(sf::Vector2f(win.getSize().x - win.getSize().x / 6, win.getSize().y / 2));
    createEnemy(sf::Vector2f(win.getSize().x - win.getSize().x / 16, win.getSize().y / 4 * 3));

}

void Game::createEnemy(const sf::Vector2f & position) {
    enemies.emplace_back(textureManager.getTexture("enemy"), position, scale);
}

void Game::loadTextures() {
    textureManager.loadTexture("player", "resources/player.png");
    textureManager.loadTexture("enemy", "resources/enemy.png");
}

