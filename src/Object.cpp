#include "Object.h"
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

Object::Object() {
}

void Object::addComponent(std::string type, std::string name) {
    if (type == "Rectangle") {
        Rectangle rect(*this);
        rect.name = name;
        rectangleList.push_back(rect);
    }
}

bool Object::hasComponent(std::string type) {
    if (type == "Rectangle") {
        for (auto& component : rectangleList) {
                return true;
        }
    }
    return false;
}

bool Object::hasComponentName(std::string type, std::string name) {
    if (type == "Rectangle") {
        for (auto& component : rectangleList) {
            if (component.name == name) {
                return true;
            }
        }
    }
    return false;
}

Rectangle Object::getRectangle(std::string name) {
    for (auto& component : rectangleList) {
        if (component.name == name) {
            return component;
        }
    }
}