#include "./include/window.hpp"

// Constructor
Window::Window() : window2FPS(0) {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Hello, World!");
    window.setFramerateLimit(144);
    draw.drawCircle();
    draw.drawRectangle();
}

// Funktion, die das zweite Fenster öffnet
void Window2(std::atomic<float>& fps, std::mutex& fpsMutex) {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Window 2");
    sf::Clock clock;

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/tahoma.ttf")) {
        std::cerr << "Font konnte nicht geladen werden" << std::endl;
        return;
    }

    sf::Text fpsText;
    fpsText.setFont(font);
    fpsText.setCharacterSize(24);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.f, 10.f);

    std::deque<float> fpsValues;
    const int maxFPSValues = 100;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Berechne und aktualisiere die FPS
        sf::Time elapsed = clock.restart();
        float currentFPS = 1.0f / elapsed.asSeconds();
        {
            std::lock_guard<std::mutex> lock(fpsMutex); // Sperre den Mutex, bevor die FPS aktualisiert wird
            fps = currentFPS;
        }

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

        fpsText.setString("FPS: " + std::to_string(averageFPS));

        window.clear(sf::Color::Black);
        window.draw(fpsText);
        window.display();
    }
}
// End Window 2
// Run the game
void Window::run() {
    sf::Clock clock;
    std::deque<float> fpsValues;
    const int maxFPSValues = 100;

    while (window.isOpen()) {
        ProcessEvents();
        update();
        render();
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
        std::cout << "FPS: " << averageFPS << std::endl;
    }

    if (window2Thread.joinable()) {
        window2Thread.join();
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
    drawFPS();
}

// Zeichnet den Text
void Window::drawText() {
    window.draw(draw.getText());
}

// Zeichnet die FPS von Fenster 2
void Window::drawFPS() {
    std::lock_guard<std::mutex> lock(fpsMutex); // Sperre den Mutex, bevor die FPS gelesen wird
    float fps = window2FPS;
    sf::Text fpsText;
    fpsText.setFont(draw.getFont()); // Verwende die gleiche Schriftart wie für den Text
    fpsText.setString("Window 2 FPS: " + std::to_string(fps));
    fpsText.setCharacterSize(24); // Setze die Schriftgröße
    fpsText.setFillColor(sf::Color::White); // Setze die Schriftfarbe
    fpsText.setPosition(10.f, 50.f); // Setze die Position des Textes
    window.draw(fpsText);
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
    if (key == sf::Keyboard::Space) {
        if (!window2Thread.joinable()) {
            window2Thread = std::thread(Window2, std::ref(window2FPS), std::ref(fpsMutex));
        }
    };
    if (key == sf::Keyboard::Escape) {
        destroy();
    }
}
