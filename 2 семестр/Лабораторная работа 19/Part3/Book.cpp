#include "Book.h"
#include <iostream>
#include <list>
using namespace std;

void Book::Clone(const Book& B)
{
    numberUDC = B.numberUDC;
    title = B.title;
    year = B.year;
    authors.clear();
    authors.assign(B.authors.begin(), B.authors.end());
}
Book::Book(int num, list<Author> aut, string tite, int ye) : numberUDC(num), title(tite), year(ye)
{
    authors.assign(aut.begin(), aut.end());
    authors.sort();
}
Book::Book(const Book& B) 
{ 
    Clone(B); 
}
Book& Book::operator = (const Book& B)
{
    if (this != &B)
        Clone(B);
    return *this;
}
void Book::GetAuthors(list<Author>& list) const 
{
    list.clear();
    list.assign(authors.begin(), authors.end());
}
void Book::SetAuthors(list<Author>& list) 
{
    authors.clear();
    authors.assign(list.begin(), list.end());
}

bool Book::operator < (const Book& B) const 
{ 
    return title.compare(B.title) < 0; 
}

bool Book::operator > (const Book& B) const 
{ 
    return title.compare(B.title) > 0; 
}

bool Book::operator == (const Book& B) const 
{ 
    return title.compare(B.title) == 0; 
}

ostream& operator << (ostream& cout, const Book& B) 
{
    cout << "Название: " << B.title << endl;
    cout << "Год публикации: " << B.year << endl;
    cout << "Номер УДК: " << B.numberUDC << endl;
    if ((B.authors).size())
    {
        cout << "Список авторов:" << endl;
        for (auto i : B.authors)
            cout << i << endl;
    }
    else
        cout << "Без автора" << endl;
    return cout;
}
