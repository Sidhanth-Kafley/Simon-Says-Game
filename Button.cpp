//
// Created by Sydney Hildreth on 4/28/20.
//

#include "Button.h"
#include "Graphics.h"
#include "Shape2d.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

Button::Button(color fill, point center, unsigned int width, unsigned int height, std::string label) : Shape2D(){

    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {fill.red - 0.5, fill.green - 0.5, fill.blue - 0.5};



}

void Button::draw() const {


    //Shape2D::draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(center.x - (4 * label.length()), center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

   /* Circle c(fill, 250, 200, 50);
    c.draw();*/

}

/* Returns true if the coordinate is inside the box */
/*bool Button::isOverlapping(int x, int y) const {
    // TODO: Implement
    if ((x >= getLeftX() && x <= getRightX()) && (x >= getTopY() && x <= getBottomY())){
        return true;

    }
    return false; // Placeholder for compilation
}*/

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    setColor(pressFill);
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    setColor(originalFill);
}