//
// Created by Adrian on 17-Nov-23.
//

#include "../headers/Bird.hpp"
#include <iostream>

Bird::Bird(int localScoreNeeded):   wingsAnimationGeneratingClock(std::make_shared<sf::Clock>()),
                                    scoreNeeded(localScoreNeeded)
{
    posY = 350;
    posX = 190;
    velocity = 0;
    rotationAngle = 0;
    wingsUp = true;
    birdSprite.setOrigin(10, 10);
    birdSprite.setPosition(posX, posY);
    birdSprite.setScale(sf::Vector2f(1.7f, 1.75f));
}

void Bird::fly() {
//    velocity = -425;
    velocity = -550;
    rotationAngle = -25;
}

void Bird::fall(float elapsedTime) {
    if (velocity <= 500) {
        velocity += elapsedTime * 2100;
    }
    if (velocity > 500 && rotationAngle < 90) {
        velocity += elapsedTime * 5;
        rotationAngle += elapsedTime * 400;
    }
    else if (rotationAngle >= 90) {
        velocity += elapsedTime * 2100;
    }
    birdSprite.setRotation(rotationAngle);
    posY += velocity * elapsedTime;
}

void Bird::update() {
    birdSprite.setPosition(posX, posY);
}

void Bird::animateWings(bool gameHasBegun) {
    float secondsSinceLastWingAnimation;
    if (gameHasBegun)
        secondsSinceLastWingAnimation = 0.1f;
    else
        secondsSinceLastWingAnimation = 0.25f;
    if (wingsAnimationGeneratingClock->getElapsedTime().asSeconds() > secondsSinceLastWingAnimation) {
        if (!wingsUp) {
            birdSprite.setTexture(birdTextureUpFlap);
            wingsUp = true;
        }
        else {
            birdSprite.setTexture(birdTextureDownFlap);
            wingsUp = false;
        }
        wingsAnimationGeneratingClock->restart();
    }
}

void Bird::draw(sf::RenderWindow &window) {
    window.draw(birdSprite);
}
void Bird::reset() {
    posY = 350;
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