#include "./include/window.hpp"
#include "./include/draw.hpp"

// Constructor
Window::Window() {
    window.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Hello, World!");
    /*
    // Erstelle eine Schrift
    if (!font.loadFromFile("assets/fonts/tahoma.ttf"))
    {
        std::cerr << "Font konnte nicht geladen werde" << std::endl;
        exit(1);
    }

    /*
    // Text schreiben
    text.setString("Deine Mutter"); // Setze den Text
    text.setCharacterSize(60); // Setze die Schriftgröße
    text.setFillColor(sf::Color::Red); // Setze die Schriftfarbe
    text.setFont(font); // Setze die Schriftart
    text.setStyle(sf::Text::Underlined);
    */
}

// Run the game
void Window::run() {
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        clear();
        draw();
        drawCubes();
        drawRectangles();
        display();
    }
}

void Window::clear() {
    window.clear(sf::Color::Black);
}

void Window::draw() {
    window.draw(text);
    window.draw(shape);
}

void Window::display() {
    window.display();
}
