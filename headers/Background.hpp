/**
 * File name: Background.hpp
 * Author: Banu Constantin-Adrian
 * Date: 11/11/2023
 * Description:
 * \brief Represents the game background.
 *
 * This class handles the implementation and drawing of the background on the screen.
 *
 */

#ifndef OOP_BACKGROUND_HPP
#define OOP_BACKGROUND_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"

class Background {
protected:
    /**
     * \brief Background texture.
     */
    sf::Texture bgTexture;

    /**
     * \brief Background sprite.
     */
    sf::Sprite bgSprite;

public:
    /**
     * \brief Generates a new background.
     */
    Background();

    /**
     * \brief Draws the background on the screen.
     *
     * @param window Provides a reference to the game window.
     */
    void draw(sf::RenderWindow& window);

//    Background(const Background& other);
//    friend void swap(Background bgA, Background bgB);
//    Background& operator=(Background other);
//    friend std::ostream& operator<<(std::ostream& out, const Background& background);
};

#endif //OOP_BACKGROUND_HPP