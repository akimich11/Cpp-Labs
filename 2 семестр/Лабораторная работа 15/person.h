#pragma once

class CPerson
{
    protected:
        char* pointer_fio;
        const int ID;
    public:
        CPerson();
        CPerson(const char*);
        virtual ~CPerson();
        char* get_fio(char*) const;
        void set_fio(const char*);
        void display();
};