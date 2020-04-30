//
// Created by Sidhanth Kafley on 4/28/20.
//


#include "Square.h"
#include<cmath>
#include "Graphics.h"
#include "string"

/********************* Square Class *********************/

Square::Square() : Shape2D(), side(2.0) {

}

Square::Square(color fill) : Shape2D(fill), side(2.0) {

}
Square::Square(double x, double y) : Shape2D(x, y) {
}
Square::Square(point2D center, double pSide) : Shape2D(center) {

    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
Square::Square(double pSide){

    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
Square::Square(double red, double green, double blue, double alpha, double pSide) : Shape2D(red, green, blue, alpha) {

    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
double Square::getSide() const{
    return side;
}



std::string Square::getType() const {
    switch (square) {
        case one: return "square1";
        case two: return "square2";
        case three: return "square3";
        case four: return "square4";

    }
}


void Square::setSide(double pSide){
    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}

void Square::setType(std::string squareName) {
    if(squareName == "square1"){
        square = one;
    }

    if(squareName == "square2"){
        square = two;
    }

    if(squareName == "square3"){
        square = three;
    }

    if(squareName == "square4"){
        square = four;
    }

}


int Square::getLeftX() const {
    return center.x; //- (side);
}

int Square::getRightX() const {
    return center.x + (side);
}


int Square::getTopY() const {
    return center.y; //- (side / 2);
}

int Square::getBottomY() const {
    return center.y + (side);
}


bool Square::isOverlapping(int x, int y) const {
        if ((x > getLeftX() && x < getRightX()) && (y > getTopY() && y < getBottomY())){
            return true;

        }
    return false;
}

void Square::move(double deltaX, double deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Square::moveX(double deltaX) {
    center.x += deltaX;
}

void Square::moveY(double deltaY) {
    center.y += deltaY;
}




void Square::draw() const{
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // glVertex2i takes a 2-D (x, y) coordinate

    glVertex2i(center.x, center.y);

    glVertex2i(center.x, center.y+150);


    glVertex2i(center.x+150, center.y+150);

    glVertex2i(center.x+150, center.y);
    glEnd();
}



