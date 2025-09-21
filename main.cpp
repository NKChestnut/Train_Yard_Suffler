#include "GameState.h"
#include "GameUI.h"
#include "GameLogic.h"
#include <ctime>
#include <cstdlib>

// Use the standard namespace
using namespace std;

int main() {
    // Seed the random number generator once at the start.
    srand(time(NULL));

    // Create the main game state object.
    GameState state;

    // Initialize the game based on user difficulty selection.
    setup_game(state);

    // Main Game Loop
    // The loop continues as long as the game_over flag is false.
    while (!state.game_over) {
        // Show player the current state of the train yard.
        display_state(state);
        
        // Ask for and process player's next move.
        process_user_input(state);
        
        // Check if last move resulted in a win or loss.
        check_game_over_conditions(state);
    }

    return 0;
}
