//
// Created by Sydney Hildreth on 4/27/20.
//

#include "shape.h"
#include <iostream>
using namespace std;

/********************* Color Struct ********************/

color::color() : red(0.0), green(0.0), blue(0.0), alpha(1.0) {
}

color::color(double r, double g, double b, double a) : red(r), green(g), blue(b), alpha(a) {
}

color::color(double r, double g, double b) : red(r), green(g), blue(b), alpha(1.0) {
}

ostream& operator << (ostream& outs, const color &c) {
    outs << "(" << c.red << ", " << c.green << ", " << c.blue << ")";
    return outs;
}

/********************* Shape Class *********************/

Shape::Shape() : fill({0.0, 0.0, 0.0}) {
}

Shape::Shape(color fill) : fill(fill) {
}

Shape::Shape(double red, double green, double blue, double alpha) : fill({red, green, blue, alpha}) {
}

Shape::~Shape() = default;

color Shape::getColor() const {
    return fill;
}

double Shape::getRed() const {
    return fill.red;
}

double Shape::getGreen() const {
    return fill.green;
}

double Shape::getBlue() const {
    return fill.blue;
}

double Shape::getOpacity() const {
    return fill.alpha;
}

string Shape::getType() const {
    switch (type) {
        case circle: return "circle";
        case square: return "square";
        case rectangle: return "rectangle";
        case triangle: return "triangle";
        case parallelogram: return "parallelogram";
        case ellipse: return "ellipse";
        case trapezoid: return "trapezoid";
        case cube: return "cube";
        case rectangularPrism: return "rectangular prism";
        case triangularPrism: return "triangular prism";
        case sphere: return "sphere";
        case triangularPyramid: return "triangular pyramid";
        case squarePyramid: return "square pyramid";
        case cylinder: return "cylinder";
        case cone: return "cone";
        case ellipsoid: return "ellipsoid";
        case torus: return "torus";
    }
}

void Shape::setColor(color c) {
    fill = c;
}

void Shape::setColor(double r, double g, double b, double a) {
    fill = {r, g, b, a};
}

void Shape::setRed(double r) {
    fill.red = r;
}

void Shape::setGreen(double g) {
    fill.green = g;
}

void Shape::setBlue(double b) {
    fill.blue = b;
}

void Shape::setOpacity(double a) {
    fill.alpha = a;
}