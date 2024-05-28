#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Erstelle ein Fentser
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, World!");
    // Erstelle einen Kreis
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Magenta);
    
    // Setze den Kreis in die Mitte des Fensters
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f shapePosition;
    shapePosition.x = windowSize.x / 2 - shape.getRadius();
    shapePosition.y = windowSize.y / 2 - shape.getRadius();
    shape.setPosition(shapePosition);
    
    // Erstelle eine Schrift
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/tahoma.ttf"))
    {
        std::cerr << "Konnte Font nicht laden" << std::endl;
        return 1;
    }

    // Text schreiben
    sf::Text text;
    text.setString("Hello, World!"); // Setze den Text
    text.setCharacterSize(24); // Setze die Schriftgröße
    text.setFillColor(sf::Color::Red); // Setze die Schriftfarbe
    text.setFont(font); // Setze die Schriftart
    text.setStyle(sf::Text::Underlined);

    // Schleife, die so lange läuft, bis das Fenster geschlossen wird
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
        
        // Clear the window with a black color
        window.clear(sf::Color::Black);
        window.draw(text);
        window.draw(shape);
        window.display();
    }

    return 0;
}
