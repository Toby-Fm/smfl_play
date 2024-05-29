#pragma once

#include "draw.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <deque>

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
    void drawCircle(); // Zeichnet den Kreis
    void drawRectangles(); // Zeichnet die Rechtecke
    void drawText(); // Zeichnet den Text
    void drawFPS(); // Zeichnet die FPS von Fenster 2
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
    bool movingLeftCricle = false, movingRightCricle = false, movingUpCricle = false, movingDownCricle = false;
    bool movingLeftRec = false, movingRightRec = false, movingUpRec = false, movingDownRec = false;
    std::thread window2Thread;

    std::atomic<float> window2FPS; // Gemeinsame Variable für FPS von Fenster 2
    std::mutex fpsMutex; // Mutex für den Zugriff auf die FPS-Variable

    std::deque<float> fpsValues; // Liste der letzten FPS-Werte
    static const int maxFPSValues = 100; // Maximale Anzahl an FPS-Werten für den Durchschnitt
};

// Funktion, die das zweite Fenster öffnet
void Window2(std::atomic<float>& fps, std::mutex& fpsMutex);
