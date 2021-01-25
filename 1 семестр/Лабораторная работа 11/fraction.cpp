#include "fraction.h"
int fraction::next_id = 0;

void fraction:: con()
{
    if(b < 0 && a)
    {
        a = -a;
        b = -b;
    }
    int c = nod(abs(a), b);
    if(c != 1)
    {
        a /= c;
        b /= c;
    }
}
int fraction:: nod(int ch, int zn)
{
	if (zn == 0)
		return ch;
	else
		return nod(zn, ch % zn);
}
fraction:: fraction(): a(0), b(1), id(++next_id) {}
fraction:: fraction(int ch, int zn): a(ch), b(zn), id(fraction::next_id++)
{
    if(!b)
        throw Bad("Fraction with these parameters can't be created");
    con();
}
fraction fraction:: operator ! () const
{
    if(!a)
        throw Bad("It's impossible to rotate this fraction");
    if(a < 0)
        return fraction(-b, -a);
    else
        return fraction(b, a);
}
fraction& fraction:: operator = (const fraction& c) 
{
    if (this != &c)
    {
        a = c.a;
        b = c.b;
    }
    return *this;
}
fraction& fraction:: operator = (const int& c) 
{
    a = c;
    b = 1;
    return *this;
}
fraction& fraction:: operator += (const fraction& c)
{
    a = c.b * a + c.a * b;
    b = b * c.b;
    con();
    return *this;
}
fraction& fraction:: operator -= (const fraction& c)
{
    a = c.b * a - c.a * b;
    b = b * c.b;
    con();
    return *this;
}
fraction& fraction:: operator *= (const fraction& c)
{
    a = c.a * a;
    b = b * c.b;
    con();
    return *this;
}
fraction& fraction:: operator /= (const fraction& c)
{
    if(c.a)
    {
        a = c.b * a;
        b = b * c.a;
        con();
        return *this;
    }
    else
        throw Bad("Div by 0");
}
fraction fraction:: operator + (const fraction& c)
{
    return fraction(c.a * b + c.b * a, b * c.b);
}
fraction fraction:: operator + (const int& c)
{
    return fraction(a + c * b, b);
}
fraction operator + (int x, const fraction& c)
{
    return fraction(c.a + x * c.b, c.b);
}
fraction fraction:: operator - (const fraction& c)
{
    return fraction(c.b * a - c.a * b, b * c.b);
}
fraction fraction:: operator - (const int& c)
{
    return fraction(a - c * b, b);
}
fraction operator - (int x, const fraction& c)
{
    return fraction(x * c.b - c.a, c.b);
}
fraction fraction:: operator * (const fraction& c)
{
    return fraction(c.a * a, c.b * b);
}
fraction fraction:: operator * (const int& c)
{
    return fraction(a * c, b);
}
fraction operator * (int x, const fraction& c)
{
    return fraction(c.a * x, c.b);
}
fraction fraction:: operator / (const fraction& c)
{
    if(c.a)
        return fraction(a * c.b, b * c.a);
    else
        throw Bad("Div by 0");
}
fraction fraction:: operator / (const int& c)
{
    if(c)
        return fraction(a, b * c);
    else
        throw Bad("Div by 0");
}
fraction operator / (int x, const fraction& c)
{
    if(c.a)
        return fraction(x * c.b, c.a);
    else
        throw fraction:: Bad("Div by 0");
}
bool fraction:: operator == (const fraction& c) const
{
    return((a == c.a) && (b == c.b));
}
bool fraction:: operator != (const fraction& c) const
{
    return((a != c.a) || (b != c.b));
}
ostream& operator << (ostream& cout, const fraction& c)
{
    if (c.b == 1 || c.a == 0)
        cout << c.a;
    else
        cout << c.a << "/" << c.b;
    return cout;
}
istream& operator >> (istream& cin, fraction& c)
{
    int ch, zn = 1;
    char d;
    cin >> ch;
    cin.get(d);
    if (d == '/')
        cin >> zn;
    else
        cin.putback(d);
    c = fraction(ch, zn);
    return cin;
}