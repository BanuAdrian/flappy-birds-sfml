//
// Created by Adrian on 17-Nov-23.
//

#include "../headers/BlueBird.hpp"
#include <iostream>

BlueBird::BlueBird(int localScoreNeeded) : Bird(localScoreNeeded) {
    if (!birdTextureUpFlap.loadFromFile("../assets/blue-bird/bluebird-upflap.png")) {
        throw TextureLoadException();
    }
    if (!birdTextureMidFlap.loadFromFile("../assets/blue-bird/bluebird-midflap.png")) {
        throw TextureLoadException();
    }
    if (!birdTextureDownFlap.loadFromFile("../assets/blue-bird/bluebird-downflap.png")) {
        throw TextureLoadException();
    }
    birdSprite.setTexture(birdTextureMidFlap);
    if (!font.loadFromFile("../assets/font.ttf")) {
        throw FontLoadException();
    }
    transparenceReady = false;
    transparentNow = false;
    transparenceHandlingClock = std::make_shared<sf::Clock>();
    transparenceText.setFont(font);
    transparenceText.setCharacterSize(10);
    transparenceText.setOutlineColor(sf::Color::Black);
    transparenceText.setOutlineThickness(1);
    transparenceText.setFillColor(sf::Color::White);
    transparenceText.setPosition(300, 15);
}

//BlueBird* BlueBird::clone() const {
//    return new BlueBird(*this);
//}

int BlueBird::getScoreNeeded() const {
    return scoreNeeded;
}

int BlueBird::getLives() const {
    return 0;
}

void BlueBird::revive() {
    throw WrongFuncException();
}

void BlueBird::handleCollision() {
    this->reset();
    transparenceReady = false;
    transparentNow = false;
    transparenceHandlingClock->restart();
    birdSprite.setColor(sf::Color(255, 255, 255, 255));
}

void BlueBird::loadTransparence() {
    if (!transparentNow && transparenceHandlingClock->getElapsedTime().asSeconds() > 5) {
        transparenceReady = true;
    } else if (transparentNow && transparenceHandlingClock->getElapsedTime().asSeconds() > 2) {
        birdSprite.setColor(sf::Color(255, 255, 255, 255));
        transparenceHandlingClock->restart();
        transparentNow = false;
        transparenceReady = false;
    }
}

void BlueBird::displaySpecialText(sf::RenderWindow &window) {
    loadTransparence();
    std::string transparenceString = "Transparence: ";
    if (transparenceReady) {
        transparenceString += "press F to activate";
        transparenceText.setPosition(235, 15);
    } else {
        transparenceString += "loading...";
        transparenceText.setPosition(300, 15);
    }
    transparenceText.setString(transparenceString);
    transparenceText.setLetterSpacing(1.5);
    window.draw(transparenceText);
}

void BlueBird::specialAbility() {
    if (transparenceReady && !transparentNow) {
        birdSprite.setColor(sf::Color(255, 255, 255, 100));
        transparenceHandlingClock->restart();
        transparentNow = true;
    }
}

bool BlueBird::isTransparent() const {
    return transparentNow;
}

void BlueBird::loadLives() {
    throw WrongFuncException();
}

BlueBird::~BlueBird() = default;