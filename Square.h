//
// Created by Sidhanth Kafley on 4/28/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H

#include "Shape.h"
#include "Shape2d.h"
#include "Graphics.h"


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

    virtual void move(double deltaX, double deltaY) override;;
    virtual void moveX(double deltaX) override;
    virtual void moveY(double deltaY) override;


    void draw(int x, int y) const override;
};

#endif //SH_SK_FINAL_PROJECT_GRAPHICS_SQUARE_H
