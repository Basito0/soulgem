#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Rectangle.h"
#include "Object.h"


//global object list
static std::vector<Object> object_list;

//debug text objects

//renders objects in scene
void RenderObjectList(sf::RenderWindow* window) {
    for (auto& gameObject : object_list) {
        if (gameObject.hasComponent("Rectangle") == true) {
            for (auto& rect : gameObject.rectangleList) {
                window->draw(rect.getRect());
            }
        }
    }
}

void createRect(sf::Vector2f v, std::string name) {
    //spawns a square in the same position of the click event and adds it to gameobject

    Object object;
    object.setPosition(v);
    object.name = "rect" + std::to_string(object_list.size());

    object.addComponent("Rectangle", name);
    Rectangle local_rect = object.getRectangle(name);
    local_rect.setFillColor(sf::Color::Green);

    object_list.push_back(object);
}

int main()
{
    //window set up
    sf::RenderWindow window(sf::VideoMode(800, 600), "SoulGem Engine");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased) {
                int mouse_pressed_x = event.mouseButton.x;
                int mouse_pressed_y = event.mouseButton.y;
                sf::Vector2f v = sf::Vector2f(mouse_pressed_x, mouse_pressed_y);

                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::string nombre = "rect" + std::to_string(object_list.size());
                    createRect(v, nombre);
                }
            }
        }
        
        RenderObjectList(&window);
        window.display();
    }

    return 0;
}