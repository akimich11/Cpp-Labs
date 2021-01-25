#include "matrix.h"

matrix:: matrix (const matrix& c)
{
    m = c.m;
    n = c.n;
    create();
    for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                Matr[i][j] = c.Matr[i][j];
}
matrix:: ~matrix()
{
    for (int i = 0; i < m; i++)
        delete[] Matr[i];
    delete[] Matr;
    Matr = NULL;
}
void matrix:: create()
{
    Matr = new int*[m];
    for (int z = 0; z < m; z++)
        Matr[z] = new int[n];
}
void matrix:: check1(const matrix& c) const
{
    if (n != c.n || m != c.m)
        throw Bad("Additation can't be done");
}
void matrix:: check2(const matrix& c) const
{
    if(n != c.m)
        throw Bad("Multiplication can't be done");
}
void matrix:: SetEl(int i, int j, int x)
{
    Matr[i][j] = x;
}
matrix matrix:: operator + (const matrix& c)
{
    check1(c);
    matrix d(m, n);
    for(int i = 0; i < d.GetM(); i++)
            for(int j = 0; j < d.GetN(); j++)
                d.Matr[i][j] = Matr[i][j] + c.Matr[i][j];
    return d;
}
matrix matrix:: operator - (const matrix& c)
{
    check1(c);   
    matrix d(m, n);
    for(int i = 0; i < d.GetM(); i++)
            for(int j = 0; j < d.GetN(); j++)
                d.Matr[i][j] = Matr[i][j] - c.Matr[i][j];
    return d;
}
matrix matrix:: operator * (const matrix& c)
{
    check2(c);
    matrix d(m, c.n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < c.n; j++)
        {
            d.Matr[i][j] = 0;
            for (int k = 0; k < n; k++)
                d.Matr[i][j] += Matr[i][k] * c.Matr[k][j];
        }
    return d;
}
matrix matrix:: operator * (const int c)
{
    matrix d(m, n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            d.Matr[i][j] = Matr[i][j] * c;
    return d;
}
matrix operator * (int x, const matrix& c)
{
    matrix d(c.m, c.n);
    for(int i = 0; i < c.m; i++)
        for(int j = 0; j < c.n; j++)
            d.Matr[i][j] = c.Matr[i][j] * x;
    return d;
}
matrix matrix:: operator / (const int c)
{
    matrix d(m, n);
    if(c)
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                d.Matr[i][j] = Matr[i][j] / c;
    }
    else
        throw Bad("Div by 0");
    return d;
}
matrix& matrix:: operator += (const matrix& c)
{
    *this = *this + c;
    return *this;
}
matrix& matrix:: operator -= (const matrix& c)
{
    *this = *this - c;
    return *this;
}
matrix& matrix:: operator *= (const matrix& c)
{
    *this = *this * c;
    return *this;
}
matrix& matrix:: operator *= (const int c)
{
    *this = *this * c;
    return *this;
}
matrix& matrix:: operator /= (const int c)
{
    *this = *this / c;
    return *this;
}
matrix& matrix:: operator = (const matrix& c) 
{
    if (this != &c)
    {
        m = c.m;
        n = c.n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                Matr[i][j] = c.Matr[i][j];
    }
    return *this;
}
ostream& operator << (ostream& cout, const matrix& c)
{
    for(int i = 0; i < c.GetM(); i++)
    {
        for(int j = 0; j < c.GetN(); j++)
        {
            cout.width(4);
            cout << c.GetEl(i, j);
        }
        cout << endl;
    }
    return cout;
}
istream& operator >> (istream& cin, matrix& c)
{
    if(c.m == 0 || c.n == 0)
    {
        cout << "Matrix is empty" << endl;
        return cin;
    }
    cout << "Enter matrix " << c.m << " x " << c.n << " :" << endl;
    for (int i = 0; i < c.m; i++)
        for(int j = 0; j < c.n; j++)
            cin >> c.Matr[i][j];
    return cin;
}