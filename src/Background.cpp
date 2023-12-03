//
// Created by Adrian on 11-Nov-23.
//

#include "../headers/Background.hpp"

Background::Background() {
    if (!bgTexture.loadFromFile("../assets/backgrounds/day.png")) {
        throw TextureLoadException();
    }
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(sf::Vector2f(2.f, 1.5f));
}

void Background::draw(sf::RenderWindow& window) {
    window.draw(bgSprite);
}

//void swap(Background bgA, Background bgB) {
//    std::swap(bgA.bgTexture, bgB.bgTexture);
//    std::swap(bgA.bgSprite, bgB.bgSprite);
//}

//Background::Background(const Background& other) : bgTexture(other.bgTexture), bgSprite(other.bgSprite) {}

//Background& Background::operator=(Background other) {
//    swap(*this, other);
//    return *this;
//}

//std::ostream& operator<<(std::ostream& out, const Background& background) {
//    float posX = sf::Vector2f(background.bgSprite.getPosition()).x;
//    float posY = sf::Vector2f(background.bgSprite.getPosition()).y;
//    out << "Background position: (" << posX << ", " << posY << ")\n";
//    return out;
//}