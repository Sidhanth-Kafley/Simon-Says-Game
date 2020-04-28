//
// Created by Sydney Hildreth on 4/27/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H

#include "shape2d.h"
#include <cmath>

static const color ARMY_GREEN = color(102, 102, 51);
static const color TOMATO_SAUCE_RED = color(204, 51, 0);
static const color LAVENDER_PURPLE = color(203, 204, 255);
static const color PLUMP_PEACH = color(255, 170, 128);
static const color CHOCOLATE_BROWN = color(102, 51, 0);
static const color MINTY_GREEN = color(128, 255, 212);
static const color NIGHT_SKY_BLUE = color(0, 51, 102);
static const color PINAPPLE_YELLOW = color(255, 255, 51);
static const color DIRTY_SNOW = color(230, 230, 230);
static const color INTENSE_BLACK = color(0, 0, 0);




class Circle : public Shape2D{

public:
    //Constructors
    Circle();
    explicit Circle(double radius);
    explicit Circle(color fill);
    explicit Circle(color fill, double radius);
    explicit Circle(point2D center);
    Circle(double x, double y);
    Circle(color fill, point2D center);
    Circle(color fill, double x, double y);
    Circle(color fill, double x, double y, double radius);
    Circle(double red, double green, double blue, double alpha);
    Circle(double red, double green, double blue, double alpha, double radius);
    Circle(double red, double green, double blue, double alpha, point2D center);
    Circle(double red, double green, double blue, double alpha, point2D center, double radius);
    Circle(double red, double green, double blue, double alpha, double x, double y);
    Circle(double red, double green, double blue, double alpha, double x, double y, double radius);

    // Deconstructor
    ~Circle() override = default;

    double getRadius() const;

    void setRadius(double radius);
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    virtual void moveY(double deltaY);




private:
    shapeType circle;
    double radius;
    int defaultValue = 5 ;
    const int defX = 5;
    const int defY = 5;


};


#endif //SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H
