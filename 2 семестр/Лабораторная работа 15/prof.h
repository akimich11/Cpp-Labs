#pragma once

#include "person.h"

class CProf : public CPerson
{
    private:
        char* kaf;
    public:
        CProf(const char*, const char*);
        ~CProf();
        char* get_kaf(char*) const;
        void set_kaf(const char*);
        void display();
};