#include "EmptyTile.h"

EmptyTile::EmptyTile(sf::Vector2f size) : Tile()
{
	shape = new sf::RectangleShape(size);
	shape->setFillColor(sf::Color(0, 255, 255));
	this->size = size;
}

EmptyTile::~EmptyTile() {
	delete shape;
}

void EmptyTile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	Tile::draw(target, states);
}
