#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

using namespace std;

int main () {
    Square Sqr1;
    Point a(0, 0);
    Point b(0, 1);
    Point c(1, 1);
    Point d(1, 0);
    vector<Point> v{a, b, c, d};
    Square Sqr2(v);
    Square Sqr3(cin);
    Square Sqr4(Sqr3);
    Sqr1.Print(cout);
    cout << Sqr2.VertexesNumbers() << endl;
    cout << "Square area is " << Sqr2.Area() << endl;
    Figure *f = new Square(Sqr2);
    delete f;

    Rectangle Rec1;
    Rectangle Rec2(v);
    Rectangle Rec3(cin);
    Rectangle Rec4(Rec3);
    Rec1.Print(cout);
    cout << Rec1.VertexesNumbers() << endl;
    cout << "Rectangle area is " << Rec2.Area() << endl;
    f = new Rectangle(Rec2);
    delete f;

    Trapezoid Trp1;
    Point atr(0,0), btr(1, 1), ctr(2, 1), dtr(3, 0);
    vector<Point> tr{atr, btr, ctr, dtr};
    Trapezoid Trp2(tr);
    Trapezoid Trp3(cin);
    Trapezoid Trp4(Trp1);
    cout << "Trapezoid area is " << Trp2.Area() << endl;
    Trp3.Print(cout);
    cout << Trp4.VertexesNumbers() << endl;
    f = new Trapezoid(Trp4);
    delete f;
    return 0;
}

