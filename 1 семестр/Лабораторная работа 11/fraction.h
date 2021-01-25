#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;

#pragma once

class fraction
{
    private:
	    int a;
	    int b;
		static int next_id;
	 	int id;
	    void con();
    public:
	    int nod(int a, int b);
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
	    
		fraction();
	    fraction(int, int);
	    
		int GetA() const { return a; }
	    int GetB() const { return b; }
		int GetID() { return id; }
	    void SetA(int);
	    void SetB(int);
	    
		fraction operator ! () const;
        fraction operator - () { a = -a; return *this; };
		
		fraction operator ++ (int) { a += b; return *this; };
		fraction operator -- (int) { a -= b; return *this; };
		fraction& operator ++ () { a += b; return *this; };
	    fraction& operator -- () { a -= b; return *this; };
	    
		fraction& operator = (const fraction&);
	    fraction& operator = (const int&);
	    
		fraction& operator += (const fraction&);
		fraction& operator -= (const fraction&);
		fraction& operator *= (const fraction&);
		fraction& operator /= (const fraction&);
		fraction& operator += (const int& c) { a += c * b; };
		fraction& operator -= (const int& c) { a -= c * b; };
		fraction& operator *= (const int& c) { a *= c; };
		fraction& operator /= (const int& c) { if(c) b *= c; else throw Bad("Div by 0"); };
		
		fraction operator + (const fraction&);
		fraction operator - (const fraction&);
		fraction operator * (const fraction&);
		fraction operator / (const fraction&);
		fraction operator + (const int&);
		fraction operator - (const int&);
		fraction operator * (const int&);
		fraction operator / (const int&);
		friend fraction operator + (int, const fraction&);
		friend fraction operator - (int, const fraction&);
		friend fraction operator * (int, const fraction&);
		friend fraction operator / (int, const fraction&);
	    
		bool operator == (const fraction&) const;
	    bool operator != (const fraction&) const;
	    
		friend ostream& operator << (ostream&, const fraction&);
	    friend istream& operator >> (ostream&, fraction&);
	    operator double() { return a / (double)b; }
};