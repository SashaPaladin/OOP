#include "square.h"
#include <cmath>

void Square::Print(ostream& os) {
    cout << "Trapezoid: " << a << ", " << b << ", " << c << ", " << d << endl;
}

double Square::Area() {
    double k = (a.y_ - d.y_) / (a.x_ - d.x_);
    double m = a.y_- k * a.x_;
    double h = abs(b.y_- k * b.x_ - m) / sqrt(1 + k * k);
    return 0.5 * (a.dist(d) + b.dist(c)) * h;
}

Square::Square() : a(), b(), c(), d() {
    cout << "Default square was created" << endl;
}

Square::Square(vector<Point> v) : a(v[0]), b(v[1]), c(v[2]), d(v[3]) {
    cout << "Square with vertices " << a << ", " << b << ", " << c << ", " << d << " was created" << endl;
}

Square::Square(istream &is) {
    cout << "Enter lower left coordinate" << endl;
    cin >> a;
    cout << "Enter upper left coordinate" << endl;
    cin >> b;
    cout << "Enter upper right coordinate" << endl;
    cin >> c;
    cout << "Enter lower right coordinate" << endl;
    cin >> d;
    cout << "Square was created" << endl;
}

Square::Square(const Square &other) : a(other.a), b(other.b), c(other.c), d(other.d) {
    cout << "Made copy of square" << endl;
}

Square::~Square() {
    cout << "Square was deleted" << endl;
}

size_t Square::VertexesNumbers() {
    return 4;
}