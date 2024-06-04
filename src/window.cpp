#include "./include/window.hpp"

// Constructor
Window::Window() {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Game", sf::Style::None | sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);
    //window.setVerticalSyncEnabled(true);

    draw.drawCircle();
    draw.drawRectangle();
}
// Run the game
void Window::run() {
    sf::Clock clock;
    std::deque<float> fpsValues;
    const int maxFPSValues = 144;

    while (window.isOpen()) {
        ProcessEvents();
        update();
        render();
        handleCollisions();
        renderFPS();

        // Berechne und aktualisiere die FPS
        sf::Time elapsed = clock.restart();
        float currentFPS = 1.0f / elapsed.asSeconds();

        // FPS-Werte aktualisieren
        fpsValues.push_back(currentFPS);
        if (fpsValues.size() > maxFPSValues) {
            fpsValues.pop_front();
        }

        // Durchschnittliche FPS berechnen
        float averageFPS = 0.0f;
        for (float value : fpsValues) {
            averageFPS += value;
        }
        averageFPS /= fpsValues.size();

        // Output FPS to console
        //std::cout << "FPS: " << averageFPS << std::endl;
    }
}

void Window::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
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
        Cmovement.y -= 20.f;
    }
    if (movingDownCricle) {
        Cmovement.y += 20.f;
    }
    if (movingLeftCricle) {
        Cmovement.x -= 20.f;
    }
    if (movingRightCricle) {
        Cmovement.x += 20.f;
    }
    draw.getCircle().move(Cmovement);

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
    window.clear(sf::Color::Transparent);
}

// Zeichnet die Formen
void Window::drawObjectsOnScreen() {
    window.draw(draw.getCircle());
    window.draw(draw.getRectangle());
    drawText();
}

// Zeichnet den Text
void Window::drawText() {
    window.draw(draw.getText());
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

void Window::renderFPS() {
    return;
};

// Handle player input
void Window::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        movingUpCricle = isPressed;
        //std::cout << "W" << std::endl;
    };
    if (key == sf::Keyboard::S) {
        movingDownCricle = isPressed;
        //std::cout << "S" << std::endl;
    };
    if (key == sf::Keyboard::A) {
        movingLeftCricle = isPressed;
        //std::cout << "A" << std::endl;
    };
    if (key == sf::Keyboard::D) {
        movingRightCricle = isPressed;
        //std::cout << "D" << std::endl;
    };
    if (key == sf::Keyboard::Up) {
        movingUpRec = isPressed;
        //std::cout << "Up" << std::endl;
    };
    if (key == sf::Keyboard::Down) {
        movingDownRec = isPressed;
        //std::cout << "Down" << std::endl;
    };
    if (key == sf::Keyboard::Left) {
        movingLeftRec = isPressed;
        //std::cout << "Left" << std::endl;
    };
    if (key == sf::Keyboard::Right) {
        movingRightRec = isPressed;
        //std::cout << "Right" << std::endl;
    };
    if (key == sf::Keyboard::Escape) {
        destroy();
    }
}

