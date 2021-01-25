#include <iostream>
#include <cmath>
using namespace std;

#ifndef __Complex_defined__
#define __Complex_defined__

class complex
{
    private:
        double a, b;
    public:
        complex(double = 0, double = 0);
        double GetA() const;
        double GetB() const;
        void SetA(double Re);
        void SetB(double Im);
        //Complex operator = (const Complex&) const;
        complex operator + (const complex&) const;
        complex operator - (const complex&) const;
        complex operator * (const complex&) const;
        complex operator / (const complex&) const;
        bool operator != (const complex&) const;
        bool operator == (const complex&) const;
        friend ostream& operator <<(ostream&, const complex&);
};
#endif