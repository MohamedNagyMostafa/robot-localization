# Introduction
This code implements a simple robot localization algorithm in C++. The algorithm uses a one-dimensional world with colored grid cells, where the robot senses its environment and moves around. The robot's location is initially uncertain and the algorithm calculates the probability of the robot's location after each movement and sensing step.

# Requirements
This code requires a C++ compiler and the Standard Template Library (STL) to run.

# Installation
To run the code, simply download the file and compile it using a C++ compiler. The code has been tested on Linux and Windows operating systems.

# Usage
The code can be executed from the command line by running the compiled executable. The robot's location in the world is displayed after each movement and sensing step.

The `initialProbability` function initializes the probability distribution of the robot's location. The `sense` function updates the probability distribution after the robot senses its environment. The `move` function updates the probability distribution after the robot moves. The display function displays the probability distribution after each step.

# License
This code is released under the MIT license. See the `LICENSE` file for details.
