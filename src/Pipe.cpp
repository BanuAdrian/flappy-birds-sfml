//
// Created by Adrian on 11-Nov-23.
//

#include "../headers/Pipe.hpp"
#include <iostream>

Pipe::Pipe() : position(600, 0){
    if (!pipeTexture.loadFromFile("../assets/pipes/pipe-green.png"))
        throw TextureLoadException();
    bottomPipeSprite.setTexture(pipeTexture);
    position.setY(280 + (rand() % (210)));
//    PosY = 280 + (rand() % (210));
//    std::cout << "PosY = " << PosY << std::endl;
    velocity = {0.f, 0.f};
//    bottomPipeSprite.setPosition(600, PosY);
    bottomPipeSprite.setPosition(position.getX(), position.getY());
    bottomPipeSprite.setScale(1.75f, 1.f);
    topPipeSprite = bottomPipeSprite;
    topPipeSprite.rotate(180);
    const auto & bottomPipePosition = bottomPipeSprite.getPosition();
    topPipeSprite.setPosition(bottomPipePosition.x + 90, bottomPipePosition.y - 170);
}
void Pipe::draw(sf::RenderWindow& window) {
    window.draw(topPipeSprite);
    window.draw(bottomPipeSprite);
}
void Pipe::update(float elapsedTime) {
    float offsetX = -elapsedTime * 175;
    velocity = {offsetX, 0.f};
    bottomPipeSprite.move(velocity);
    const auto & bottomPipePosition = bottomPipeSprite.getPosition();
    topPipeSprite.setPosition(bottomPipePosition.x + 90, bottomPipePosition.y - 170);
}
const sf::Sprite & Pipe::getTopPipeSprite() const {
    return topPipeSprite;
}
const sf::Sprite & Pipe::getBottomPipeSprite() const {
    return bottomPipeSprite;
}

//void swap(Pipe pipeA, Pipe pipeB) {
//    std::swap(pipeA.pipeTexture, pipeB.pipeTexture);
//    std::swap(pipeA.topPipeSprite, pipeB.topPipeSprite);
//    std::swap(pipeA.bottomPipeSprite, pipeB.bottomPipeSprite);
//    std::swap(pipeA.velocity, pipeB.velocity);
//    std::swap(pipeA.PosY, pipeB.PosY);
//}
//
//
//Pipe::Pipe(const Pipe &other) : pipeTexture(other.pipeTexture), topPipeSprite(other.topPipeSprite),
//                                bottomPipeSprite(other.bottomPipeSprite), velocity(other.velocity),
//                                PosY(other.PosY) {}
//
//Pipe &Pipe::operator=(Pipe other) {
//    swap(*this, other);
//    return *this;
//}
