//
// Created by Peterek, Filip on 16/09/2019.
//

#include "engine.hpp"

using sspu::Engine;

const sf::Color Engine::background = sf::Color(255, 255, 255);

void Engine::draw() {

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

void Engine::handleEvents() {

    sf::Event ev;
    while (win.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed) {
            win.close();
        }
        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape) {
            win.close();
        }
    }

}

void Engine::tick() {
    handleEvents();
    draw();
}

void Engine::run() {

    while (win.isOpen()) {
        tick();
    }

}

Engine::Engine() :
        win(sf::VideoMode::getDesktopMode(), "Aircraft", sf::Style::Fullscreen),
        player(sf::Texture(), sf::Vector2f(0, 0), 1.f) {

    win.setFramerateLimit(60);
    scale = win.getSize().x / 800.f;

}

