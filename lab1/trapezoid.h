#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

using namespace std;

class Trapezoid : public Figure {
public:
    Trapezoid();

    Trapezoid(vector<Point> v);

    Trapezoid(istream &is);

    Trapezoid(const Trapezoid &other);

    void Print(ostream &os);

    size_t VertexesNumbers();

    double Area() override;

    virtual ~Trapezoid();

private:
    Point a, b, c, d;
};

#endif //TRAPEZOID_H
