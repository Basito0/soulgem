#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Rectangle{
	public:
		std::string name;

		Rectangle(sf::Transformable);

		sf::Color getFillColor();
		sf::Vector2f getPosition();
		sf::RectangleShape getRect();
		void setFillColor(sf::Color);
		void setName(std::string);
		void setPosition(sf::Vector2f);
		void setRect(sf::RectangleShape);
	private:
		sf::RectangleShape rect;
};
