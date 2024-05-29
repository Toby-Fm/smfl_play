#include "./include/window.hpp"

// Constructor
Window::Window() {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Hello, World!");
    window.setFramerateLimit(144);
    draw.drawCircle();
    draw.drawRectangle();
}

// Run the game
void Window::run() {
    sf::Clock clock;
    while (window.isOpen())
    {
        ProcessEvents();
        update();
        render();
        // Calculate FPS
        sf::Time elapsed = clock.restart();
        float fps = 1.0f / elapsed.asSeconds();
        // Output FPS to console
        std::cout << "FPS: " << fps << std::endl;
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
    sf::Vector2f Cmovement(0.f, 0.f);
    if (movingUpCricle) {
        Cmovement.y -= 30.f;
    }
    if (movingDownCricle) {
        Cmovement.y += 30.f;
    }
    if (movingLeftCricle) {
        Cmovement.x -= 30.f;
    }
    if (movingRightCricle) {
        Cmovement.x += 30.f;
    }
    draw.getCircle().move(Cmovement);
    //std::cout << "Circle Position: (" << draw.getCircle().getPosition().x << ", " << draw.getCircle().getPosition().y << ")" << std::endl;

    sf::Vector2f Rmovement(0.f, 0.f);
    if (movingUpRec) {
        Rmovement.y -= 20.f;
    }
    if (movingDownRec) {
        Rmovement.y += 20.f;
    }
    if (movingLeftRec) {
        Rmovement.x -= 20.f;
    }
    if (movingRightRec) {
        Rmovement.x += 20.f;
    }
    draw.getRectangle().move(Rmovement);
}

// Löscht den Bildschirm
void Window::clear() {
    window.clear(sf::Color::Black);
}

// Zeichnet die Formen
void Window::drawObjectsOnScreen() {
    window.draw(draw.getCircle());
    window.draw(draw.getRectangle());
    drawText();
    //drawFps();
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
        movingUpCricle = isPressed;
        std::cout << "W" << std::endl;
    };
    if (key == sf::Keyboard::S) {
        movingDownCricle = isPressed;
        std::cout << "S" << std::endl;
    };
    if (key == sf::Keyboard::A) {
        movingLeftCricle = isPressed;
        std::cout << "A" << std::endl;
    };
    if (key == sf::Keyboard::D) {
        movingRightCricle = isPressed;
        std::cout << "D" << std::endl;
    };
    if (key == sf::Keyboard::Up) {
        movingUpRec = isPressed;
        std::cout << "Up" << std::endl;
    };
    if (key == sf::Keyboard::Down) {
        movingDownRec = isPressed;
        std::cout << "Down" << std::endl;
    };
    if (key == sf::Keyboard::Left) {
        movingLeftRec = isPressed;
        std::cout << "Left" << std::endl;
    };
    if (key == sf::Keyboard::Right) {
        movingRightRec = isPressed;
        std::cout << "Right" << std::endl;
    };
    if (key == sf::Keyboard::Escape) {
        destroy();
    }
}