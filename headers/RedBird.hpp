/**
 * File name: RedBird.hpp
 * Author: Banu Constantin-Adrian
 * Date: 17/11/2023
 * Description:
 * \brief Represents the red bird.
 *
 * This class inherits from the base class "Bird" and additionally implements the revive ability specific to this type of bird.
 */

#ifndef OOP_REDBIRD_HPP
#define OOP_REDBIRD_HPP

#include "Bird.hpp"

class RedBird : public Bird {
private:
    /**
     * \brief Number of lives of the character at a certain moment.
     */
    static int lives;

    /**
     * \brief Text used for displaying the number of lives.
     */
    sf::Text livesText;

    /**
     * \brief Font of the text.
     */
    sf::Font font;

    /**
     * \brief Clock that handles lives generation.
     */
    std::shared_ptr<sf::Clock> livesGeneratingClock;

public:
    /**
     * \brief Creates a red bird.
     * @param localScoreNeeded Score needed for such a bird.
     */
    explicit RedBird(int localScoreNeededForNextBird = 0);

    /**
     * \brief Destructor specific to this derived class.
     */
    ~RedBird() override;

    /**
     * \brief Virtual "constructor".
     *
     * @return Pointer to the derived class "RedBird".
     */
//    RedBird* clone() const override;

    /**
     * \brief Getter for the number of lives of the bird.
     *
     * @return >= 0, depending on the number of lives available at a certain moment.
     */
    int getLives() const override;

    /**
     * \brief Getter for the required score.
     *
     * @return >= 0 depending on the current character.
     */
    int getScoreNeededForNextBird() const override;

    /**
     * \brief Implementation of the revive ability.
     */
    void revive() override;

    /**
     * \brief Collision management.
     */
    void handleCollision() override;

    /**
     * \brief Loading transparency in the case of the derived class "BlueBird".
     */
    void loadTransparence() override;

    /**
     * \brief Loading lives.
     */
    void loadLives() override;

    /**
     * \brief Checks the transparency state.
     *
     * @return True if the bird is transparent and False otherwise.
     */
    bool isTransparent() const override;

    /**
     * \brief Displays the number of available lives.
     *
     * @param window Provides a reference to the game window.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementation of transparency.
     */
    void specialAbility() override;
};

#endif //OOP_REDBIRD_HPP