void Window::handleCollisions() {
    // Finde Screen resolution für Kollision
    int windowHeight = window.getSize().y; // Höhe des Fensters
    int windowWidth = window.getSize().x; // Breite des Fensters

    /* Collision detection */
    // Für Rectangle
    /* Linker Rand */
    if (draw.getRectangle().getPosition().x < 0) {
        draw.getRectangle().setPosition(0, draw.getRectangle().getPosition().y);
        std::cout << "Rectangle hat den linken Rand berührt!" << std::endl;
    };
    /* Rechter Rand */
    if (draw.getRectangle().getPosition().x + draw.getRectangle().getSize().x > windowWidth) {
        draw.getRectangle().setPosition(windowWidth - draw.getRectangle().getSize().x, draw.getRectangle().getPosition().y);
        std::cout << "Rectangle hat den rechten Rand berührt!" << std::endl;
    };
    /* Oberen Rand */
    if (draw.getRectangle().getPosition().y < 0) {
        draw.getRectangle().setPosition(draw.getRectangle().getPosition().x, 0);
        std::cout << "Rectangle hat den oberen Rand berührt!" << std::endl;
    };
    /* Unteren Rand */
    if (draw.getRectangle().getPosition().y + draw.getRectangle().getSize().y > windowHeight) {
        draw.getRectangle().setPosition(draw.getRectangle().getPosition().x, windowHeight - draw.getRectangle().getSize().y);
        std::cout << "Rectangle hat den unteren Rand berührt!" << std::endl;
    };

    // Für Circle
    /* Linker Rand */
    if (draw.getCircle().getPosition().x < 0) {
        draw.getCircle().setPosition(0, draw.getCircle().getPosition().y);
        std::cout << "Circle hat den linken Rand berührt!" << std::endl;
    };
    /* Rechter Rand */
    if (draw.getCircle().getPosition().x + draw.getCircle().getRadius() * 2 > windowWidth) {
        draw.getCircle().setPosition(windowWidth - draw.getCircle().getRadius() * 2, draw.getCircle().getPosition().y);
        std::cout << "Circle hat den rechten Rand berührt!" << std::endl;
    };
    /* Oberen Rand */
    if (draw.getCircle().getPosition().y < 0) {
        draw.getCircle().setPosition(draw.getCircle().getPosition().x, 0);
        std::cout << "Circle hat den oberen Rand berührt!" << std::endl;
    };
    /* Unteren Rand */
    if (draw.getCircle().getPosition().y + draw.getCircle().getRadius() * 2 > windowHeight) {
        draw.getCircle().setPosition(draw.getCircle().getPosition().x, windowHeight - draw.getCircle().getRadius() * 2);
        std::cout << "Circle hat den unteren Rand berührt!" << std::endl;
    };

    // Kollision zwischen Circle und Rectangle erkennen und blockieren
    if (draw.getCircle().getGlobalBounds().intersects(draw.getRectangle().getGlobalBounds())) {
        sf::FloatRect circleBounds = draw.getCircle().getGlobalBounds();
        sf::FloatRect rectBounds = draw.getRectangle().getGlobalBounds();
        float circleRadius = draw.getCircle().getRadius();

        sf::Vector2f circlePosition = draw.getCircle().getPosition();
        sf::Vector2f rectanglePosition = draw.getRectangle().getPosition();
        sf::Vector2f rectangleSize = sf::Vector2f(rectBounds.width, rectBounds.height);

        float leftRect = rectanglePosition.x;
        float rightRect = rectanglePosition.x + rectangleSize.x;
        float topRect = rectanglePosition.y;
        float bottomRect = rectanglePosition.y + rectangleSize.y;

        float leftCircle = circlePosition.x - circleRadius;
        float rightCircle = circlePosition.x + circleRadius;
        float topCircle = circlePosition.y - circleRadius;
        float bottomCircle = circlePosition.y + circleRadius;

        if (circleBounds.left < rectBounds.left && circleBounds.left + circleBounds.width > rectBounds.left) {
            // Kreis kommt von links
            draw.getCircle().setPosition(rectBounds.left - circleRadius, draw.getCircle().getPosition().y);
        }
        else if (circleBounds.left + circleBounds.width > rectBounds.left + rectBounds.width && circleBounds.left < rectBounds.left + rectBounds.width) {
            // Kreis kommt von rechts
            draw.getCircle().setPosition(rectBounds.left + rectBounds.width + circleRadius, draw.getCircle().getPosition().y);
        }
        if (bottomCircle > topRect && topCircle < topRect) {
            // Kreis kommt von oben
            draw.getCircle().setPosition(circlePosition.x, topRect - circleRadius);
        }
        if (topCircle < bottomRect && bottomCircle > bottomRect) {
            // Kreis kommt von unten
            draw.getCircle().setPosition(circlePosition.x, bottomRect + circleRadius);
        }
        std::cout << "Kollision zwischen Rec und Circle erkannt!" << std::endl;
    }
}