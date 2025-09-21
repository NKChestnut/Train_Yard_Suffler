#include "GameLogic.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Use the standard namespace
using namespace std;

void setup_game(GameState& state) {
    // Initialize GameState defaults
    state.move_count = 0;
    state.game_over = false;
    state.is_hard_mode = false;
    int num_cars = 0;

    // Difficulty Selection
    cout << "Welcome to the Train Yard Shuffler!\n";
    cout << "Choose your difficulty:\n";
    cout << "  1. Easy   (3 cars, simple puzzle)\n";
    cout << "  2. Medium (6 cars, limited siding)\n";
    cout << "  3. Hard   (9 cars, heavy car & limited siding)\n";
    cout << "Your choice: ";
    char difficulty_choice;
    cin >> difficulty_choice;

    switch (difficulty_choice) {
        case '1':
            num_cars = 3;
            state.move_limit = 10;
            state.siding_capacity = 3;
            state.challenge_description = "Solve within 10 moves.";
            break;
        case '2':
            num_cars = 6;
            state.move_limit = 30;
            state.siding_capacity = 3;
            state.challenge_description = "Siding track can only hold 3 cars!";
            break;
        case '3':
            num_cars = 9;
            state.move_limit = 50;
            state.siding_capacity = 4;
            state.is_hard_mode = true;
            state.challenge_description = "Siding holds 4 cars & car [X] is extra heavy!";
            break;
        default:
            cout << "Invalid choice. Setting to Easy.\n";
            num_cars = 3;
            state.move_limit = 10;
            state.siding_capacity = 3;
            state.challenge_description = "Solve within 10 moves.";
            break;
    }

    // Generate Train Cars
    if (state.is_hard_mode) {
        // For hard mode, the train has N-1 lettered cars plus the special 'X' car.
        for (int i = 0; i < num_cars - 1; ++i) {
            state.target_train.push_back('A' + i);
        }
        state.target_train.push_back('X');
    } else {
        // For easy/medium, the train just has N lettered cars.
        for (int i = 0; i < num_cars; ++i) {
            state.target_train.push_back('A' + i);
        }
    }
    
    vector<char> shuffled_cars = state.target_train;

    // Shuffle and Validate Puzzle
    random_shuffle(shuffled_cars.begin(), shuffled_cars.end());

    // Loop so the puzzle never starts in an already-solved state.
    while (equal(shuffled_cars.begin(), shuffled_cars.end(), state.target_train.begin())) {
        random_shuffle(shuffled_cars.begin(), shuffled_cars.end());
    }

    // Load the shuffled cars into the incoming train queue.
    for (char car : shuffled_cars) {
        state.incoming_train.push(car);
    }
}


void process_user_input(GameState& state) {
    cout << "Target Order: ";
    for(char c : state.target_train) cout << "[" << c << "] ";
    cout << "\n\n";

    cout << "Choose an action:\n";
    cout << "  1. Move car from [Incoming] -> [Siding]\n";
    cout << "  2. Move car from [Siding]   -> [Outgoing]\n";
    cout << "  (Enter 'q' to quit)\n";
    cout << "Your choice: ";
    
    string choice;
    cin >> choice;

    bool move_made = false;
    if (choice == "1") {
        if (state.incoming_train.empty()) {
            cout << "\nAction failed: The Incoming Train is empty!\n";
        } else if (state.siding_track.size() >= state.siding_capacity) {
            cout << "\nAction failed: The Siding Track is full!\n";
        } else {
            char car_to_move = state.incoming_train.front();
            // Hard mode rule: Heavy car 'X' cannot go on an empty siding.
            if (state.is_hard_mode && car_to_move == 'X' && state.siding_track.empty()) {
                cout << "\nAction failed: The Heavy Car [X] cannot be placed on an empty siding!\n";
            } else {
                state.incoming_train.pop();
                state.siding_track.push(car_to_move);
                move_made = true;
            }
        }
    } else if (choice == "2") {
        if (state.siding_track.empty()) {
            cout << "\nAction failed: The Siding Track is empty!\n";
        } else {
            char car_to_move = state.siding_track.top();
            state.siding_track.pop();
            state.outgoing_train.push_back(car_to_move);
            move_made = true;
        }
    } else if (choice == "q") {
        cout << "Thanks for playing!\n";
        state.game_over = true;
    } else {
        cout << "\nInvalid choice. Please enter 1, 2, or q.\n";
    }

    if (move_made) {
        state.move_count++;
    }
}


void check_game_over_conditions(GameState& state) {
    // Check for Loss Condition (Out of moves)
    if (state.move_count >= state.move_limit) {
        cout << "\nGAME OVER! You ran out of moves.\n";
        state.game_over = true;
        return; // Exit early if the player has lost
    }

    // Check for Win/Loss Condition
    if (state.outgoing_train.size() == state.target_train.size()) {
        // Compare the completed train with the target order.
        if (equal(state.outgoing_train.begin(), state.outgoing_train.end(), state.target_train.begin())) {
            cout << "\nCongratulations! You solved the puzzle in " << state.move_count << " moves!\n";
        } else {
            cout << "\nThe final train is in the wrong order! You lose.\n";
        }
        state.game_over = true;
    }
}
