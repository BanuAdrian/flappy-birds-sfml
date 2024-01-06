/**
 * File name: Pipe.hpp
 * Author: Banu Constantin-Adrian
 * Date: 11/11/2023
 * Description:
 * \brief Represents the top and bottom pipes.
 *
 * This class handles the implementation and drawing of pipes on the screen.
 */

#ifndef OOP_PIPE_HPP
#define OOP_PIPE_HPP

#include <SFML/Graphics.hpp>
#include "Exceptions.hpp"
#include "Position.hpp"

class Pipe {
protected:
    /**
     * \brief Pipe texture.
     */
    sf::Texture pipeTexture;

    /**
     * \brief Top pipe sprite.
     */
    sf::Sprite topPipeSprite;

    /**
     * \brief Bottom pipe sprite.
     */
    sf::Sprite bottomPipeSprite;

    /**
     * \brief Pipes velocity.
     */
    sf::Vector2f velocity;

    /**
     * \brief Position of the pipes.
     */
    Position<int> position;
public:
    /**
     * \brief Creates an obstacle.
     */
    Pipe();

    /**
     * \brief Draws the pipes on the screen.
     * @param window Provides a reference to the game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * \brief Updates the pipes.
     * @param elapsedTime Time between the last 2 frames of the game, used to ensure smooth movement.
     */
    void update(float elapsedTime);

    /**
     * Getter for the top pipe sprite.
     * @return Constant reference to the top pipe sprite.
     */
    const sf::Sprite & getTopPipeSprite() const;

    /**
     * Getter for the bottom pipe sprite.
     * @return Constant reference to the bottom pipe sprite.
     */
    const sf::Sprite & getBottomPipeSprite() const;

//    Pipe(const Pipe& other);
//    friend void swap(Pipe pipeA, Pipe pipeB);
//    Pipe& operator=(Pipe other);
};

#endif //OOP_PIPE_HPP
