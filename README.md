# CPPND: Capstone Pong Game

Pong Game using as base code the starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. Also as a source of inspiration the blog https://austinmorlan.com/posts/pong_clone/ help to create this game.

# Game instructions:
* Players:
  * 1.- Player1 is the left paddle, player2 is the right paddle..
 
* Movements:
  * 1.- To move the left paddle up press `w`, to move it down press `s`.
  * 2.- To move the right paddle up press `up arrow`, to move it down press `down arrow`.
 
* Score:
  * 1.- When the left wall is hit by the ball the score for player2 increment, when the right wall is hit player's 1 score is incremented.
 
* Initial state:
  * 1.- On game start the ball starts in the middle and moves in direction to the right wall.
  * 2.- The scores increment by 1. There is no limit for now.

* What's next:
  * 1.- Change the ball's direction randomly when it hits the paddles, right now follows kinda predictable trajectory.
  * 2.- Add sound effects.
  * 3.- Limit the score to a limit so the game ends, and organize the matches by sets.
 
 ## Rubrics:
  * A.- Compiling and Testing (All Rubric Points REQUIRED):
      * The project runs locally using cmake and make. Follow the instructions in dependencies for running locally and basic build instructions.
   
  * B.- Loops, Functions, I/O:
      * Main: Almost similar to the snake game. Initalize the Renderer, Controller and Game logic. Set some useful variables.
      * Renderer: Main goal is to initalize the SLD_Renderer and draw the primitives in the screen.
      * Player: Initialize and Loads the font to use for score displaying. Keep track of the player score.
      * Paddle: Logic to update the paddle position, velocity and render.
      * Ball: Logic to update the ball position, velocity and render.
      * Controller: Logic to get the input from the keyboard and update the paddles velocity or quit the game.
      * GameVector: Helper class to handle some vector operations.
      * Game: Intialize the main game loop, and handle update logic, such as collisions or text.
      * The project reads the Lemonada-Bold.ttf font to display the player's score.
      * The user input is read from the keyboard to move the paddles.
      
  * C.- Object Oriented Programming:
      * Each class, main, renderer, player, paddle, ball, controller, gamevector and game have their own attributes and methods.
      * In each classes their attributes where set private or public accordingly.
      * Attributes and methods are named accordinly to their purpose and actions.
      * States are accessed via getter and setter methods.
      
  * D.- Memory Management:
      * Pass by reference is used in some functions.
      * Rule of five implemented in GameVector, Paddle and Ball classes.
      * use of descrutors in player to clean the fonts.
      * use of unique_ptr.
      
  * E.- Concurrency:
    
   
## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

* SDL_ttf 2.0.15, recommended used Brew install SDL_ttf for Mac and Linux. 
  * Linux: https://www.libsdl.org/projects/SDL_ttf/
  * Mac: https://www.libsdl.org/projects/SDL_ttf/
  * Windows: https://www.libsdl.org/projects/SDL_ttf/

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PongGame`.

![pong](https://user-images.githubusercontent.com/51099172/89977139-418bcf80-dc1f-11ea-856f-f5ac5b3e2161.jpg)


