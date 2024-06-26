#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Draw {
public:
    void drawCircle();
    sf::CircleShape& getCircle() { return circle; }

    void drawRectangle();
    sf::RectangleShape& getRectangle() { return rectangle; }

    void drawTriangle();
    sf::ConvexShape& getTriangle() { return triangle; }
    /*
    void drawText();
    sf::Text& getText() { return text; } // Ändere die Rückgabe zu einem Referenztyp
    sf::Font& getFont() { return font; } // Füge eine Methode hinzu, um die Schriftart zurückzugeben
    */
private:

    sf::CircleShape circle;
    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;
    sf::ConvexShape triangle;
};
