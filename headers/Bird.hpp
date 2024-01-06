/**
 * File name: Bird.hpp
 * Author: Banu Constantin-Adrian
 * Date: 17/11/2023
 * Description:
 * \brief Represents the base class/interface for the game character.
 *
 * This class handles the in-game representation, drawing, and providing characteristics for each
 * type of bird.
 */

#ifndef OOP_BIRD_HPP
#define OOP_BIRD_HPP

template<class T>
class Position;

#include <SFML/Graphics.hpp>
#include <memory>
#include "Exceptions.hpp"
#include "Position.hpp"

class Bird {
protected:
    /**
     * \brief Texture of the bird with wings up.
     */
    sf::Texture birdTextureUpFlap;

    /**
     * \brief Texture of the bird with centered wings.
     */
    sf::Texture birdTextureMidFlap;

    /**
     * \brief Texture of the bird with wings down.
     */
    sf::Texture birdTextureDownFlap;

    /**
     * \brief The bird's sprite.
     */
    sf::Sprite birdSprite;

    /**
     * \brief Clock used for wing animation.
     */
    std::shared_ptr<sf::Clock> wingsAnimationGeneratingClock;

    /**
     * \brief Score needed for the player to upgrade to the next character.
     */
    int scoreNeededForNextBird;

    /**
     * \brief Determines if the wings are oriented up or down.
     */
    bool wingsUp;

    /**
     * \brief Position of the character.
     */
    Position<float> position;

    /**
     * \brief Character's velocity.
     */
    float velocity;

    /**
     * \brief Rotation angle of the sprite.
     */
    float rotationAngle;

public:
    /**
     * \brief Constructs a new bird.
     *
     * @param localScoreNeeded Score needed for the next bird.
     */
    explicit Bird(int localScoreNeeded = 0);

    /**
     * \brief Virtual destructor.
     */
    virtual ~Bird();

    /**
     * \brief Determines the ability of the bird to fly.
     */
    void fly();

    /**
     * \brief Determines the falling of the bird.
     *
     * @param elapsedTime Time between the last 2 frames of the game, used to ensure smooth movement.
     */
    void fall(float elapsedTime);

    /**
     * \brief Updates the position of the bird.
     */
    void update();

    /**
     * \brief Draws the character on the screen.
     *
     * @param window Provides a reference to the game window.
     */
    void draw(sf::RenderWindow &window);

    /**
     * \brief Allows resetting the attributes at the moment of collision.
     */
    void reset();

    /**
     * \brief Implements wing animation.
     *
     * @param gameHasBegun Communicates the game state.
     */
    void animateWings(bool gameHasBegun);

    /**
     * \brief Getter for the character's sprite.
     *
     * @return Constant reference to the character's sprite.
     */
    const sf::Sprite & getBirdSprite() const;

    /**
     * \brief Virtual "constructor".
     *
     * @return Pointer to the base class Bird.
     */
//    virtual Bird* clone() const = 0;

    /**
     * \brief Getter for the number of lives of the bird.
     *
     * @return Strictly 0 for the derived classes "YellowBird" and "BlueBird"; >= 0 for the derived class "RedBird".
     */
    virtual int getLives() const = 0;

    /**
     * \brief Getter for the needed score.
     *
     * @return >= 0 depending on the current character.
     */
    virtual int getScoreNeededForNextBird() const = 0;

    /**
     * \brief Implements the ability to revive in the case of the derived class "RedBird."
     */
    virtual void revive() = 0;

    /**
     * \brief Handles collision.
     */
    virtual void handleCollision() = 0;

    /**
     * \brief Displays special text depending on the current character.
     *
     * @param window Provides a reference to the game window.
     */
    virtual void displaySpecialText(sf::RenderWindow &window) = 0;

    /**
     * \brief Implements the special ability for the derived class "BlueBird."
     */
    virtual void specialAbility() = 0;

    /**
     * \brief Loads transparency for the derived class "BlueBird".
     */
    virtual void loadTransparence() = 0;

    /**
     * \brief Loads lives for the derived class "RedBird".
     */
    virtual void loadLives() = 0;

    /**
     * \brief Checks the transparency state.
     *
     * @return True if the bird is transparent and False otherwise.
     */
    virtual bool isTransparent() const = 0;

    //    friend std::ostream& operator<<(std::ostream& out, const Pet& pet);
};


#endif //OOP_BIRD_HPP
