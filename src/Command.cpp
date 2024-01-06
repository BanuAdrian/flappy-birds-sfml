//
// Created by Adrian on 06-Jan-24.
//

#include "../headers/Command.hpp"

void FlyCommand::execute(Game& game) {
    game.getBird()->fly();
}

void SpecialAbilityCommand::execute(Game& game) {
    game.getBird()->specialAbility();
}
