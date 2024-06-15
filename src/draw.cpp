#include "draw.hpp"

void Draw::drawCircle()
{
    // Erstelle einen Kreis
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

void Draw::drawTriangle()
{
    // Erstelle ein Dreieck
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(150.f, 0.f));
    triangle.setPoint(2, sf::Vector2f(75.f, 150.f));
    triangle.setFillColor(sf::Color::Yellow);
    triangle.setOutlineThickness(5.f);
    triangle.setOutlineColor(sf::Color::Blue);
    // Setze die Position des Dreiecks
    triangle.setPosition(400.f, 400.f);
}
/*
void Draw::drawText()
{
    // Erstelle eine Schrift
    if (!font.loadFromFile("assets/fonts/tahoma.ttf"))
    {
        std::cerr << "Font konnte nicht geladen werden" << std::endl;
        exit(1);
    }

    // Text schreiben
    text.setString("IDK"); // Setze den Text
    text.setCharacterSize(60); // Setze die Schriftgröße
    text.setFillColor(sf::Color::Red); // Setze die Schriftfarbe
    text.setFont(font); // Setze die Schriftart
    text.setStyle(sf::Text::Underlined);
}
*/