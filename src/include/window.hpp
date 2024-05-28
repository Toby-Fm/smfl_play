#pragma once

#include "draw.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_HEIGHT 1920
#define WINDOW_WIDTH 1080

class Window {
public:
    Window();
    void run();
    void drawCubes() {
        Draw draw;
        draw.drawCube();
        window.draw(draw.getShape()); // Verwenden der getShape Methode
    }
    void drawRectangles() {
        Draw draw;
        draw.drawRectangle();
        window.draw(draw.getRectangle()); // Verwenden der getRectangle Methode
    }
private:
    void clear();
    void draw();
    void display();

    sf::RenderWindow window;
    sf::CircleShape shape;
    sf::Font font;
    sf::Text text;
};
