#include "person.h"
#include "stud.h"
#include "prof.h"
#include <cstring>
#include <iostream>
using namespace std;

static int next_id = 600000;

CPerson:: CPerson() : ID(++next_id)
{
    pointer_fio = new char[strlen("Noname") + 1];
    strcpy(pointer_fio, "Noname");
}
CPerson:: CPerson(const char* x_fio) : ID(++next_id)
{
    pointer_fio = new char[strlen(x_fio) + 1];
    strcpy(pointer_fio, x_fio);
}
Cstud:: Cstud(const char* x_fio, const int x_kurs, const int x_grup) : CPerson(x_fio)
{
    kurs = x_kurs;
    grup = x_grup;
}
CProf:: CProf(const char* x_fio, const char* x_kaf) : CPerson(x_fio)
{
    kaf = new char[strlen(x_kaf) + 1];
    strcpy(kaf, x_kaf);
}
CPerson:: ~CPerson()
{
    delete[] pointer_fio;
}
CProf:: ~CProf()
{
    delete[] kaf;
}
void CPerson:: display()
{
    cout <<"ID = " << ID <<" "<< pointer_fio;
}
void Cstud:: display()
{
    CPerson:: display();
    cout << " " << kurs << " " << grup << endl;
}
void CProf:: display()
{
    CPerson:: display();
    cout << " " << kaf << endl;
}
char* CPerson:: get_fio(char* pfio) const
{
    pfio = new char[strlen(pointer_fio) + 1];
    strcpy(pfio, pointer_fio);
    return pfio;
}
char* CProf:: get_kaf(char* pkaf) const
{
    pkaf = new char[strlen(kaf) + 1];
    strcpy(pkaf, kaf);
    return pkaf;
}
void CPerson::set_fio(const char* x_fio)
{
    pointer_fio = new char[strlen(x_fio) + 1];
    strcpy(pointer_fio, x_fio);
}
void CProf::set_kaf(const char* x_caf)
{
    kaf = new char[strlen(x_caf) + 1];
    strcpy(kaf, x_caf);
}

ostream& operator << (ostream& cout, const Cstud& studet)
{
    cout <<"ID: " << studet.ID <<" "<< studet.pointer_fio << " " << studet.kurs << " " << studet.grup << endl;
    return cout;
}