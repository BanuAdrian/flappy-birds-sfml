//
// Created by Adrian on 17-Nov-23.
//

#include "../headers/RedBird.hpp"
#include <iostream>

int RedBird::lives;

RedBird::RedBird(int localScoreNeededForNextBird) : Bird(localScoreNeededForNextBird) {
    if (!birdTextureUpFlap.loadFromFile("../assets/red-bird/redbird-upflap.png")) {
        throw TextureLoadException();
    }
    if (!birdTextureMidFlap.loadFromFile("../assets/red-bird/redbird-midflap.png")) {
        throw TextureLoadException();    }
    if (!birdTextureDownFlap.loadFromFile("../assets/red-bird/redbird-downflap.png")) {
        throw TextureLoadException();    }
    birdSprite.setTexture(birdTextureMidFlap);
    lives = 3;
    if (!font.loadFromFile("../assets/font.ttf")) {
        throw FontLoadException();    }
    livesText.setFont(font);
    livesText.setCharacterSize(15);
    livesText.setOutlineColor(sf::Color::Black);
    livesText.setOutlineThickness(1);
    livesText.setFillColor(sf::Color::White);
    livesText.setPosition(375, 10);
    livesGeneratingClock = std::make_shared<sf::Clock>();
}

//RedBird* RedBird::clone() const {
//    return new RedBird(*this);
//}

int RedBird::getScoreNeededForNextBird() const {
    return scoreNeededForNextBird;
}

int RedBird::getLives() const {
    return lives;
}

void RedBird::revive() {
//    posY = 300;
    position.setY(300);
    velocity = 0;
    lives--;
    rotationAngle = 0;
    birdSprite.setRotation(0);
    birdSprite.setPosition(position.getX(), position.getY());
//    birdSprite.setPosition(posX, posY);
    birdSprite.setTexture(birdTextureMidFlap);
}

void RedBird::handleCollision() {
    if (lives > 0)
        this->revive();
    else
        this->reset();
}

void RedBird::loadLives() {
    if (livesGeneratingClock->getElapsedTime().asSeconds() > 15) {
        if (lives < 3)
            lives++;
        livesGeneratingClock->restart();
    }
}

void RedBird::displaySpecialText(sf::RenderWindow &window) {
    loadLives();
    std::string livesString = "Lives: " + std::to_string(lives);
    livesText.setString(livesString);
    livesText.setLetterSpacing(1.5);
    window.draw(livesText);
}

void RedBird::specialAbility() {}

void RedBird::loadTransparence() {
    throw WrongFuncException();
}

bool RedBird::isTransparent() const {
    return false;
}

RedBird::~RedBird() = default;