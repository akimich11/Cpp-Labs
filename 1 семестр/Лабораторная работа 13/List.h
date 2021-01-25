#ifndef List_h
#define List_h

#include <iostream>
using namespace std;
class List
{
    public:
        struct Plane
        {
            int number;
            string model;
            double max_speed;
            Plane* Next;
        };
        Plane* First;
    public:
        List(){ First = NULL; } // конструктор
        List(const List&); // конструктор копирования
        virtual ~List(); // деструктор

        int Top();
        bool FindByValue(int, string, double, Plane* &);
        void InsertFirst(const int &, const string &, const double &); // добавление нового элемента в начало списка
        void InsertLast(const int &, const string &, const double &); // добавление нового элемента в конец списка
        void InsertAfter(const int &, const string &, const double &, Plane*);        
        bool DeleteFirst(); // удаление элемента из начала списка
        bool DeleteLast(); // удаление элемента из конца списка
        bool DeleteByValue(int, string, double); // удаление элемента по значениям
        void ListPrint() const; // печать элементов списка
        void ForEach (void(int, string, double))const; // выполнить действия над всеми элементами списка, не изменяя его
        void ForEach (void(int&, string&, double&)); // выполнить действия над всеми элементами списка, изменяя его
        
        const List & operator = (const List &); // оператор присваивания
        void Erase(); // удаление элементов списка

    protected:
        void Clone(const List &); // клонирование
};
#endif
