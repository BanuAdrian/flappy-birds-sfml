//
// Created by Adrian on 11-Nov-23.
//

#include "../headers/Ground.hpp"

float Ground::offsetX;
float Ground::offsetY;

Ground::Ground() {
    offsetX = 0.f;
    offsetY = 600.f;
    if (!grTexture.loadFromFile("../assets/ground.png"))
        throw TextureLoadException();
    grSprite.setTexture(grTexture);
    grSprite.setScale(sf::Vector2f(1.6f, 1.f));
    grSprite.setPosition(sf::Vector2f(offsetX, offsetY));
}
void Ground::move(float elapsedTime) {
    offsetX -= elapsedTime * 200;
    if (offsetX <= -80) {
        offsetX += 80;
    }
    grSprite.setPosition(sf::Vector2f(offsetX, offsetY));
}
void Ground::draw(sf::RenderWindow& window) {
    window.draw(grSprite);
}

//void swap(Ground &groundA, Ground &groundB) {
//    std::swap(groundA.grTexture, groundB.grTexture);
//    std::swap(groundA.grSprite, groundB.grSprite);
//    std::swap(groundA.offsetX, groundB.offsetX);
//    std::swap(groundA.offsetY, groundB.offsetY);
//}
//
//Ground::Ground(const Ground &other) : grTexture(other.grTexture), grSprite(other.grSprite) {}
//
//Ground &Ground::operator=(Ground other) {
//    swap(*this, other);
//    return *this;
//}



//std::ostream& operator<<(std::ostream& out, const Ground& ground) {
//    out << "offsetX = " << ground.offsetX << " | offsetY = " << ground.offsetY << "\n";
//    return out;
//}
const sf::Sprite & Ground::getGroundSprite() const {
    return grSprite;
}

Ground::~Ground() = default;