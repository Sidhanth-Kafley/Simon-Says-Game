#include "Graphics.h"
#include <iostream>
#include <vector>
#include "Square.h"

#include <string>
#include <ctime>


using namespace std;
string enemyColor;
GLdouble width, height;
int wd;
int level = 1;
Square first({0, 1,0});
Square second({1, 0, 0});
Square third({1,1, 0});
Square fourth({1,0,1,0});
vector<string> enemyChosenColor={};
vector<string> userClickedPattern = {};

vector<int> levelNumbers = {};
vector<int> endGame = {1};
screen stateScreen = startGame;

void addGreenColor(){
    userClickedPattern.push_back("green");
}
void addRedColor(){
    userClickedPattern.push_back("red");
}
void addYellowColor(){
    userClickedPattern.push_back("yellow");
}
void addPurpleColor(){
    userClickedPattern.push_back("purple");
}


void init() {
    width = 900;
    height = 900;
    srand(time(0));
    enemyColor = "red";
    enemyChosenColor.push_back(enemyColor);


}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Blue and opaque
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

    if (stateScreen == startGame) {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2i(150, 450);
        for (const char &letter : "Welcome to Simon Says! Press i for instructions or g to begin!") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }


    }else if (stateScreen == instruction){
        glColor3f(1.0, 1.0, 1.0);

        glRasterPos2i(250, 300);
        for (const char &letter : "INSTRUCTIONS FOR SIMON SAYS") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }

        glRasterPos2i(75, 450);
        for (const char &letter : "This is a Simon Says Game. Your enemy will show you a sequence of colors. ") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        glRasterPos2i(75, 500);
        for (const char &letter : "However, as you move on to the next level, the enemy will only display that level's ") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        glRasterPos2i(75, 550);
        for (const char &letter : "sequence, so must remember the previous pattern. ") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }

        glRasterPos2i(75, 600);
        for (const char &letter : "In order to win, you must complete all 10 levels.") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }


        glRasterPos2i(300, 650);
        for (const char &letter : "Press 'g' to begin.") {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }


    }else if (stateScreen == game) {
        first.setType("square1");
        first.setCenter(50,100);
        first.setSide(150);
        first.draw();


        second.setType("square2");
        second.setCenter(500, 100);
        second.setSide(150);
        second.draw();


        third.setType("square3");
        third.setCenter(50,500);
        third.setSide(150);
        third.draw();

        fourth.setType("square4");
        fourth.setCenter(500,500);
        fourth.setSide(150);
        fourth.draw();


        if(levelNumbers.size() == 9){
            stateScreen = winner;
        }

        if(endGame.size() == 2){
            stateScreen = finish;
        }



    } else if (stateScreen == finish) {
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(130, 500);
        for (const char &letter : "Game over! The enemy has outsmarted you!"){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
    } else if (stateScreen == winner){
        glColor3f(1.0, 0.0, 0.0);
        glRasterPos2i(130, 200);
        for (const char &letter : "Congratulations! You have outsmarted your enemy!"){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
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

    if (stateScreen == startGame && (key == 'g' || key == 'G')){
        stateScreen = game;
        glutTimerFunc(1000, timer, 0);
    }

    if (stateScreen == startGame && key == 'i' || key == 'I' ){
        stateScreen = instruction;


    }

    if (stateScreen == instruction && (key == 'g' || key == 'G')){
        stateScreen = game;
        glutTimerFunc(1000, timer, 0);
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
    string number1 =  first.getType();
    string number2 =  second.getType();
    string number3 =  third.getType();
    string number4 =  fourth.getType();


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&  first.isOverlapping(x,y)){
            first.setColor(1,1,1,1);

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && first.isOverlapping(x,y)) {
            first.setColor(0,1,0,1);
        addGreenColor();
        for(int i = 0; i< userClickedPattern.size(); i++) {
            if (enemyChosenColor[i] != userClickedPattern[i]) {
                endGame.push_back(2);
                userClickedPattern.clear();
            }


        }
        if (level <= 10 && userClickedPattern.size() == enemyChosenColor.size()) {
                  level = nextSequence(level);
                   userClickedPattern.clear();
        }

    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && second.isOverlapping(x,y)){
        second.setColor(1,1,1,1);


    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && second.isOverlapping(x,y)){
        second.setColor(1,0,0,1);
        addRedColor();
        for(int i = 0; i< userClickedPattern.size(); i++) {
            if (enemyChosenColor[i] != userClickedPattern[i]) {
                endGame.push_back(2);
                userClickedPattern.clear();
            }


        }
        if (level <= 10 && userClickedPattern.size() == enemyChosenColor.size()) {
            level = nextSequence(level);
            userClickedPattern.clear();
        }
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && third.isOverlapping(x,y)){
        third.setColor(1,1,1,1);

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP&& third.isOverlapping(x,y)){
        third.setColor(1,1,0,1);
        addYellowColor();
        cout << userClickedPattern.size() << endl;
        cout << enemyChosenColor.size() << endl;
        for(int i = 0; i< userClickedPattern.size(); i++) {
            if (enemyChosenColor[i] != userClickedPattern[i]) {
                endGame.push_back(2);
                userClickedPattern.clear();
            }


        }
        if (level <= 10 && userClickedPattern.size() == enemyChosenColor.size()) {
            level = nextSequence(level);
            userClickedPattern.clear();
        }
    }


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && fourth.isOverlapping(x,y)){
        fourth.setColor(1,1,1,1);


    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fourth.isOverlapping(x,y)){
        fourth.setColor(1,0,1,1);
        addPurpleColor();
        for(int i = 0; i< userClickedPattern.size(); i++) {
            if (enemyChosenColor[i] != userClickedPattern[i]) {
                endGame.push_back(2);
                userClickedPattern.clear();
            }


        }
        if (level <= 10 && userClickedPattern.size() == enemyChosenColor.size()) {
            level = nextSequence(level);
            userClickedPattern.clear();
        }
    }


    glutPostRedisplay();
}


int nextSequence(int level) {


    levelNumbers.push_back(level);
    int randomNumber = rand() % 3;
    vector<string> buttonColours = {"red", "purple", "green", "yellow"};
    string randomColor = buttonColours[randomNumber];
    enemyColor = randomColor;
    enemyChosenColor.push_back(enemyColor);
    glutTimerFunc(2000, timer, 0);
    level++;
    return level;

}


void timer(int dummy) {
    if(dummy == 0){
        if(enemyColor == "green"){
            first.setColor(1.0,1.0,1.0,1.0);

        }
        else if(enemyColor == "red"){
            second.setColor(1.0,1.0,1.0,1.0);

        }
        else if(enemyColor == "yellow"){
            third.setColor(1.0,1.0,1.0,1.0);

        }
        else if(enemyColor == "purple"){
            fourth.setColor(1.0,1.0,1.0,1.0);

        }

        dummy++;
        glutTimerFunc(500, timer, dummy);
    }
    else{
        if(enemyColor == "green"){
            first.setColor(0.0,1.0,0.0,1.0);

        }
        else if(enemyColor == "red"){
            second.setColor(1.0,0.0,0.0,1.0);

        }
        else if(enemyColor == "yellow"){
            third.setColor(1.0,1.0,0.0,1.0);

        }
        else if(enemyColor == "purple"){
            fourth.setColor(1.0,0.0,1.0,1.0);

        }

    }

    glutPostRedisplay();


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



    // Enter the event-processing loop
    glutMainLoop();


    return 0;
}
