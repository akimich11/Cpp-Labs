#include <iostream>
#include <cmath>
using namespace std;

int cifri(int n)
{
	int p = 1;
	while(n >= 10)
	{
		n /= 10;
		p++;
	}
	return p;
}

int degree(int a, int b)
{
	int rez = 1;
	for (int i = 0; i < b; i++)
	{
		rez *= a;
	}
	return rez;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b;
	int n, i2;
    cout << "Введите границы интервала (a и b)" << endl;
	cin >> a;
	cin >> b;
	if (a > b)
		swap(&a, &b);

	if (a <= 0 || b <= 0)
	{
		cout << "Error" << endl;
		return 0;
	}

	cout << "Числа Армстронга на заданном интервале:" << endl;
	for (int i = a; i <= b; i++)
	{
		i2 = i; //сохранение первоначального значения
		n = 0;
		while (i != 0)
		{
			n += degree(i % 10, cifri(i2));
			i /= 10;
		}
		if (n == i2)
			cout << i2 << endl;
		i = i2; //восстановление первоначального значения
	}
	return 0;
}