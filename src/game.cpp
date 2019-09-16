//
// Created by Peterek, Filip on 16/09/2019.
//

#include "game.hpp"

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
    win.display();

}

void Game::run() {

    while (win.isOpen()) {
        draw();
    }

}
