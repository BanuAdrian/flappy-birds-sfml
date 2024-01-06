/**
 * File name: BlueBird.hpp
 * Author: Banu Constantin-Adrian
 * Date: 17/11/2023
 * Description:
 * \brief Represents the blue bird.
 *
 * This class inherits from the base class "Bird" and additionally implements transparency specific to this type of bird.
 */

#ifndef OOP_BLUEBIRD_HPP
#define OOP_BLUEBIRD_HPP

#include <memory>
#include "Bird.hpp"

class BlueBird : public Bird{
private:
    /**
     * \brief Specifies if the transparency ability is ready.
     */
    bool transparenceReady;

    /**
     * \brief Specifies if the bird is transparent at the moment.
     */
    bool transparentNow;

    /**
     * \brief Text for displaying a suggestive message regarding the availability of the transparency ability.
     */
    sf::Text transparenceText;

    /**
     * \brief The font used for text.
     */
    sf::Font font;

    /**
     * \brief The clock used to manage transparency.
     */
    std::shared_ptr<sf::Clock> transparenceHandlingClock;

public:
    /**
     * \brief Constructs a new blue bird.
     * @param localScoreNeededForNextBird Score needed for the next bird.
     */
    explicit BlueBird(int localScoreNeededForNextBird = 5);

    /**
     * \brief Destructor specific to this derived class.
     */
    ~BlueBird() override;

    /**
     * \brief Virtual "constructor".
     *
     * @return Pointer to the derived class "BlueBird".
     */
//    BlueBird* clone() const override;

    /**
     * \brief Getter for the number of lives of the bird.
     *
     * @return 0, as it is a specific ability of the derived class "RedBird".
     */
    int getLives() const override;

    /**
     * \brief Getter for the required score.
     *
     * @return >= 0 depending on the current character.
     */
    int getScoreNeededForNextBird() const override;

    /**
     * \brief Implementation of the ability to revive for the derived class RedBird.
     */
    void revive() override;

    /**
     * \brief Collision management.
     */
    void handleCollision() override;

    /**
     * \brief Loading transparency.
     */
    void loadTransparence() override;

    /**
     * \brief Loading lives for the derived class "RedBird".
     */
    void loadLives() override;

    /**
     * \brief Checks the transparency status.
     *
     * @return True if the bird is transparent and False otherwise.
     */
    bool isTransparent() const override;

    /**
     * \brief Displays transparency availability.
     *
     * @param window Provides a reference to the game window.
     */
    void displaySpecialText(sf::RenderWindow &window) override;

    /**
     * \brief Implementation of the special ability for the derived class "BlueBird".
     */
    void specialAbility() override;
};


#endif //OOP_BLUEBIRD_HPP
