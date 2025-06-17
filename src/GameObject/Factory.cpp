#include "GameObject/Factory.h"

// return map of Factory.
std::map<char, Factory::CreatorFunc>& Factory::getMap() 
{
    static std::map<char, CreatorFunc> map;
    return map;
}

// bool unimportant !
// Just because the classes that implement it have a variable that is STATIC.
// And it needs to be a certain TYPE , and we randomly chose it to be bool .
bool Factory::registerIt(char symbol, CreatorFunc func) {
    getMap()[symbol] = func; 
    return true;
}


// if exist object in map , Return a constructed and ready-to-use object !
std::unique_ptr<Object> Factory::create(char symbol, sf::Vector2f location, const ImagesObject& images) {
    auto it = getMap().find(symbol);
    if (it != getMap().end())
        return it->second(location, images);
    return nullptr;
}