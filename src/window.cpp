#include "./include/window.hpp"

// Constructor
Window::Window() {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Hello, World!");
}

// Run the game
void Window::run() {
    while (window.isOpen()) 
    {
        /*
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        */
        clear();
        draw();
        keyInput();
        display();
    }
}

// Löscht den Bildschirm
void Window::clear() {
    window.clear(sf::Color::Black);
}

// Zeichnet die Formen
void Window::draw() {
    drawCircle();
    drawRectangles();
    drawText();
}


void Window::display() {
    window.display();
}

// Schließt das fenster
void Window::destroy() {
    window.close();
}

// Key inputs
void Window::keyInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "Up" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        std::cout << "Down" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "Left" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::cout << "Space" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // Close window
        destroy();
    }
}