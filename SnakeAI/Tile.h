#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Tile : public sf::Transformable, public sf::Drawable
{
public:
	sf::RectangleShape* shape;
	Entity* content;
	sf::Vector2f size;
	Tile();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

