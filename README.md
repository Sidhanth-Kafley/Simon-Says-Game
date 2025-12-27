# Simon Says Game

This is a memory game called Simon Says. Your "enemy" (aka the computer) will show you a sequence of colors first and then
you must repeat the sequence back. However, as you move on to the next level, the enemy will only display that level's sequence 
so you must remember the previous pattern. As the level increases, the game becomes more challenging and relies on your memory.
We used the draw method of the Shape class to create the four 
different tiles (Squares) that act as if they are buttons. We created a method called isOverlapping that ensures only the
clicks inside the square are registered to the correct color. You can use either CLion or the command line to run this program. 

## Key features:
- Progressive Difficulty: 10 levels with increasing complexity
- Interactive Graphics: Built using OpenGL/GLUT for smooth visual feedback
- Click Detection: Precise collision detection using custom isOverlapping method
- Object-Oriented Design: Clean architecture with inheritance and polymorphism
- Cross-Platform: Compatible with Windows, macOS, and Linux

## How to play:
- Watch as the computer displays a sequence of colored tiles
- Repeat the sequence by clicking the tiles in the correct order
- Each new level adds one more color to the sequence
- Remember: only the new color is shown, you must recall the previous pattern!
- In order to win, you must complete all 10 levels.
- If you don't repeat the same sequence, the game is over and you lose!

## Technologies used:
- We used OpenGL/GLUT for the graphics aspect of the program.
- C++ for core logic and game structure

## How to Run the Project Locally:

### Prerequisites

1. A C++ compiler such as g++ or clang  
2. OpenGL and GLUT
3. CMake  

### Steps

Clone the repository:

    git clone https://github.com/Sidhanth-Kafley/Simon-Says-Game.git

Navigate into the project directory:

    cd Simon-Says-Game

Create a build directory and compile the project:

    mkdir build
    cd build
    cmake ..
    make

Run the executable:

    ./Simon-Says-Game

The project can also be built using an IDE such as CLion.

## Created by:
~ Sydney Hildreth and Sidhanth Kafley
