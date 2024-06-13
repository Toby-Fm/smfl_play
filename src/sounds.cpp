//
// Created by toby on 14.06.24.
//

#include "sounds.hpp"
#include <iostream>

// Play Sound (Fahrradklingel)
void sounds::fahrradklingelSound() {
    // SFML AUDIO
    if (!buffer.loadFromFile("assets/wav/Fahrradklingel.wav")) {
        std::cout << "Error loading sound" << std::endl;
    } else {
        std::cout << "Sound loaded" << std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
}