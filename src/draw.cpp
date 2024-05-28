#include "draw.hpp"

void Draw::drawCube()
{
    // Erstelle einen cube
    shape.setRadius(200.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));
}

void Draw::drawRectangle()
{
    // Erstelle ein Rechteck
    rectangle.setSize(sf::Vector2f(100.f, 50.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineThickness(5.f);
    rectangle.setOutlineColor(sf::Color::Blue);
}
