#include "Author.h"
#include <string>
using namespace std;

Author::Author(string s, string n, string m) : surname(s), name(n), lastname(m) {}

void Author::Clone(const Author& A) 
{
    surname = A.surname;
    name = A.name;
    lastname = A.lastname;
}

Author::Author(const Author& A) 
{ 
    Clone(A); 
}

Author& Author::operator = (const Author& A) 
{
    if (this != &A)
        Clone(A);
    return *this;
}

bool Author::operator < (const Author& A) const 
{
    if (surname.compare(A.surname) != 0)
        return surname.compare(A.surname) < 0;
    else if (name.compare(A.name) != 0)
        return name.compare(A.name) < 0;
    else
        return lastname.compare(A.lastname) < 0;
}

bool Author::operator > (const Author& A) const 
{ 
    if (surname.compare(A.surname) != 0)
        return surname.compare(A.surname) > 0;
    else if (name.compare(A.name) != 0)
        return name.compare(A.name) > 0;
    else
        return lastname.compare(A.lastname) > 0;
}

bool Author::operator == (const Author& A) const 
{ 
    return surname.compare(A.surname) == 0; 
}

ostream& operator << (ostream& cout, const Author& A) 
{
    if(A.GetLastname() != "-")
        cout << A.surname << " " << A.name << " " << A.lastname;
    else
        cout << A.surname << " " << A.name;
    return cout;
}
