//
// Created by Adrian on 05-Jan-24.
//

#include "../headers/BirdFactory.hpp"

std::shared_ptr<Bird> BirdFactory::create(int birdType, int scoreNeededForNextBird) {
    switch (birdType) {
        case YELLOW_BIRD:
            return std::make_shared<YellowBird>(scoreNeededForNextBird);
        case RED_BIRD:
            return std::make_shared<RedBird>(scoreNeededForNextBird);
        case BLUE_BIRD:
            return std::make_shared<BlueBird>(scoreNeededForNextBird);
    }
    throw UnknownBirdException();
}

std::shared_ptr<Bird> BirdFactory::create(int birdType) {
    switch (birdType) {
        case YELLOW_BIRD:
            return std::make_shared<YellowBird>();
        case RED_BIRD:
            return std::make_shared<RedBird>();
        case BLUE_BIRD:
            return std::make_shared<BlueBird>();
    }
    throw UnknownBirdException();
}