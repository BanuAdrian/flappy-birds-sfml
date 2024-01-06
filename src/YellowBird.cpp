//
// Created by Adrian on 11-Nov-23.
//

#include "../headers/YellowBird.hpp"
#include <iostream>

YellowBird::YellowBird(int localScoreNeededForNextBird) : Bird(localScoreNeededForNextBird) {
    if (!birdTextureUpFlap.loadFromFile("../assets/yellow-bird/yellowbird-upflap.png")) {
        throw TextureLoadException();
    }
    if (!birdTextureMidFlap.loadFromFile("../assets/yellow-bird/yellowbird-midflap.png")) {
        throw TextureLoadException();
    }
    if (!birdTextureDownFlap.loadFromFile("../assets/yellow-bird/yellowbird-downflap.png")) {
        throw TextureLoadException();
    }
    birdSprite.setTexture(birdTextureMidFlap);

}

//YellowBird* YellowBird::clone() const {
//    return new YellowBird(*this);
//}

int YellowBird::getScoreNeededForNextBird() const {
    return scoreNeededForNextBird;
}

int YellowBird::getLives() const {
    return 0;
}

void YellowBird::handleCollision() {
    this->reset();
}

void YellowBird::displaySpecialText([[maybe_unused]]sf::RenderWindow &window) {}
void YellowBird::specialAbility() {}

void YellowBird::revive() {
    throw WrongFuncException();
}

void YellowBird::loadTransparence() {
    throw WrongFuncException();
}

bool YellowBird::isTransparent() const {
    return false;
}

void YellowBird::loadLives() {
    throw WrongFuncException();
}

YellowBird::~YellowBird() = default;