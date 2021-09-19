#include "rectangle.h"

void Rectangle::Print(ostream &os) {
    cout << "Rectangle: " << a << ", " << b << ", " << c << ", " << d << endl;
}

double Rectangle::Area(){
    return (abs(a.x_ - b.x_) * abs(a.y_ - b.y_));
}

Rectangle::Rectangle() : a(), b() {
    cout << "Default rectangle is created" << endl;
}

Rectangle::Rectangle(vector<Point> v) : a(v[0]), b(v[1]), c(v[2]), d(v[3]) {
    cout << "Rectangle with vertices " << a << ", " << b << ", " << c << ", " << d << " was created"
    << endl; // создание с помощью вектора координат вершин
}

Rectangle::Rectangle(istream &is) {
    cout << "Enter lower left coordinate" << endl;
    cin >> a;
    cout << "Enter upper left coordinate" << endl;
    cin >> b;
    cout << "Enter upper right coordinate" << endl;
    cin >> c;
    cout << "Enter lower right coordinate" << endl;
    cin >> d;
    cout << "Rectangle was created via stream" << endl;
}

Rectangle::Rectangle(const Rectangle &other) : a(other.a), b(other.b), c(other.c), d(other.d) {
    cout << "Made copy of rectangle" << endl;
}

Rectangle::~Rectangle() {
    cout << "Rectangle was deleted" << endl;
}

size_t Rectangle::VertexesNumbers() {
    return 4;
}