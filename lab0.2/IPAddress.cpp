#include "IPAddress.h"
#include <string>

IPAddress::IPAddress() : a(0), b(0), c(0), d(0)
{}

IPAddress::IPAddress(uc _a, uc _b, uc _c, uc _d) : a(_a), b(_b), c(_c), d(_d)
{}

void IPAddress::Print() const
{
    printf("%d %d %d %d\n", a, b, c, d);
}

bool IPAddress::Check(IPAddress Address, IPAddress Mask) const
{
    if (Mask.a == 0)
    {
        return ((Address.a == 0)&&(Address.b == 0)&&(Address.c == 0)&&(Address.d == 0));
    }
    if (Mask.a < 255)
    {
        return ((Address.b == 0)&&(Address.c == 0)&&(Address.d == 0)&&(Mask.a + a - 255 == Address.a));
    }
    if (Mask.b == 0)
    {
        return ((a == Address.a)&&(Address.b == 0)&&(Address.c == 0)&&(Address.d == 0));
    }
    if (Mask.b < 255)
    {
        return ((a == Address.a)&&(Mask.b + b - 255 == Address.b)&&(Address.c == 0)&&(Address.d == 0));
    }
    if (Mask.c == 0)
    {
        return ((a == Address.a)&&(b == Address.b)&&(Address.c == 0)&&(Address.d == 0));
    }
    if (Mask.c < 255)
    {
        return ((a == Address.a)&&(b == Address.b)&&(Mask.c + c - 255 == Address.c)&&(Address.d == 0));
    }
    if (Mask.d == 0)
    {
        return ((a == Address.a)&&(b == Address.b)&&(c == Address.c)&&(Address.d == 0));
    }
    if (Mask.d < 255)
    {
        return ((a == Address.a)&&(b == Address.b)&&(c == Address.c)&&(Mask.d + d - 255 == Address.d));
    }
    return true;
}

char* IPAddress::Get() const
{
    int _a = a;
    int _b = b;
    int _c = c;
    int _d = d;
    char* s = new char [16];
    int t = 0;
    string buff = to_string(_a);
    for (int i = 0; i < buff.length(); ++i)
    {
        s[t + i] = buff[i];
    }
    t += buff.length();
    s[t] = ' ';
    ++t;
    buff = to_string(_b);
    for (int i = 0; i < buff.length(); ++i)
    {
        s[t + i] = buff[i];
    }
    t += buff.length();
    s[t] = ' ';
    ++t;
    buff = to_string(_c);
    for (int i = 0; i < buff.length(); ++i)
    {
        s[t + i] = buff[i];
    }
    t += buff.length();
    s[t] = ' ';
    ++t;
    buff = to_string(_d);
    for (int i = 0; i < buff.length(); ++i)
    {
        s[t + i] = buff[i];
    }
    return s;
}

IPAddress operator+(IPAddress A, IPAddress B)
{
    unsigned _a = (A.a + B.a) % 256;
    unsigned _b = (A.b + B.b) % 256;
    unsigned _c = (A.c + B.c) % 256;
    unsigned _d = (A.d + B.d) % 256;
    return IPAddress(_a, _b, _c, _d);
}

IPAddress operator-(IPAddress A, IPAddress B)
{
    int _a = (A.a - B.a) % 256;
    int _b = (A.b - B.b) % 256;
    int _c = (A.c - B.c) % 256;
    int _d = (A.d - B.d) % 256;
    return IPAddress(_a, _b, _c, _d);
}

bool operator==(IPAddress A, IPAddress B)
{
    return ((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c)&&(A.d == B.d));
}

bool operator!=(IPAddress A, IPAddress B)
{
    return !((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c)&&(A.d == B.d));
}

bool operator>(IPAddress A, IPAddress B)
{
    if ((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c))
    {
        return A.d > B.d;
    }
    if ((A.a == B.a)&&(A.b == B.b))
    {
        return A.c > B.c;
    }
    if (A.a == B.a)
    {
        return A.b > B.b;
    }
    return A.a > B.a;
}

bool operator<(IPAddress A, IPAddress B)
{
    if ((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c))
    {
        return A.d < B.d;
    }
    if ((A.a == B.a)&&(A.b == B.b))
    {
        return A.c < B.c;
    }
    if (A.a == B.a)
    {
        return A.b < B.b;
    }
    return A.a < B.a;
}

bool operator>=(IPAddress A, IPAddress B)
{
    if ((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c))
    {
        return A.d >= B.d;
    }
    if ((A.a == B.a)&&(A.b == B.b))
    {
        return A.c > B.c;
    }
    if (A.a == B.a)
    {
        return A.b > B.b;
    }
    return A.a > B.a;
}

bool operator<=(IPAddress A, IPAddress B)
{
    if ((A.a == B.a)&&(A.b == B.b)&&(A.c == B.c))
    {
        return A.d <= B.d;
    }
    if ((A.a == B.a)&&(A.b == B.b))
    {
        return A.c < B.c;
    }
    if (A.a == B.a)
    {
        return A.b < B.b;
    }
    return A.a < B.a;
}