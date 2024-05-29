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
    Escape
};

class Window {
public:
    Window();
    void run();
    void drawCircle() { // Zeichnet den Kreis
        Draw draw;
        draw.drawCircle();
        window.draw(draw.getCircle()); // Verwenden der getShape Methode
    }
    void drawRectangles() { // Zeichnet das Rechteck
        Draw draw;
        draw.drawRectangle();
        window.draw(draw.getRectangle()); // Verwenden der getRectangle Methode
    }
    void drawText() { // Zeichnet den Text
        Draw draw;
        draw.drawText();
        window.draw(draw.getText()); // Verwenden der getText Methode
    }
private:
    void clear(); // Löscht den Bildschirm
    void draw(); // Zeichnet die Formen
    void display(); // Zeigt die Formen an
    void destroy(); // Schließt das fenster

    // Key inputs
    void keyInput();

    sf::RenderWindow window;
};
