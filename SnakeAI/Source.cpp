#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "EmptyTile.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setTitle("Snake AI");

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));

    Grid* grid = new Grid(sf::Vector2f(200, 200), sf::Vector2f(10, 10), sf::Vector2f(20, 20), sf::Vector2f(2, 2));
    grid->setPosition(sf::Vector2f(100, 100));

    EmptyTile* test = new EmptyTile(sf::Vector2f(100, 100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(*grid);
        window.display();
    }

    return 0;
}