//
// Created by Sydney Hildreth on 4/27/20.
//

#include "Shape2d.h"
using namespace std;

/********************* Point2D Struct ********************/

point2D::point2D() : x(0), y(0) {}

point2D::point2D(double x, double y) : x(x), y(y) {}

ostream& operator << (ostream& outs, const point2D &p) {
    outs << "(" << p.x << ", " << p.y << ")";
    return outs;
}

/********************* Shape2D Class *********************/

Shape2D::Shape2D() : Shape(), center({0, 0}) {
}

Shape2D::Shape2D(color fill) : Shape(fill), center({0, 0}) {
}

Shape2D::Shape2D(point2D center) : Shape(), center(center) {
}

Shape2D::Shape2D(color fill, point2D center) : Shape(fill), center(center) {
}

Shape2D::Shape2D(double red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), center({0, 0}) {
}

Shape2D::Shape2D(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha), center(center) {
}

Shape2D::Shape2D(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha), center({x, y}) {
}

Shape2D::Shape2D(double x, double y) : Shape(), center({x, y}) {
}

Shape2D::Shape2D(color fill, double x, double y) : Shape(fill), center({x, y}) {
}

point2D Shape2D::getCenter() const {
    return center;
}

double Shape2D::getCenterX() const {
    return center.x;
}

double Shape2D::getCenterY() const {
    return center.y;
}

void Shape2D::setCenter(point2D center) {
    this->center = center;
}

void Shape2D::setCenter(double x, double y) {
    center = {x, y};
}

void Shape2D::setCenterX(double x) {
    center.x = x;
}

void Shape2D::setCenterY(double y) {
    center.y = y;
}

void Shape2D::move(double deltaX, double deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Shape2D::moveX(double deltaX) {
    center.x += deltaX;
}

void Shape2D::moveY(double deltaY) {
    center.y += deltaY;
}

ostream& operator << (std::ostream& outs, const Shape2D &shape) {
    outs << left << setw(20) << shape.getType() << right <<
         setw(15) << shape.getColor() <<
         setw(15) << shape.getCenter();
    return outs;
}

