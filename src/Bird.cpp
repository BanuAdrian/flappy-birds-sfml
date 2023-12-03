//
// Created by Adrian on 17-Nov-23.
//

#include "../headers/Bird.hpp"
#include <iostream>

Bird::Bird(int localScoreNeeded) : scoreNeeded(localScoreNeeded) {
    posY = 300;
    posX = 190;
    velocity = 0;
    rotationAngle = 0;
    wingsAnimationGeneratingClock = std::make_shared<sf::Clock>();
    birdSprite.setOrigin(10, 10);
    birdSprite.setPosition(posX, posY);
    birdSprite.setScale(sf::Vector2f(1.7f, 1.75f));
}

void Bird::fly() {
    velocity = -425;
    rotationAngle = -35;
}

void Bird::fall(float elapsedTime) {
    velocity += elapsedTime * 1300;
    if (rotationAngle < -28)
        rotationAngle += elapsedTime * 20;
    else if (rotationAngle >= -28 && rotationAngle < 0)
        rotationAngle += elapsedTime * 75;
    else if (rotationAngle >= 0 && rotationAngle < 30)
        rotationAngle += elapsedTime * 300;
    else if (rotationAngle >= 30 && rotationAngle < 90)
        rotationAngle += elapsedTime * 700;
    birdSprite.setRotation(rotationAngle);
    posY += velocity * elapsedTime;
}

void Bird::update() {
    birdSprite.setPosition(posX, posY);
}

void Bird::animateWings(bool gameHasBegun) {
    static bool wingsState = 0;
    float secondsSinceLastWingAnimation;
    if (gameHasBegun == 1)
        secondsSinceLastWingAnimation = 0.1;
    else
        secondsSinceLastWingAnimation = 0.25;
    if (wingsAnimationGeneratingClock->getElapsedTime().asSeconds() > secondsSinceLastWingAnimation) {
        if (wingsState == 0) {
            birdSprite.setTexture(birdTextureUpFlap);
            wingsState = 1;
        }
        else {
            birdSprite.setTexture(birdTextureDownFlap);
            wingsState = 0;
        }
        wingsAnimationGeneratingClock->restart();
    }
}

void Bird::draw(sf::RenderWindow &window) {
    window.draw(birdSprite);
}
void Bird::reset() {
    posY = 300;
    velocity = 0;
    birdSprite.setRotation(0);
    rotationAngle = 0;
    birdSprite.setPosition(posX, posY);
    birdSprite.setTexture(birdTextureMidFlap);
}
const sf::Sprite & Bird::getBirdSprite() const {
    return birdSprite;
}

Bird::~Bird() = default;


//std::ostream& operator<<(std::ostream& out, const Bird& bird) {
//    out << "posY = " << bird.posY << " | velocity = " << bird.velocity << "\n";
//    return out;
//}