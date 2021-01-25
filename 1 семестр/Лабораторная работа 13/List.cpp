#include "List.h"
#include <exception>

    void List::Clone(const List &L) // клонирование
    {
        Plane *p, *q, *r;
        r = NULL;
        p = L.First;
        while (p != NULL)
        {
            q = new Plane;
            q -> number = p -> number;
            q -> model = p -> model;
            q -> max_speed = p -> max_speed;
            q -> Next = NULL;
            if (r == NULL)
                First = q;
            else
                r -> Next = q;
            r = q;
            p = p -> Next;
        }
    }
    void List::Erase() // удаление списка
    {
        Plane *p, *q;
        p = First;
        while (p != NULL)
        {
            q = p -> Next;
            delete p; 
            p = q;
        }
        First=NULL;
    }
    List::List(const List& L) // конструктор копирования
    {
        Clone(L);
    }
    List::~List() // деструктор
    {
        Erase();
    }
    int List:: Top()
    {
        if(First == NULL)
            throw exception();
        return First -> number;
    }
    void List::InsertFirst(const int &ANumber, const string &AModel, const double &ASpeed) // добавление нового элемента в начало списка
    {
        Plane* P = new Plane; 
        P -> number = ANumber;
        P -> model = AModel;
        P -> max_speed = ASpeed;
        P -> Next = First;
        First = P;
    }
    void List::InsertLast(const int &ANumber, const string &AModel, const double &ASpeed) // добавление нового элемента в конец списка
    {
        Plane* P = new Plane;
        P -> number = ANumber;
        P -> model = AModel;
        P -> max_speed = ASpeed;
        Plane* Q = First;
        while(Q -> Next != NULL)
            Q = Q -> Next;
        P -> Next = Q -> Next;
        Q -> Next = P;
    }
    bool List::DeleteFirst() // удаление элемента из начала списка
    {
        if (First == NULL)
            return false;
        Plane* P = First;
        First = First -> Next;
        delete P;
        return true;
    }
    bool List::DeleteLast() // удаление элемента с конца списка
    {
        if (First == NULL)
            return false;
        Plane* Q = First;
        Plane* P = First;
        while(P -> Next -> Next != NULL)
            P = P -> Next;
        while(Q -> Next != NULL)
            Q = Q -> Next;
        P -> Next = Q -> Next;
        delete Q;
        return true;
    }
    bool List::FindByValue(int n, string m, double s, Plane* &Q)
    {
        Plane* P = First;
        int k = 0;
        while (P != NULL)
        {
            k++;
            if(P -> number == n && P -> model == m && P -> max_speed == s)
            {
                cout << "Число сравнений: " << k << endl;
                Q = P;
                return true;
            }
            P = P -> Next;
        }
        cout << "Число сравнений: " << k << endl;
        return false;
    }
    void List::InsertAfter(const int &ANumber, const string &AModel, const double &ASpeed, Plane* Q)
    {
        Plane* P = new Plane;
        P -> number = ANumber;
        P -> model = AModel;
        P -> max_speed = ASpeed;
        P -> Next = Q -> Next;
        Q -> Next = P;
    }
    bool List::DeleteByValue(int n, string m, double s)
    {
        Plane* Prev = First;
        if(Prev -> number == n && Prev -> model == m && Prev -> max_speed == s)
        {
            DeleteFirst();
            return true;
        }
        while (Prev -> Next != NULL)
        {
            if((Prev -> Next) -> number == n && (Prev -> Next) -> model == m && (Prev -> Next) -> max_speed == s)
                break;
            Prev = Prev -> Next;
        }
        if (Prev -> Next == NULL)
            return false;
        Plane* Q = Prev -> Next;
        Prev -> Next = Q -> Next;
        delete Q;
        return true;
    }
    const List & List::operator = (const List &L) // оператор присваивания
    {
        if (&L == this)
            return *this; // проверка на самоприсваивание
        Erase();
        Clone(L);
        return *this;
    }

    void List::ListPrint()const // печать элементов списка 1-ый способ
    {
        Plane *P = First;
        if (P == NULL)
        {
            cout << "список пуст" << endl;
            return;
        }
        if (P != NULL)
        {
            cout << "содержимое списка" << endl;
            while(P != NULL)
            {
                cout << P -> number <<" "<< P -> model <<" "<< P-> max_speed << endl;
                P = P -> Next;
            }
        }
    }
    void Print(int x, string m, double s) // печать элементов списка 2-ой способ
    {
        cout << x <<" "<< m <<" "<< s << endl;
    }
    void Print_with_increment(int& x, string& m, double& s)
    {
        x += 1;
        m += "1";
        s += 1.0;
        cout << x <<" "<< m <<" "<< s << endl;
    }

    void List::ForEach(void Fun(int, string, double))const
    {
        Plane *P = First;
        if (P == NULL)
            cout << "список пуст" << endl;
        if (P != NULL)
        {
            cout << "содержимое списка" << endl;
            while(P != NULL)
            {
                Fun(P -> number, P -> model, P -> max_speed);
                P = P -> Next;
            }
        }
    }
    void List::ForEach (void Fun(int&, string&, double&)) 
    {
        Plane* P = First;
        if (P == NULL)
            cout << "список пуст" << endl;
        if (P != NULL)
        {
            cout << "содержимое списка" << endl;
            while(P != NULL)
            {
                Fun(P -> number, P -> model, P -> max_speed);
                P = P -> Next;
            }
        }    
    } // выполнить действия над всеми элементами списка, изменяя его
