#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Draw {
public:
    void drawCircle();
    sf::CircleShape& getCircle() { return circle; }

    void drawRectangle();
    sf::RectangleShape& getRectangle() { return rectangle; }

    void drawText();
    sf::Text getText() { return text; }
private:
    sf::RenderWindow window;
    sf::CircleShape circle;
    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;
};