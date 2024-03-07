## Simon Says Game

### ~ Sydney Hildreth and Sidhanth Kafley

This is a memory game called Simon Says. Your "enemy" (aka the computer) will show you a sequence of colors first and then
you must repeat the sequence back. However, as you move on to the next level, the enemy will only display that level's sequence 
so must remember the previous pattern. As you increase levels, the game becomes more challenging and relies on your memory.
In order to win, you must complete all 10 levels. If you don't repeat the same sequence, the game is over and you lose!
We used OpenGL/GLUT for the graphics aspect of the program. We used the draw method of the Shape class to create the four 
different tiles (Squares) that act as if they are buttons. We created a method called isOverlapping that ensures only the
clicks inside the square are registered to the correct color. You can use either CLion or the command line to run this program. 
