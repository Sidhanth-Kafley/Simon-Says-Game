//
// Created by Sydney Hildreth on 4/27/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H

#include "Shape2d.h"
#include <cmath>


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
    virtual void move(double deltaX, double deltaY) override;
    virtual void moveX(double deltaX) override ;
    virtual void moveY(double deltaY) override ;

    //virtual void draw() = 0;
    void draw() const override;


private:
    shapeType circle;
    double radius;
    int defaultValue = 5 ;
    const int defX = 5;
    const int defY = 5;


};


#endif //SH_SK_FINAL_PROJECT_GRAPHICS_CIRCLE_H
