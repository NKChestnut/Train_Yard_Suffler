#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameState.h"

//Initializes the game by setting up difficulty and the initial train order.
void setup_game(GameState& state);

//Processes the player's input and updates the game state accordingly.
void process_user_input(GameState& state);

//Checks if the game has reached a win or loss condition.
void check_game_over_conditions(GameState& state);

#endif // GAMELOGIC_H
