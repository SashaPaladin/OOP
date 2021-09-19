#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

using namespace std;

class Square : public Figure {
public:
    Square();

    Square(vector<Point> v);

    Square(istream &is);

    Square(const Square &other);

    void Print(ostream &os);

    size_t VertexesNumbers();

    double Area() override;

    virtual ~Square();

private:
    Point a, b, c, d;
};


#endif //SQUARE_H
