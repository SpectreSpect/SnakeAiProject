#include "Grid.h"

Grid::Grid(sf::Vector2f grid_size, sf::Vector2f grid_cells_count, sf::Vector2f padding, sf::Vector2f tile_gap)
{
	this->grid_size = grid_size;
	this->padding = padding;
	this->grid_cells_count = grid_cells_count;
	tile_size.x = ((this->grid_size.x - padding.x * 2) - tile_gap.x * (grid_cells_count.x - 1)) / grid_cells_count.x;
	tile_size.y = ((this->grid_size.y - padding.y * 2) - tile_gap.y * (grid_cells_count.y - 1)) / grid_cells_count.y;

	grid_background = new sf::RectangleShape(grid_size);
	grid_background->setFillColor(sf::Color(0, 0, 255, 0));
	grid_background->setOutlineColor(sf::Color(255, 255, 255));
	grid_background->setOutlineThickness(1);
	tiles = new Tile**[grid_cells_count.x];

	for (int x = 0; x < grid_cells_count.x; x++)
	{ 
		tiles[x] = new Tile*[grid_cells_count.y];
		for (int y = 0; y < grid_cells_count.y; y++)
		{
			tiles[x][y] = new EmptyTile(tile_size);
			float size_x = padding.x + (tile_size.x + tile_gap.x) * x;
			float size_y = padding.y + (tile_size.y + tile_gap.y) * y;
			tiles[x][y]->setPosition(sf::Vector2f(size_x, size_y));
		}	
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(*grid_background, states);

	for (int y = 0; y < grid_cells_count.y; y++)
		for (int x = 0; x < grid_cells_count.x; x++)
		{
			target.draw(*tiles[x][y], states);
		}
}


