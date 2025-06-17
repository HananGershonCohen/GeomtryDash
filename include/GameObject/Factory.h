#pragma once

#include <map>
#include <memory>
#include <functional>
#include <SFML/Graphics.hpp>

#include "GameObject/Object.h"
#include "GameObject/Images/ImagesObject.h"

class Factory
{
public:
    using CreatorFunc = std::function<std::unique_ptr<Object>(sf::Vector2f, const ImagesObject&)>;

    static std::unique_ptr<Object> create(char symbol, sf::Vector2f location, const ImagesObject& images);
    static bool registerIt(char symbol, CreatorFunc func);

private:
    static std::map<char, CreatorFunc>& getMap();//m_map 
};