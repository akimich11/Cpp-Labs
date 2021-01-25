#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    private:
        struct Repeater
        {
            char* s;
            int n;
            Repeater() { n = 1; }
        };
        Repeater* repeat;
        void Clone(const MyString &);
        void Erase();
    public:
        MyString();
        MyString(const char*);
        MyString(const MyString&);
        ~MyString();
        MyString& operator = (const char*);
        MyString& operator = (const MyString&);
        bool operator == (const MyString&) const;
        bool operator != (const MyString&) const;
        bool operator > (const MyString&) const;
        bool operator < (const MyString&) const;
        MyString operator + (const MyString&);
        MyString operator + (const char*);
        int size() const;
        char operator [] (int) const;
        friend istream& operator >> (istream&, MyString&);
        friend ostream& operator << (ostream&, const MyString&);
};
