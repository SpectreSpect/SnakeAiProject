#pragma once
#include "Tile.h"

class EmptyTile : public Tile
{
public:
	EmptyTile(sf::Vector2f size);
	~EmptyTile();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

