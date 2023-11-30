#pragma once
#include <SFML/Graphics.hpp>
#include "EmptyTile.h"

class Grid : public sf::Transformable, public sf::Drawable
{
public:
    sf::Vector2f grid_size;
    sf::Vector2f padding;
    sf::Vector2f grid_cells_count;
    sf::Vector2f tile_gap;
    sf::RectangleShape* grid_background;
    Tile*** tiles;

    Grid(sf::Vector2f grid_size, sf::Vector2f grid_cells_count, sf::Vector2f padding, sf::Vector2f tile_gap);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Vector2f tile_size;
};

