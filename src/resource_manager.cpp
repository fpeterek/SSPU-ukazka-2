//
// Created by Peterek, Filip on 16/09/2019.
//

#include "resource_manager.hpp"

void ResourceManager::loadTexture(const std::string & texture, const std::string & filename) {
    textures[texture].loadFromFile(filename);
}

const sf::Texture & ResourceManager::getTexture(const std::string & txt) const {
    return textures.at(txt);
}

void ResourceManager::loadFont(const std::string & font, const std::string & filename) {
    fonts[font].loadFromFile(filename);
}

const sf::Font &ResourceManager::getFont(const std::string & font) const {
    return fonts.at(font);
}


