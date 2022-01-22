#ifndef OOP_IPADRESS_H
#define OOP_IPADRESS_H

#include <iostream>
using namespace std;

typedef unsigned char uc;

class IPAddress {
public:
    IPAddress();
    IPAddress(uc _a, uc _b, uc _c, uc _d);

    friend IPAddress operator+(IPAddress A, IPAddress B);
    friend IPAddress operator-(IPAddress A, IPAddress B);
    friend bool operator==(IPAddress A, IPAddress B);
    friend bool operator!=(IPAddress A, IPAddress B);
    friend bool operator<(IPAddress A, IPAddress B);
    friend bool operator>(IPAddress A, IPAddress B);
    friend bool operator<=(IPAddress A, IPAddress B);
    friend bool operator>=(IPAddress A, IPAddress B);

    void Print() const;

    bool Check(IPAddress Address, IPAddress Mask) const;

    char* Get() const;

private:
    uc a;
    uc b;
    uc c;
    uc d;
};


#endif //OOP_IPADRESS_H
