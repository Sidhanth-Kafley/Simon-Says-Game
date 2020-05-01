#include "Graphics.h"
#include <iostream>
#include <vector>
#include "Square.h"
#include "Button.h"
#include "Circle.h"
#include <string>
#include <ctime>


using namespace std;
string enemyColor;
GLdouble width, height;
int wd;
Square first({0, 1,0});
Square second({1, 0, 0});
Square third({1,1, 0});
Square fourth({1,0,1,0});
vector<string> enemyChosenColor={};
vector<string> userClickedPattern = {};
Button button1({1,0,0}, {100,100}, 100, 50, "Square");
screen state = startGame;

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
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width*2, height*2); // DO NOT CHANGE THIS LINE

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
        first.setType("square1");
        first.setCenter(50,100);
        first.setSide(150);
        first.draw();
        //first.move(400,500);

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


        enemyColor = nextSequence();
        enemyChosenColor.push_back(enemyColor);
        glutTimerFunc(5000, timer, 0);
//        if(enemyColor == "green"){
//            first.setColor(1.0,1.0,1.0,1.0);
//        }
//        else if(enemyColor == "red"){
//            second.setColor(1.0,1.0,1.0,1.0);
//        }
//        else if(enemyColor == "yellow"){
//            third.setColor(1.0,1.0,1.0,1.0);
//        }
//        else{
//            fourth.setColor(1.0,1.0,1.0,1.0);
//        }

        for(int i = 0; i< userClickedPattern.size(); i++){
            if(enemyChosenColor[i]==userClickedPattern[i]){
                cout << enemyChosenColor[i]<<endl;
                cout << userClickedPattern[i]<<endl;

            }
//           else{
//               state = start;
//            }
       }

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
//string
void mouse(int button, int state, int x, int y) {
    string number1 =  first.getType();
    string number2 =  second.getType();
    string number3 =  third.getType();
    string number4 =  fourth.getType();


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&  first.isOverlapping(x,y)){
            first.setColor(1,1,1,1);
        //userClickedPattern.push_back("green");

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && first.isOverlapping(x,y)) {
            first.setColor(0,1,0,1);
        addGreenColor();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && second.isOverlapping(x,y)){
        second.setColor(1,1,1,1);
        //userClickedPattern.push_back("red");

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && second.isOverlapping(x,y)){
        second.setColor(1,0,0,1);
        addRedColor();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && third.isOverlapping(x,y)){
        third.setColor(1,1,1,1);
        //userClickedPattern.push_back("yellow");
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP&& third.isOverlapping(x,y)){
        third.setColor(1,1,0,1);
        addYellowColor();
    }


    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && fourth.isOverlapping(x,y)){
        fourth.setColor(1,1,1,1);
        //userClickedPattern.push_back("purple");

    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && fourth.isOverlapping(x,y)){
        fourth.setColor(1,0,1,1);
        addPurpleColor();
    }


    glutPostRedisplay();
}


string nextSequence(){
//    int randomNumber = rand() % 3;
//    vector<string> buttonColours = {"red", "purple", "green", "yellow"};
//    string randomColor = buttonColours[randomNumber];
//    return randomColor;
    return "red";
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
        glutPostRedisplay();
        dummy++;
        glutTimerFunc(5000, timer, dummy);
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
        glutPostRedisplay();
    }


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
    //glutMouseFunc(mouse2);

    // handles timer
    glutTimerFunc(0, timer, 0);
//    enemyColor = nextSequence();
//    cout<<enemyColor<<endl;
//    for(int i = 0; i< enemyChosenColor.size(); i++){
//        if(enemyChosenColor[i]==userClickedPattern[i]){
//            state = finish;
//        }
//        else{
//            state = finish;
//        }
    // Enter the event-processing loop
    glutMainLoop();


    return 0;
}
