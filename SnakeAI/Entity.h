#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable, public sf::Drawable
{
	sf::RectangleShape* shape;
	sf::Vector2f grid_pos;
	sf::Vector2f size;
	Entity();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

