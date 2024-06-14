#pragma once

#include "draw.hpp"
#include "sounds.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <deque>
#include <cstdlib>
#include <ctime>

#define WINDOW_HEIGHT 1920
#define WINDOW_WIDTH 1080

// Klasse für die Tastatureingaben
enum class Key {
    Up, Down, Left, Right, Space, Escape,
    W, A, S, D, F
};

class Window {
public:
    Window();
    void run();

private:
    Draw draw;
    sounds sound;

    void drawCircle(); // Zeichnet den Kreis
    void drawRectangles(); // Zeichnet die Rechtecke
    void drawText(); // Zeichnet den Text

    void ProcessEvents();
    void update(); // Aktualisiert das Fenster
    void clear(); // Löscht den Bildschirm
    void drawGrid(); // Zeichnet das BG - Gitter
    void drawObjectsOnScreen(); // Zeichnet die Formen
    void destroy(); // Schließt das fenster
    void render();
    void renderFPS(); // Zeichnet die FPS

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed); // Key inputs
    void handleCollisions(); // Kollisionsabfrage

    sf::RenderWindow window;

    std::vector<sf::RectangleShape> gridCells;
    bool movingLeftCricle = false, movingRightCricle = false, movingUpCricle = false, movingDownCricle = false;
    bool movingLeftRec = false, movingRightRec = false, movingUpRec = false, movingDownRec = false;
};

// Funktion, die das zweite Fenster öffnet
void Window2(std::atomic<float>& fps, std::mutex& fpsMutex);
