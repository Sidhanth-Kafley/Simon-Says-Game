#include "Graphics.h"
#include <iostream>
#include <vector>
#include "Square.h"
#include "Button.h"
#include "Circle.h"

using namespace std;

GLdouble width, height;
int wd;
Square first;
Square second;
Square third;
Square fourth;
Circle c(250,200);
Button button1({1,0,0}, {100,100}, 100, 50, "Square");
screen state = startGame;
void init() {
    width = 900;
    height = 900;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    /*
     * Draw here
     */
    // Set the color to draw
    // Note: you can change this at any time during the drawing process
   // s.draw();
    //button1.draw();
    //c.draw();
    //first.move(245,450);
    if (state == startGame) {
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(245, 450);
        for (const char &letter : "Welcome to Simon Says! Press g to begin!"){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    } else if (state == game) {

        first.draw();
        first.move(245,450);
        //second.draw();


    } else if (state == finish) {
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(130, 200);
        for (const char &letter : "Game over!"){
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    switch(key){
        case 'x': start();
            break;

    }

    if (state == startGame && key == 'g'){
        state = game;
    }
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        first.setColor(0,1,0,1);
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        first.setColor(1,1,1,1);
    }
    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}
void start(){

}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Simon Says" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();

    vector<string> buttonColours = {"red", "blue", "green", "yellow"};

    vector<string> gamePattern = {};
    vector<string> userClickedPattern = {};

    int level = 0;

    return 0;
}
