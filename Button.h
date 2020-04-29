//
// Created by Sydney Hildreth on 4/28/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_BUTTON_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_BUTTON_H


#include "Shape.h"
#include "Shape2d.h"
#include "Square.h"
#include <string>

class Button : public Shape2D {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    Button(color fill, point center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw(int x, int y) const override;

    /* Returns true if the coordinate is inside the box */
    //bool isOverlapping(int x, int y) const;

    /* Change color of the Button when the user is hovering over it */
    void hover();

    /* Change color of the Button when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();
};
#endif //SH_SK_FINAL_PROJECT_GRAPHICS_BUTTON_H
