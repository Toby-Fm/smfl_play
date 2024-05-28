#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, World!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    
    // Setze den Kreis in die Mitte des Fensters
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f shapePosition;
    shapePosition.x = windowSize.x / 2 - shape.getRadius();
    shapePosition.y = windowSize.y / 2 - shape.getRadius();
    shape.setPosition(shapePosition);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
