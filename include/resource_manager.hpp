//
// Created by Peterek, Filip on 16/09/2019.
//

#ifndef SSPU_UKAZKA_2_RESOURCE_MANAGER_HPP
#define SSPU_UKAZKA_2_RESOURCE_MANAGER_HPP

#include <unordered_map>

#include <SFML/Graphics.hpp>

class ResourceManager {

    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> fonts;

public:

    void loadTexture(const std::string & texture, const std::string & filename);
    const sf::Texture & getTexture(const std::string & txt) const;

    void loadFont(const std::string & font, const std::string & filename);
    const sf::Font & getFont(const std::string & font) const;


};

#endif //SSPU_UKAZKA_2_RESOURCE_MANAGER_HPP
