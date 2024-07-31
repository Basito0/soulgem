#include "Rectangle.h"
#include <string>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

Rectangle::Rectangle(sf::Transformable tr) {
	sf::RectangleShape initial_rect(sf::Vector2f(100, 100));
	initial_rect.setFillColor(sf::Color::Magenta);
	initial_rect.setPosition(tr.getPosition());
	rect = initial_rect;
}

sf::Color Rectangle::getFillColor() {
	return rect.getFillColor();
}

sf::Vector2f Rectangle::getPosition() {
	return rect.getPosition();
}

sf::RectangleShape Rectangle::getRect() {
	return rect;
}

void Rectangle::setFillColor(sf::Color newcolor) {
	rect.setFillColor(newcolor);
}

void Rectangle::setName(std::string s) {
	name = s;
}
void Rectangle::setPosition(sf::Vector2f p) {
	rect.setPosition(p);
}

void Rectangle::setRect(sf::RectangleShape r) {
	rect = r;
}

