#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <iostream>


class Trapezoid : public Figure {
    public:
    Trapezoid(std::istream &InputStream);
    Trapezoid();
    double GetArea();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);
    friend bool operator == (Trapezoid& p1, Trapezoid& p2);
    friend std::ostream& operator << (std::ostream& os, Trapezoid& p);
    virtual ~Trapezoid();
    double area;

    private:
    Point a;
    Point b;
    Point c;
    Point d;
};
#endif
