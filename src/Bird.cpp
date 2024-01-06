//
// Created by Adrian on 17-Nov-23.
//

#include "../headers/Bird.hpp"
#include <iostream>

template<class T>
T maximum(T a, T b) {
    if (a > b)
        return a;
    return b;
}

Bird::Bird(int localScoreNeededForNextBird): wingsAnimationGeneratingClock(std::make_shared<sf::Clock>()),
                                  scoreNeededForNextBird(localScoreNeededForNextBird), position(190, 350)
{
//    position.setX(350);
//    position.setY(190);
//    posY = 350;
//    posX = 190;
    velocity = 0;
    rotationAngle = 0;
    wingsUp = true;
    birdSprite.setOrigin(10, 10);
//    birdSprite.setPosition(posX, posY);
    birdSprite.setPosition(position.getX(), position.getY());
    birdSprite.setScale(sf::Vector2f(1.7f, 1.75f));
}

void Bird::fly() {
//    velocity = -425;
    velocity = -550;
    rotationAngle = -25;
}

void Bird::fall(float elapsedTime) {
    if (maximum<float>(velocity, 500) == 500) {
        velocity += elapsedTime * 2100;
    }
    if (maximum<float>(velocity, 500) == velocity && maximum<float>(rotationAngle, 90) == 90) {
        velocity += elapsedTime * 5;
        rotationAngle += elapsedTime * 400;
    }
    else if (maximum<float>(rotationAngle, 90) == rotationAngle) {
        velocity += elapsedTime * 2100;
    }
    birdSprite.setRotation(rotationAngle);
    position.setY(position.getY() + velocity * elapsedTime);
//    posY += velocity * elapsedTime;
}

void Bird::update() {
//    birdSprite.setPosition(posX, posY);
    birdSprite.setPosition(position.getX(), position.getY());
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
//    posY = 350;
    position.setY(350);
    velocity = 0;
    birdSprite.setRotation(0);
    rotationAngle = 0;
    birdSprite.setPosition(position.getX(), position.getY());
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