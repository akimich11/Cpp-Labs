#pragma once
#include <string>
#include <iostream>
using namespace std;

class Author 
{
    private:
        string surname;
        string name;
        string lastname;
        void Clone(const Author&);
    public:
        Author(string, string, string);
        Author(const Author&);
        string GetSurname() const { return surname; }
        string GetName() const { return name; }
        string GetLastname() const { return lastname; }
        Author& operator = (const Author&);
        bool operator < (const Author&) const;
        bool operator > (const Author&) const;
        bool operator == (const Author&) const;
        friend ostream& operator << (ostream&, const Author&);
};