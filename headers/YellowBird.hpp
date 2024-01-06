/**
 * File name: YellowBird.hpp
 * Author: Banu Constantin-Adrian
 * Date: 17/11/2023
 * Description:
 * \brief Represents the yellow bird.
 *
 * This class inherits from the base class "Bird".
 */

#ifndef OOP_YELLOWBIRD_HPP
#define OOP_YELLOWBIRD_HPP

#include "Bird.hpp"

class YellowBird : public Bird {
public:
    /**
     * \brief Creates a yellow bird.
     */
    explicit YellowBird(int localScoreNeededForNextBird = 2);

    /**
     * \brief Destructor specific to this derived class.
     */
    ~YellowBird() override;

    /**
     * \brief Virtual "constructor".
     *
     * @return Pointer to the derived class "YellowBird".
     */
//    YellowBird* clone() const override;

    /**
     * \brief Getter for the number of lives of the bird.
     *
     * @return 0, since it is a specific ability of the derived class "RedBird".
     */
    int getLives() const override;

    /**
     * \brief Getter for the required score.
     *
     * @return 0, since it is the starting character.
     */
    int getScoreNeededForNextBird() const override;

    /**
     * \brief Implementation of the revive ability in the case of the derived class "RedBird".
     */
    void revive() override;

    /**
     * \brief Collision management.
     */
    void handleCollision() override;

    /**
     * \brief Loading transparency for the derived class "BlueBird".
     */
    void loadTransparence() override;

    /**
     * \brief Loading lives for the derived class "RedBird".
     */
    void loadLives() override;

    /**
     * \brief Displaying special text depending on the current character.
     *
     * @param window Provides a reference to the game window.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementation of the special ability for the derived class "BlueBird".
     */
    void specialAbility() override;

    /**
     * \brief Checks the transparency state.
     *
     * @return True if the bird is transparent and False otherwise.
     */
    bool isTransparent() const override;
};

#endif //OOP_YELLOWBIRD_HPP
