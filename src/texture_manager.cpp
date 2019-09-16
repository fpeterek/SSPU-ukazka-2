//
// Created by Peterek, Filip on 16/09/2019.
//

#include "texture_manager.hpp"

void TextureManager::loadTexture(const std::string & texture, const std::string & filename) {
    textures[texture].loadFromFile(filename);
}

const sf::Texture & TextureManager::getTexture(const std::string & txt) const {
    return textures.at(txt);
}
