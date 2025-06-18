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
    // std::function <>  =  pointer to a function.
    // Function accept   =  ( vector2f , ImagesObject& ).
    // Function returned =  std::unique_ptr<Object>.
    using CreatorFunc = std::function<std::unique_ptr<Object>(sf::Vector2f, const ImagesObject&)>;

    // STATIC Compile-time : create fuctory!
    // We want to run the function in the GameController. >> after << the factory is already built!
    // give arguments and take pointer to basic class .
    static std::unique_ptr<Object> create(char symbol, sf::Vector2f location, const ImagesObject& images);

    // STATIC function.
    // Compile-time : coordination between the character and the representing class.
    static bool registerIt(char symbol, CreatorFunc func);

private:

    // create map. 
    // accept - char : returned - pointer to function .
    static std::map<char, CreatorFunc>& getMap();//m_map 
};