#include "trapezoid.h"
#include <cmath>

    Trapezoid::Trapezoid() {}

    Trapezoid::Trapezoid(std::istream &InputStream)
  {
      InputStream >> a;
      InputStream >> b;
      InputStream >> c;
      InputStream >> d;
      std:: cout << "Trapezoid that you wanted to create has been created" << std:: endl;
  }

  void Trapezoid::Print(std::ostream &OutputStream) {
      OutputStream << "Trapezoid: ";
      OutputStream << a << " " << b << " " << c << " " << d << std:: endl;
      
  }

   size_t Trapezoid::VertexesNumber() {
       size_t number = 4;
       return number;
   }

   double Trapezoid::Area() {
    double k = (a.Y() - d.Y()) / (a.X() - d.X());
    double m = a.Y() - k * a.X();
    double h = abs(b.Y() - k * b.X() - m) / sqrt(1 + k * k);
    return 0.5 * (a.dist(d) + b.dist(c)) * h;
   }

   double Trapezoid:: GetArea() {
       return area;
   }

    Trapezoid::~Trapezoid() {
          std:: cout << "My friend, your trapezoid has been deleted" << std:: endl;
      }

    bool operator == (Trapezoid& p1, Trapezoid& p2){
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d) {
            return true;
        }
        return false;
    }

    std::ostream& operator << (std::ostream& os, Trapezoid& p){
    os << "Trapezoid: ";
    os << p.a << p.b << p.c << p.d;
    os << std::endl;
    return os;
}