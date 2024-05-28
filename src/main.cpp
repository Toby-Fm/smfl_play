#include "./include/main.hpp"
#include "./include/window.hpp"
#include "./include/draw.hpp"

int main() {
    // Erstelle ein Fenster
    Window window;

    // Schleife, die so lange läuft, bis das Fenster geschlossen wird
    window.run();

    return 0;
}
