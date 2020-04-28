//
// Created by Sydney Hildreth on 4/27/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE2D_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE2D_H

#include <iomanip>
#include <iostream>
#include "shape.h"

struct point2D {
    double x;
    double y;

    /* Constructors */
    point2D();
    point2D(double x, double y);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const point2D &p);
};

class Shape2D : public Shape {
protected:
    point2D center;
public:
    /* Constructors */
    Shape2D();
    explicit Shape2D(color fill);
    explicit Shape2D(point2D center);
    Shape2D(color fill, point2D center);
    Shape2D(double red, double green, double blue, double alpha);
    Shape2D(double red, double green, double blue, double alpha, point2D center);
    Shape2D(double red, double green, double blue, double alpha, double x, double y);
    Shape2D(double x, double y);
    Shape2D(color fill, double x, double y);

    /* Destructor */
    ~Shape2D() override = default;

    /* Getters */
    point2D getCenter() const;
    double getCenterX() const;
    double getCenterY() const;

    /* Setters */
    void setCenter(point2D center);
    void setCenter(double x, double y);
    void setCenterX(double x);
    void setCenterY(double y);
    virtual void move(double deltaX, double deltaY);
    virtual void moveX(double deltaX);
    virtual void moveY(double deltaY);



    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const Shape2D &shape);
};

#endif //SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE2D_H
