/**
 * File name: Game.hpp
 * Author: Banu Constantin-Adrian
 * Date: 11/11/2023
 * Description:
 * \brief Represents the actual game.
 *
 * This class handles the game functionalities.
 */
#pragma once

#ifndef OOP_GAME_HPP
#define OOP_GAME_HPP

class Command;

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Ground.hpp"
#include "BirdFactory.hpp"
#include "Pipe.hpp"
#include "Background.hpp"
#include "Exceptions.hpp"
#include "Command.hpp"

#define YELLOW_BIRD 1
#define RED_BIRD 2
#define BLUE_BIRD 3

class Game {
private:
    /**
     * \brief Game window.
     */
    sf::RenderWindow window;

    /**
     * \brief Score text.
     */
    sf::Text scoreText;

    /**
     * \brief Text for the highest score obtained by the player.
     */
    sf::Text highestScoreText;

    /**
     * \brief Font for text.
     */
    sf::Font font;

    /**
     * \brief Clock used for managing game frames.
     */
    std::shared_ptr<sf::Clock> frameHandlingClock;

    /**
     * \brief Clock used for generating pipes.
     */
    std::shared_ptr<sf::Clock> pipeGeneratingClock;

    /**
     * \brief Clock used for generating the score.
     *
     * Since obstacles are generated at a constant time interval, the score increases based on this aspect.
     */
    std::shared_ptr<sf::Clock> scoreGeneratingClock;

    /**
     * \brief Game obstacles represented by pipes.
     */
//    std::vector<Pipe*> pipes;
    std::vector<std::shared_ptr<Pipe>> pipes;
    /**
     * \brief The object from the factory method.
     */
    BirdFactory birdFactory;

    /**
     * \brief Current character.
     */
    std::shared_ptr<Bird> bird;

    /**
     * \brief Current command to be executed.
     */
    std::shared_ptr<Command> currentCommand;

    /**
     * \brief Game background.
     */
    Background background;

    /**
     * \brief Game ground.
     */
    Ground ground;

    /**
     * \brief Time between the last 2 game frames, used to ensure smooth movement of sprites.
     */
    static float elapsedTime;

    /**
     * \brief Specifies if the game is running.
     */
    static bool isRunning;

    /**
     * \brief Specifies if the game has started.
     */
    static bool hasBegun;

    /**
     * \brief Score obtained before a collision.
     */
    static int score;

    /**
     * \brief The highest score obtained by the player for the current game session.
     */
    static int highestScore;

    /**
     * \brief Specifies the current bird.
     */
    static int currentBird;

public:
    /**
     * \brief Creates a new game.
     */
    Game();

    /**
     * \brief Game destructor.
     */
    ~Game() = default;

    /**
     * \brief Detects collision with the ground.
     * @return True if the bird hits the ground and False otherwise.
     */
    bool groundCollision() const;

    /**
     * \brief Detects collision with pipes.
     * @return True if the bird hits the pipes and False otherwise.
     */
    bool pipeCollision() const;

    /**
     * \brief Detects collision with screen boundaries.
     * @return True if the bird is about to exceed the screen boundaries and False otherwise.
     */
    bool outOfScreenCollision() const;

    /**
     * \brief Getter for the current character.
     * @return Smart pointer to the current character.
     */
    std::shared_ptr<Bird> getBird() const;

    /**
     * \brief Setter for the command to be executed.
     */
    void setCommand(std::shared_ptr<Command> newCommand);

    /**
     * \brief Provides window settings.
     */
    void windowSettings();

    /**
     * \brief Provides text settings.
     */
    void textSettings();

    /**
     * \brief Provides initial values for game attributes.
     */
    void initSettings();

    /**
     * \brief Handles events within the game window.
     *
     * Events can be: closing the window, pressing a button, or clicking.
     */
    void handleEvents();

    /**
     * \brief Handles the time between the last two frames of the game.
     */
    void handleTime();

    /**
     * \brief Handles the displayed text.
     */
    void handleText();

    /**
     * \brief Handles the score.
     */
    void handleScore();

    /**
     * \brief Handles collision with obstacles.
     */
    void handleCollision();

    /**
     * \brief Checks for any type of collision.
     */
    void checkCollision();

    /**
     * \brief Updates game objects.
     */
    void updateObjects();

    /**
     * \brief Draws game objects.
     */
    void drawObjects();

    /**
     * \brief Renders game scenes.
     */
    void render();

    /**
     * \brief Updates the character based on the player's highest score.
     */
    void upgradeBird();

    /**
     * \brief Starts the game.
     */
    void start();

    /**
     * \brief Updates the player's highest score.
     */
    static void updateHighestScore();

    /**
     * \brief Resets the score.
     */
    static void resetScore();

//    Game &operator=(Game other);
//    Game(const Game& other);
//    friend std::ostream& operator<<(std::ostream& out, const Game& game);
//    friend void swap(Game& gameA, Game& gameB);
};

#endif //OOP_GAME_HPP
