#include "./include/window.hpp"

// Constructor
Window::Window() {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Hello, World!");
    window.setFramerateLimit(60);
    draw.drawCircle();
}

// Run the game
void Window::run() {
    while (window.isOpen()) 
    {
        ProcessEvents();
        update();
        render();
    }
}

void Window::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                window.close();
                break;
        }
    }
}

// Aktualisiert das Fenster
void Window::update() {
    sf::Vector2f movement(0.f, 0.f);
    if (movingUp) {
        movement.y -= 20.f;
    }
    if (movingDown) {
        movement.y += 20.f;
    }
    if (movingLeft) {
        movement.x -= 20.f;
    }
    if (movingRight) {
        movement.x += 20.f;
    }
    draw.getCircle().move(movement);
    std::cout << "Circle Position: (" << draw.getCircle().getPosition().x << ", " << draw.getCircle().getPosition().y << ")" << std::endl;
}

// Löscht den Bildschirm
void Window::clear() {
    window.clear(sf::Color::Black);
}

// Zeichnet die Formen
void Window::drawObjectsOnScreen() {
    window.draw(draw.getCircle());
    //drawCircle();
    //drawRectangles();
    //drawText();
}

// Schließt das fenster
void Window::destroy() {
    std::cout << "Fenster wird geschlossen" << std::endl;
    window.close();
}

// Rendert das Fenster
void Window::render() {
    clear();
    drawObjectsOnScreen();
    window.display();
}

// Handle player input
void Window::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        movingUp = isPressed;
        std::cout << "W" << std::endl;
    };
    if (key == sf::Keyboard::S) {
        movingDown = isPressed;
        std::cout << "S" << std::endl;
    };
    if (key == sf::Keyboard::A) {
        movingLeft = isPressed;
        std::cout << "A" << std::endl;
    };
    if (key == sf::Keyboard::D) {
        movingRight = isPressed;
        std::cout << "D" << std::endl;
    };
    if (key == sf::Keyboard::Escape) {
        destroy();
    }
}