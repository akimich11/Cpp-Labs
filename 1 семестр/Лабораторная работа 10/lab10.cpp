#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex number1(5, 2);
    complex number2(3, -3);
    complex number3;
    cout << number3 << endl;
    number3 = number2 - number1;
    cout << number3 << endl;
    number3 = number2 + number1;
    cout << number3 << endl;
    number3 = number2 * number1;
    cout << number3 << endl;
    number3 = number2 / number1;
    cout << number3 << endl;
    number3 = complex(3, -3);
    if(number3 == number2)
        cout << number3 << endl;
    if(number3 != number1)
        cout << number1 << endl;
    return 0;
}