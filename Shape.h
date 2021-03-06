//
// Created by Sydney Hildreth on 4/27/20.
//

#ifndef SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE_H
#define SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE_H

#include <cmath> // This allows you to use sqrt and pow functions
#include <string>

const double PI = 3.14159265358979323846;

struct color {
    double red;
    double green;
    double blue;
    double alpha; // Opacity (0 is transparent, 1 is solid)

    /* Constructors */
    color();
    color(double r, double g, double b);
    color(double r, double g, double b, double a);


    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const color &c);
};

struct point {
    int x;
    int y;
};

class Shape {
protected:
    enum shapeType {
        circle,
        square
    };
    color fill;
    shapeType type;

public:
    /* Constructors */
    Shape();
    explicit Shape(color fill);
    Shape(double red, double green, double blue, double alpha);

    /* Destructor */
    virtual ~Shape() = 0;

    /* Getters */
    color getColor() const;
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getOpacity() const;
    std::string getType() const;


    /* Setters */
    void setColor(color c);
    void setColor(double r, double g, double b, double a);
    void setRed(double r);
    void setGreen(double g);
    void setBlue(double b);
    void setOpacity(double a);



    //virtual void draw() = 0;
   // virtual void draw() const;
    virtual void draw() const = 0;
};

#endif //SH_SK_FINAL_PROJECT_GRAPHICS_SHAPE_H
