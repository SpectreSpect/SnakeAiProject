#include "Entity.h"

Entity::Entity() {
	shape = new sf::RectangleShape(size);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*shape, states);
}
