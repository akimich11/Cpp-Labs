#include "complex.h"

complex::complex(double Re, double Im): a(Re), b(Im){}

/*double complex::GetA() const {return a;}
double complex::GetB() const {return b;}
void complex::SetA(double Re) {a = Re;}
void complex::SetB(double Im) {b = Im;}*/

complex complex::operator + (const complex& c) const
{
    return complex(a + c.a, b + c.b);
}
complex complex::operator - (const complex& c) const
{
    return complex(a - c.a, b - c.b);
}
complex complex::operator * (const complex& c) const
{
    return complex(a*c.a - b*c.b, a*c.b + b*c.a);
}
complex complex::operator / (const complex& c) const
{
    if(c.a == 0 && c.b == 0)
        throw "Div by 0";
    return complex((a*c.a + b*c.b) / (a*c.a + b*c.b), (a*c.b - b*c.a) / (a*c.a + b*c.b));
}
bool complex::operator == (const complex& c) const
{
    return ((a == c.a) && (b == c.b));
}
bool complex::operator != (const complex& c) const
{
    return ((a != c.a) || (b != c.b));
    //return (!(this->operator==(c)));
}
ostream& operator <<(ostream& cout, const complex& c)
{
    if(c.b > 0 && c.b != 1)
        cout << c.a << "+" << c.b << "i";
    else if(c.b < 0 && c.b != -1)
        cout << c.a << c.b << "i";
    else if(c.b == 1)
        cout << c.a <<"+i";
    else if(c.b == -1)
        cout << c.a <<"-i";
    else
        cout << c.a;
    return cout;
}