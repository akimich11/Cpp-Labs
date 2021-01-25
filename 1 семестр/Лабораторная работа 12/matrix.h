#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

#pragma once

class matrix
{
    private:
        int **Matr;
        int m;
        int n;
        void create();
    public:
        class Bad 
		{
			private:
				char* message;
				void operator = (const Bad& e) {}
			public:
				Bad(const char* str) 
				{
					assert(str != NULL);
					message = new char[strlen(str) + 1];
					strcpy(message, str);
				}
				Bad(const Bad& e)
				{
					message = new char [strlen(e.message) + 1];
					strcpy(message, e.message);
				}
				const char* getMessage() const { return message; }
				~Bad() { delete [] message; }
		};
        matrix(): m(5), n(5) { create(); }
        matrix(int i): m(i), n(i) { create(); }
        matrix(int i, int j): m(i), n(j) { create(); }
        matrix(const matrix&);
        ~matrix();
        int GetM() const{ return m; };
        int GetN() const{ return n; };
        int GetEl(int i, int j) const{ return Matr[i][j]; };
        void SetEl(int, int, int);

        void check1(const matrix&) const;
        void check2(const matrix&) const;

        matrix operator + (const matrix&);
        matrix operator - (const matrix&);
        matrix operator * (const matrix&);
        matrix operator * (const int);
        matrix operator / (const int);
        matrix& operator += (const matrix&);
		matrix& operator -= (const matrix&);
		matrix& operator *= (const matrix&);
        matrix& operator *= (const int);
        matrix& operator /= (const int);
        friend matrix operator * (int, const matrix&);

        matrix& operator = (const matrix&);

        friend ostream& operator << (ostream&, const matrix&);
        friend istream& operator >> (istream&, matrix&);
};