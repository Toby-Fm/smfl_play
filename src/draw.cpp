#include "draw.hpp"

void Draw::drawCircle()
{
    // Erstelle einen cube
    circle.setRadius(40.f);
    circle.setFillColor(sf::Color::Magenta);
    circle.setOutlineThickness(5.f);
    circle.setOutlineColor(sf::Color::Blue);

    // Setze die Position des Kreises
    circle.setPosition(100.f, 100.f);
}

void Draw::drawRectangle()
{
    // Erstelle ein Rechteck
    rectangle.setSize(sf::Vector2f(200.f, 100.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineThickness(5.f);
    rectangle.setOutlineColor(sf::Color::Blue);

    // Setze die Position des Rechtecks
    rectangle.setPosition(600.f, 200.f);
}

void Draw::drawText()
{
    // Erstelle eine Schrift
    if (!font.loadFromFile("assets/fonts/tahoma.ttf"))
    {
        std::cerr << "Font konnte nicht geladen werde" << std::endl;
        exit(1);
    }

    // Text schreiben
    text.setString("Deine Mutter"); // Setze den Text
    text.setCharacterSize(60); // Setze die Schriftgröße
    text.setFillColor(sf::Color::Red); // Setze die Schriftfarbe
    text.setFont(font); // Setze die Schriftart
    text.setStyle(sf::Text::Underlined);

}