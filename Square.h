//
// Created by Sidhanth Kafley on 4/28/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H

#include "shape.h"
#include "shape2d.h"


class Square: public Shape2D{

private:
    double side;

public:
    //Constructor
    Square();
    Square(color fill);
    Square(double x, double y);
    Square(point2D center, double side);
    Square(double side);
    Square(double red, double green, double blue, double alpha, double side);

    //Destructor
    ~Square() override = default;

    //Getters
    double getSide() const;

    //Setters
    void setSide(double pSide);

    //Override virtual methods
    virtual double calculateArea() const override;
    virtual double calculatePerimeter() const override;
    virtual void move(double deltaX, double deltaY) override;;
    virtual void moveX(double deltaX) override;
    virtual void moveY(double deltaY) override;
};

#endif //SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H
