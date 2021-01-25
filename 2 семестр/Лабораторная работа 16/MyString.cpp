#include "MyString.h"

void MyString::Clone(const MyString &P)
{
    repeat = P.repeat;
    repeat -> n++;
}

void MyString::Erase()
{
    if (--(repeat -> n) == 0)
    {
        delete[] repeat -> s;
        delete repeat;
    }
}

MyString::MyString() : repeat(new Repeater) {}

MyString::MyString(const char* st) : repeat(new Repeater)
{
    repeat -> s = new char[strlen(st) + 1];
    strcpy(repeat -> s, st);
}

MyString::MyString(const MyString &P)
{
    Clone(P);
}

MyString::~MyString()
{
    Erase();
}

MyString & MyString::operator = (const char *st)
{
    if (repeat -> n > 1)
    {
        --repeat -> n;
        repeat = new Repeater;
    }
    else
        delete repeat -> s;
    repeat -> s = new char[strlen(st) + 1];
    strcpy(repeat -> s, st);
    return *this;
}

MyString& MyString::operator = (const MyString &P)
{
    if (this != &P)
    {
        Erase();
        Clone(P);
    }
    return *this;
}

bool MyString::operator == (const MyString &P) const
{
    return strcmp(repeat -> s, P.repeat -> s) == 0;
}

bool MyString::operator != (const MyString &P) const
{
    return !(*this == P);
}

bool MyString::operator > (const MyString &P) const
{
    return strcmp(repeat -> s, P.repeat -> s) > 0;
}

bool MyString::operator < (const MyString &P) const
{
    return strcmp(repeat -> s, P.repeat -> s) < 0;
}

MyString MyString::operator + (const MyString &P)
{
    MyString P2;
    P2.repeat -> s = new char[strlen(repeat -> s) + strlen(P.repeat -> s) + 1];
    strcpy(P2.repeat -> s, repeat -> s);
    strcat(P2.repeat -> s, P.repeat -> s);
    return P2;
}

MyString MyString::operator + (const char* c)
{
    MyString P1(c);
    MyString P2;
    P2.repeat -> s = new char[strlen(this->repeat->s) + strlen(P1.repeat->s) + 1];
    strcpy(P2.repeat -> s, repeat -> s);
    strcat(P2.repeat -> s, P1.repeat -> s);
    return P2;
}

int MyString::size() const
{
    return (int)strlen(repeat -> s);
}

char MyString::operator [] (int i) const
{
    if (i < 0 || i >= strlen(repeat -> s))
        throw "Неверный индекс";
    return repeat -> s[i];
}

istream& operator >> (istream &cin, MyString &P)
{
    char buffer[256];
    cin >> buffer;
    P = buffer;
    return cin;
}

ostream& operator << (ostream &cout, const MyString &P)
{
    cout << P.repeat -> s << " [" << P.repeat -> n << "]";
    return cout;
}
