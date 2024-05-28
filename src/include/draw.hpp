#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Draw {
public:
    void drawCube();
    sf::CircleShape getShape() { return shape; }

    void drawRectangle();
    sf::RectangleShape getRectangle() { return rectangle; }
private:
    sf::RenderWindow window;
    sf::CircleShape shape;
    sf::RectangleShape rectangle;
};