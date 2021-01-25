#include <iostream>
#include "fraction.cpp"
#include <ctime>

using namespace std;

int main()
{
    try
    {
        srand(time(NULL));
        int ch = 0, zn = 0;
        const int n = 10;
        fraction array[n];
        
        for(int i = 0; i < 4; i++)
        {
            ch = -5 + rand() % 9;
            zn = -5 + rand() % 9;
            if(!zn) 
                zn = 1;
            array[i] = fraction(ch, zn);
        }
        for (int i = 4; i < 7; i++)
            array[i] = array[i - 4] * array[i - 4].GetID();

        for (int i = 7; i < 10; i++)
            array[i] = array[i - 3] + array[i - 6];

        cout << "Array of fractions: " << endl;    
        for (int i = 0; i < 10; i++)
            cout << array[i].GetID() << "  " << array[i] << endl;
        
        int k = 0;
        fraction sum;
        for (int i = 0; i < 10; i++)
            if(array[i].GetID() % 2 == 0)
            {
                sum += array[i];
                k++;
            }
        cout << endl;
        cout << "Average:" << endl;
        cout << sum / k << " " << sum.GetID() << endl;
        
        //тест ввода дроби
        /*cin >> n2;
        //тесты вывода:
        cout << n1 + n2 << endl; //тест сложения дробей
        cout << n1 - n2 << endl; //тест вычитания дробей
        cout << n1 * n2 << endl; //тест умножения дробей
        cout << n1 / n2 << endl; //тест деления дробей 
    
        cout << n2 + 2 << endl; //тест сложения дроби и числа
        cout << n2 - 2 << endl; //тест вычитания числа от дроби
        cout << n2 * 2 << endl; //тест умножения дроби на число
        cout << n2 / 2 << endl; //тест деления дроби на число
        
        cout << -n2 << endl; //тест унарного минуса
        cout << !n1 << endl; //тест получения обратной дроби

        cout << n1++ << endl; //тест инкремента
        cout << n2-- << endl; //тест декремента

        cout << 2 + n1 << endl; //тест сложения числа и дроби
        cout << 2 - n1 << endl; //тест вычитания числа и дроби
        cout << 2 * n1 << endl; //тест умножения числа и дроби
        cout << 2 / n1 << endl; //тест деления числа и дроби
        
        n1 += n2;
        n1 -= n2;
        n1 *= n2;
        n1 /= n2;

        n1 += 2;
        n1 -= 3;
        n1 *= 5;
        n1 /= 4;

        system("pause");*/
    }
    catch (fraction::Bad e)
    {
        cout <<"Error: "<< e.getMessage() << endl;
    }
    return 0;
}