/**
 * File name: BirdFactory.hpp
 * Author: Banu Constantin-Adrian
 * Date: 05/01/2024
 * Description:
 *
 * \brief Represents the class that implements the factory method design pattern.
 */

#ifndef OOP_BIRDFACTORY_HPP
#define OOP_BIRDFACTORY_HPP

#include "YellowBird.hpp"
#include "BlueBird.hpp"
#include "RedBird.hpp"
#include "Exceptions.hpp"

#define YELLOW_BIRD 1
#define RED_BIRD 2
#define BLUE_BIRD 3

class BirdFactory {
public:
    /**
     * \brief Function for creating a new bird.
     *
     * @param birdType Specifies the type of bird to create.
     *
     * @return Smart pointer to the Bird class.
     */
    std::shared_ptr<Bird> create(int birdType);

    /**
     * \brief Overloaded function for creating a new bird.
     *
     * @param birdType Specifies the type of bird to create.
     *
     * @param scoreNeededForNextBird Stores the score needed to upgrade to the next character.
     *
     * @return Smart pointer to the Bird class.
     */
    std::shared_ptr<Bird> create(int birdType, int scoreNeededForNextBird);
};


#endif //OOP_BIRDFACTORY_HPP
