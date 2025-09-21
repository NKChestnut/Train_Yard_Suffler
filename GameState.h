#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <queue>
#include <stack>
#include <vector>
#include <string>

// Use the standard namespace to avoid repeatedly typing 'std::'
using namespace std;

/*struct GameState
Holds all the data representing the current state of the train yard game.
This structure is passed between functions to provide them with the context
they need to display the state, process moves, and check for win/loss conditions.
*/
struct GameState {
    // Data structures for the train cars
    queue<char> incoming_train;
    stack<char> siding_track;
    vector<char> outgoing_train;
    vector<char> target_train;

    // Game rule parameters
    int move_count;
    int move_limit;
    size_t siding_capacity;
    bool is_hard_mode;
    string challenge_description;

    // Game flow control
    bool game_over;
};

#endif // GAMESTATE_H
