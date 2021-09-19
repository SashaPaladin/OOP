#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

using namespace std;

class Rectangle : public Figure {
public:
    Rectangle();

    Rectangle(vector<Point> v);

    Rectangle(istream &is);

    Rectangle(const Rectangle &other);

    void Print(ostream &os);

    size_t VertexesNumbers();

    double Area() override;

    virtual ~Rectangle();

private:
    Point a, b, c, d;
};


#endif