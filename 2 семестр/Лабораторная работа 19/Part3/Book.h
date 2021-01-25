#pragma once
#include "Author.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Book 
{
    private:
        int numberUDC;
        list<Author> authors;
        string title;
        int year;
        void Clone(const Book&);
    public:
        Book(int, list<Author>, string, int);
        Book(const Book&);
        string GetTitle() const { return title; }
        void GetAuthors(list<Author>&) const;
        void SetAuthors(list<Author>&);
        Book& operator = (const Book&);
        bool operator < (const Book&) const;
        bool operator > (const Book&) const;
        bool operator == (const Book&) const;
        friend ostream& operator << (ostream&, const Book&);
};
