#include "GameUI.h"
#include <iostream>
#include <vector>

using namespace std;

void display_state(const GameState& state) {
    // Clear the console for a clean, animated feel on each turn.
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    cout << "=======================================================\n";
    cout << "              Train Yard Shuffler\n";
    cout << "=======================================================\n";
    cout << "Moves: " << state.move_count << " / " << state.move_limit << "\n";
    cout << "Challenge: " << state.challenge_description << "\n";
    cout << "-------------------------------------------------------\n";

    // Display the Incoming Train
    // A copy is made so can pop items w/o affecting the game state.
    queue<char> incoming_copy = state.incoming_train;
    cout << "1. Incoming Train: Front -> ";
    if (incoming_copy.empty()) {
        cout << "(empty)";
    } else {
        while (!incoming_copy.empty()) {
            cout << "[" << incoming_copy.front() << "] ";
            incoming_copy.pop();
        }
    }
    cout << "\n";

    // Display the Siding Track 
    // A copy is made to display contents w/o altering the original stack.
    stack<char> siding_copy = state.siding_track;
    cout << "2. Siding Track  : Top -> ";
    if (siding_copy.empty()) {
        cout << "(empty)";
    } else {
        while (!siding_copy.empty()) {
            cout << "[" << siding_copy.top() << "] ";
            siding_copy.pop();
        }
    }
    cout << "\n";
    
    // Display the Outgoing Train
    cout << "3. Outgoing Train: ";
    if (state.outgoing_train.empty()) {
        cout << "(empty)";
    } else {
        for (char car : state.outgoing_train) {
            cout << "[" << car << "] ";
        }
    }
    cout << "\n=======================================================\n";
}
