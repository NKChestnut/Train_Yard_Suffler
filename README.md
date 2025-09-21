# Train Yard Suffler

A logic puzzle game built in C++ that runs in the terminal. The objective is to reorder a jumbled train using a single siding track. This project is a hands-on demonstration of the **Stack** and **Queues**.

## Core Concepts Demonstrated

This program was designed to showcase two fundamental Last-In-First-Out (LIFO) and First-In-First-Out (FIFO) data structures:

* **`std::queue`**: Represents the **Incoming Train**. Cars can only be taken from the front of the queue, perfectly simulating a train that can only move forward.
* **`std::stack`**: Represents the **Siding Track**. A car moved to the siding track can only be moved back out from the same end it entered, making the last car in the first one out.

The puzzle challenges the player to use these two structures to sort a randomly ordered set of cars.

## Features

* **Three Difficulty Levels**:
  * **Easy**: 3 train cars with a generous move limit.
  * **Medium**: 6 train cars with a limited siding track capacity (3 cars).
  * **Hard**: 9 train cars with limited siding capacity and a special "Heavy Car" (`[X]`) that cannot be placed on an empty siding.
* **Randomized Puzzles**: The starting order of the train is randomly shuffled every time you play.
* **Multi-File Structure**: The code is organized into header and source files for better readability and maintenance, following standard C++ practices.
* **Clear Console UI**: The game screen is cleared and redrawn after every move, providing a clean and smooth user experience.

## How to Compile and Run

This project is designed to be compiled using `g++` and `make`.

### Prerequisites

* A C++ compiler (like g++)
* `make`

## How to Play

1. **Objective**: Your goal is to move all train cars from the **Incoming Train** to the **Outgoing Train** in the correct alphabetical (and special character) order shown by the "Target Order" display.

2. **Controls**:
* Enter `1` to move the front car from the **Incoming Train** to the top of the **Siding Track**.
* Enter `2` to move the top car from the **Siding Track** to the end of the **Outgoing Train**.
* Enter `q` to quit the game at any time.

3. **Challenges**: Pay attention to the move limit and siding capacity on higher difficulties!

## Project Structure

The code is split into several files for better organization:

* `main.cpp`: The main entry point of the program. Contains the primary game loop.
* `GameState.h`: Defines the `GameState` struct, which holds all the data for a game session.
* `GameLogic.h / GameLogic.cpp`: Contains functions for setting up the game, processing player input, and checking for win/loss conditions.
* `GameUI.h / GameUI.cpp`: Contains the function for rendering the game state to the console.
* `Makefile`: The build script used by `make` to compile the entire project.
