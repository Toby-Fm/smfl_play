#pragma once

#include "draw.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_HEIGHT 1400
#define WINDOW_WIDTH 800

// Klasse für die Tastatureingaben
enum class Key {
    Up,
    Down,
    Left,
    Right,
    Space,
    Escape,
    W,
    A,
    S,
    D
};

class Window {
public:
    Window();
    void run();

private:
    Draw draw;
    void drawCircle();
    void drawRectangles() { // Zeichnet das Rechteck
        draw.drawRectangle();
        window.draw(draw.getRectangle());
    }
    void drawText() { // Zeichnet den Text
        draw.drawText();
        window.draw(draw.getText());
    }

private:
    void ProcessEvents();
    void update(); // Aktualisiert das Fenster
    void clear(); // Löscht den Bildschirm
    void drawObjectsOnScreen(); // Zeichnet die Formen
    void destroy(); // Schließt das fenster
    void render();

    // Key inputs
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::RenderWindow window;
    bool movingLeft = false, movingRight = false, movingUp = false, movingDown = false;
    //bool movingLeft, movingRight, movingUp, movingDown;
};
