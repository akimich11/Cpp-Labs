#include <iostream>
#include "List.cpp"
using namespace std;

int main()
{
    try
    {
        List L; // 1. создаем пустой список
        L.ListPrint(); //1-ый способ печати
        
        L.InsertFirst(10, "Boeing", 777.7); //5. добавим элемент в начало списка
        L.ListPrint();
        L.InsertLast(20, "Airbus", 666.6); //6. добавим элемент в конец списка
        L.ListPrint();
        L.InsertFirst(30, "Junkers", 555.5); //5. добавим элемент в начало списка
        L.ListPrint();
        L.InsertLast(40, "Airbus", 444.4); //6. добавим элемент в конец списка
        L.ListPrint();
        L.InsertLast(50, "Boeing", 333.3); //6. добавим элемент в конец списка
        L.ListPrint();

        cout << "Конструктор копирования" << endl;
        List M = L; //2. Конструктор копирования
        L = M; //3. Оператор присваивания
        cout << "список M" << endl;
        M.ForEach(Print); //12. Просмотр через callback-функцию без изменения значений (2-ой способ печати)

        List:: Plane* Q;

        if(M.FindByValue(30, "Junkers", 555.5, Q)) //10. Найдём элемент по значению (в начале)
            cout << "Итог: элемент найдён" << endl;
        else
            cout <<"Итог: элемент не найден"<<endl;
        
        if(L.FindByValue(50, "Boeing", 333.3, Q)) //10. Найдём элемент по значению (в конце)
            cout << "Итог: элемент найдён" << endl;
        else
            cout <<"Итог: элемент не найден"<<endl;

        if(L.FindByValue(20, "Airbus", 666.6, Q)) //10. Найдём элемент по значению (в середине)
            cout << "Итог: элемент найдён" << endl;
        else
            cout <<"Итог: элемент не найден"<<endl;

        L.InsertAfter(70, "Airbus", 988.7, Q); //Вставка элемента после найденного
        L.ForEach(Print);

        if(L.FindByValue(80, "Airbus", 10000.8, Q)) //10. Найдём элемент по значению (такого нет)
            cout << "Итог: элемент найдён" << endl;
        else
            cout <<"Итог: элемент не найден"<<endl;

        L.ForEach(Print_with_increment); //11. Просмотр элементов с увеличением всех значений на единицу
        
        if(L.DeleteByValue(71, "Airbus1", 989.7)) //9. удалим элемент по значению
        {
            cout << "после удаления" << endl;
            L.ListPrint();
        }
        else
            cout << "список пуст или элемент не найдён" << endl;
        if (L.DeleteFirst()) //7. удалим элемент из начала
        {
            cout << "после удаления" << endl;
            L.ListPrint();
        }
        else
            cout << "список пуст" << endl;
        if (L.DeleteLast()) //8. удалим элемент с конца
        {
            cout << "после удаления" << endl;
            L.ListPrint();
        }
        else
            cout << "список пуст" << endl;

        L.Erase(); // Очистим список L
        L.ListPrint();    
    }
    catch (exception e)
    {
        cout << "Список пуст!" << endl;
    }
    return 0;
}