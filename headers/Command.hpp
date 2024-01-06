/**
 * File name: Command.hpp
 * Author: Banu Constantin-Adrian
 * Date: 06/01/2024
 * Description:
 *
 * \brief Represents the classes through which the Command design pattern is implemented.
 */

#ifndef OOP_COMMAND_HPP
#define OOP_COMMAND_HPP

class Game;

#include "Game.hpp"

class Command {
public:
    /**
     * \brief Virtual destructor.
     *
     */
    virtual ~Command() = default;

    /**
     * \brief Function for executing a command.
     *
     * @param game Current game instance.
     *
     */
    virtual void execute(Game& game) = 0;
};

class FlyCommand : public Command {
public:
    /**
     * \brief Function for executing a command.
     *
     * @param game Current game instance.
     *
     */
    void execute(Game& game) override;
};

class SpecialAbilityCommand : public Command {
public:
    /**
     * \brief Function for executing a command.
     *
     * @param game Current game instance.
     *
     */
    void execute(Game& game) override;
};

#endif //OOP_COMMAND_HPP
