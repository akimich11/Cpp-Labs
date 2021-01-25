//Вариант 6

#include "methods.cpp"

int main()
{
    const int n = 10;
    int k, course, group, i = 0, i0 = 0;
    char* name, *kaph, *surname1, *surname2;
    bool is_broken = false;
    CPerson* people[n];
    Cstud* surname[n];

    while(true)
    {
        cout <<"1. Создать студента" << endl;
        cout <<"2. Создать профессора" << endl;
        cout <<"3. Вывести массив студентов "<< endl;
        cout <<"4. Вывести массив профессоров "<< endl;
        cout <<"5. Найти всех однофамильцев на курсе и вывести их"<< endl;
        cout <<"6. Выход "<< endl;
        cout <<"Введите номер пункта меню: ";
        cin >> k;
        switch(k)
        {
            case 1:
            {
                name = new char[300];
                cout <<"Введите имя: "<< endl;
                cin >> name;
                cout <<"Введите курс и группу: "<< endl;
                cin >> course >> group;
                Cstud* student = new Cstud(name, course, group);
                people[i++] = student;
                delete[] name;
                cout << endl;
                break;
            }
            case 2:
            {
                name = new char[300];
                kaph = new char[300];
                cout <<"Введите имя: "<< endl;
                cin >> name;
                cout <<"Введите кафедру: "<< endl;
                cin >> kaph;
                CProf* professor = new CProf(name, kaph);
                people[i++] = professor;
                delete[] name;
                delete[] kaph;
                cout << endl;
                break;
            }
            case 3:
            {
                for(int p = 0; p < i; p++)
                {
                    if(typeid(*people[p]) == typeid(Cstud))
                        ((Cstud*)people[p]) -> display();
                }
                cout << endl;
                break;
            }
            case 4:
            {
                for(int p = 0; p < i; p++)
                {
                    if(typeid(*people[p]) == typeid(CProf))
                        ((CProf*)people[p]) -> display();
                }
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "Введите курс" << endl;
                cin >> course;
                cout << "Однофамильцы на курсе:" << endl;
                for (int p = 0; p < i; p++)
                {
                    if(((Cstud*)people[p]) -> get_kurs() == course)
                        surname[i0++] = (Cstud*)people[p]; //выделение однокурсников
                }
                int t = 0, p = 1;
                while(i0)
                {
                    if(strcmp(surname[p] -> get_fio(surname1), surname[t] -> get_fio(surname2)) == 0)
                    {
                        cout << surname[p] << endl;
                        for(int j = p; j < i0; j++)
                            surname[j] = surname[j + 1];
                        i0--;
                    }
                    p++;
                }
                break;
            }
            default:
            {
                cout << endl;
                return 0;
                break;
            }
        }
    }
}