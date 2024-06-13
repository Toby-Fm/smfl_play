//
// Created by toby on 14.06.24.
//

#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SFML/Audio.hpp>

class sounds {
public:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    void fahrradklingelSound();
    void hitSound();
    void backgroundMusic();
};



#endif //SOUNDS_HPP
