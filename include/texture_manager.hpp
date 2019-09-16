//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_TEXTURE_MANAGER_HPP
#define SSPU_UKAZKA_2_TEXTURE_MANAGER_HPP

#include <unordered_map>

#include <SFML/Graphics.hpp>

class TextureManager {

    std::unordered_map<std::string, sf::Texture> textures;

public:

    void loadTexture(const std::string & texture, const std::string & filename);
    const sf::Texture & getTexture(const std::string & txt) const;

};

#endif //SSPU_UKAZKA_2_TEXTURE_MANAGER_HPP
