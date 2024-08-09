#pragma once
#include "Rectangle.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>


class Object : public sf::Transformable {
public:
    std::string name;
    Object();
    void addComponent(std::string, std::string);
    bool hasComponent(std::string);
    bool hasComponentName(std::string, std::string);
    Rectangle getRectangle(std::string);

    std::vector<Rectangle> rectangleList;

};