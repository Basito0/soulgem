#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Object {
public:
    std::string name;
    bool hasComponent(std::string);
    void addComponent(std::string);
    void setRect(sf::RectangleShape r);
    sf::RectangleShape getRect();
    Object();
private:
    std::map<std::string, int> dictionary;
    sf::RectangleShape rect;
};