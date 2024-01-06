/**
 * File name: Ground.hpp
 * Author: Banu Constantin-Adrian
 * Date: 11/11/2023
 * Description:
 * \brief Represents the game ground.
 *
 * This class handles the implementation and drawing of the ground on the screen.
 */

#ifndef OOP_GROUND_HPP
#define OOP_GROUND_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"

class Ground {
private:
    /**
     * \brief Ground texture.
     */
    sf::Texture grTexture;

    /**
     * \brief Ground sprite.
     */
    sf::Sprite grSprite;

    /**
     * \brief Offset on the X-axis between two ground sprites.
     */
    static float offsetX;

    /**
     * \brief Offset on the Y-axis between two ground sprites.
     */
    static float offsetY;

public:
    /**
     * \brief Creates the ground.
     */
    Ground();

    /**
     * \brief Ground destructor.
     */
    ~Ground();

    /**
     * \brief Moves the ground.
     * @param elapsedTime Time between the last 2 frames of the game, used to ensure smooth movement.
     */
    void move(float elapsedTime);

    /**
     * \brief Draws the ground on the screen.
     * @param window Provides a reference to the game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * Getter for the ground sprite.
     * @return Constant reference to the ground sprite.
     */
    const sf::Sprite & getGroundSprite() const;

//    friend std::ostream& operator<<(std::ostream& out, const Ground& ground);
//    Ground(const Ground& other);
//    Ground& operator=(Ground other);
//    friend void swap(Ground& groundA, Ground& groundB);
};

#endif //OOP_GROUND_HPP
