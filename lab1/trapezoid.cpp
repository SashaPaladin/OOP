#include "trapezoid.h"
#include <cmath>

void Trapezoid::Print(ostream& os) {
    cout << "Trapezoid: " << a << ", " << b << ", " << c << ", " << d << endl;
}

double Trapezoid::Area() {
    double k = (a.y_ - d.y_) / (a.x_ - d.x_);
    double m = a.y_- k * a.x_;
    double h = abs(b.y_- k * b.x_ - m) / sqrt(1 + k * k);
    return 0.5 * (a.dist(d) + b.dist(c)) * h;
}

Trapezoid::Trapezoid() : a(), b(), c(), d() {
    cout << "Default trapezoid was created" << endl;
}

Trapezoid::Trapezoid(vector<Point> v) : a(v[0]), b(v[1]), c(v[2]), d(v[3]) {
    cout << "Trapezoid with vertices " << a << ", " << b << ", " << c << ", " << d << " was created" << endl;
}

Trapezoid::Trapezoid(istream &is) {
    cout << "Enter lower left coordinate" << endl;
    cin >> a;
    cout << "Enter upper left coordinate" << endl;
    cin >> b;
    cout << "Enter upper right coordinate" << endl;
    cin >> c;
    cout << "Enter lower right coordinate" << endl;
    cin >> d;
    cout << "Trapezoid was created" << endl;
}

Trapezoid::Trapezoid(const Trapezoid &other) : a(other.a), b(other.b), c(other.c), d(other.d) {
    cout << "Made copy of trapezoid" << endl;
}

Trapezoid::~Trapezoid() {
    cout << "Trapezoid was deleted" << endl;
}

size_t Trapezoid::VertexesNumbers() {
    return 4;
}