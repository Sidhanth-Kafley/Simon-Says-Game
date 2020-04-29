//
// Created by Sydney Hildreth on 4/27/20.
//

//
// Created by Sydney Hildreth on 2/24/20.
//

#include "Circle.h"
#include "Graphics.h"

Circle::Circle() : Shape2D(){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(double radius): Shape2D(){
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }
    type = circle;
}

Circle::Circle(color fill) : Shape2D(fill){
    radius = defaultValue;
    type = circle;
}


Circle::Circle(color fill, double radius) : Shape2D(fill) {
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }
    type = circle;
}

Circle::Circle(point2D center) : Shape2D(center) {
    radius = defaultValue;
    type = circle;
}

Circle::Circle(double x, double y) : Shape2D(x,y){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(color fill, point2D center) : Shape2D(fill, center){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(color fill, double x, double y) : Shape2D(fill, x, y){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(color fill, double x, double y, double radius) : Shape2D(fill, x, y){
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }
    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha) : Shape2D(red, green, blue, alpha){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha, double radius) : Shape2D(red, green, blue, alpha){
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }
    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha,  point2D center) : Shape2D(red, green, blue, alpha, center){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha,  point2D center, double radius) : Shape2D(red, green, blue, alpha, center){
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }

    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha, double x, double y) : Shape2D(red, green, blue, alpha, x, y){
    radius = defaultValue;
    type = circle;
}

Circle::Circle(double red, double green, double blue, double alpha, double x, double y, double radius) : Shape2D(red, green, blue, alpha, x, y){
    if(radius > 0){
        this->radius = radius;
    } else {
        defaultValue = radius;
    }
    type = circle;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius){
    if(radius > 0){
        this->radius = radius;
    } else {
        radius = defaultValue;
    }
}
void Circle::move(double deltaX, double deltaY) {
    if(deltaX > 0 && deltaY > 0){
        Shape2D::move(deltaX, deltaY);
    } else {
        Shape2D::move(defX, defY);
    }

}

void Circle::moveX(double deltaX){
    if(deltaX > 0 ){
        Shape2D::moveX(deltaX);
    } else {
        Shape2D::moveX(defX);
    }

}

void Circle::moveY(double deltaY){
    if(deltaY > 0 ){
        Shape2D::moveY(deltaY);
    }else {
        Shape2D::moveY(defY);
    }
}

void Circle::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    for (double i = 0; i < 2.0 * PI + 0.05; i += (2.0 * PI) / 360.0) {
        glVertex2i(center.x + (radius * cos(i)),
                center.y + (radius * sin(i)));
    }
    glEnd();
}



