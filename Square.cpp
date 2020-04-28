//
// Created by Sidhanth Kafley on 4/28/20.
//


#include "Square.h"
#include<cmath>

/********************* Square Class *********************/

Square::Square() : Shape2D(), side(2.0) {
    type = square;
}

Square::Square(color fill) : Shape2D(fill), side(2.0) {
    type = square;
}
Square::Square(double x, double y) : Shape2D(x, y) {
}
Square::Square(point2D center, double pSide) : Shape2D(center) {
    type = square;
    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
Square::Square( double pSide){
    type = square;
    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
Square::Square(double red, double green, double blue, double alpha, double pSide) : Shape2D(red, green, blue, alpha) {
    type = square;
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

void Square::setSide(double pSide){
    if(pSide < 0){
        side = 1;
    }
    else{
        side = pSide;
    }
}
double Square::calculateArea() const {
    double area = pow(side, 2);
    return area;
}

double Square::calculatePerimeter() const {
    double perimeter = 4*side;
    return perimeter;
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



