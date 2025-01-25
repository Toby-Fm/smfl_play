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

// Hit Sound
void sounds::hitSound() {
    // SFML AUDIO
    if (!buffer.loadFromFile("assets/wav/hitSound.wav")) {
        std::cout << "Error loading sound" << std::endl;
    } else {
        std::cout << "Sound loaded" << std::endl;
    }
    sound.setBuffer(buffer);
    sound.setVolume(10);
    sound.play();
	//sound.setLoop(true);
}

// Hintergrund Musik
void sounds::backgroundMusic() {
    // SFML AUDIO
    if (!buffer.loadFromFile("assets/wav/bgSound.wav")) {
        std::cout << "Error loading sound" << std::endl;
    } else {
        std::cout << "Sound loaded" << std::endl;
    }
    sound.setBuffer(buffer);
    sound.setVolume(10);
    sound.play();
}