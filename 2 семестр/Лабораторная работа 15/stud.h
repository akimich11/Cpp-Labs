#pragma once
#include "person.h"
#include <iostream>
using namespace std;

class Cstud : public CPerson
{
    private:
        int kurs;
        int grup;
    public:
        Cstud(const char*, const int, const int);
        int get_kurs() const { return kurs; }
        int get_grup() const { return grup; }
        int get_ID() const { return ID; }
        void set_kurs(const int x_kurs) { kurs = x_kurs; }
        void set_grup(const int x_grup) { grup = x_grup; }
        void display();
        friend ostream& operator << (ostream&, const Cstud&);
};