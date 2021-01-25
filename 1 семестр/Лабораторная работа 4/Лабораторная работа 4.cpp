#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

void swap(int& l, int& m)
{
	int tmp = l;
	l = m;
	m = tmp;
}

void task1(double** a, int n1, int m1)
{
	bool is_null = false;
	int k = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			if (a[i][j] == 0)
			{
				is_null = true;
				break;
			} 
		}
		if (!is_null)
			k++;
	}
	cout <<"Количество строк без нулей: "<< k << endl;
	cout << endl;
}
void task2(double** a, int n1, int m1)
{
	int k_max = 0, k = 1, i1 = 0;
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1-1; j++)
		{
			if (a[i][j]>a[i][j+1])
				k++;
			else
			{
				if (k >= k_max)
				{
					k_max = k;
					i1 = i;
				}
				k = 1;
			}
		}
		if (k >= k_max)
		{
			k_max = k;
			i1 = i;
		}
		k = 1;
	}
	cout << "Элементов в самой длинной строго убывающей последовательности: "<< k_max <<endl;
	cout <<"Номер последней строки, в которой такая последовательность есть: "<< i1 + 1 << endl;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	srand(time(0));
	const int n = 100, m = 100;
	int l, p, n1, m1;
	char d;
	cout << "Введите количество строк и столбцов матрицы:" << endl;
	cin >> n1 >> m1;;
	if (n1 > n || n1 < 1 || m1 > m || m1 < 1)
	{
		cout << "Ошибка ввода" << endl;
		return 0;
	}
	double** a = new double* [n1]; // Объявление динамического массива
	for (int i = 0; i < n1; i++)
		a[i] = new double[m1];
	
	cout << "Введите единицу, если хотите заполнить матрицу самостоятельно (или что-нибудь другое, если нет)" << endl;
	cin >> d;
	if (d == '1')
	{
		cout << "Введите элементы матрицы" << endl;
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m1; j++)
				cin >> a[i][j];
	}
	else
	{
		cout << "Введите целочисленные границы интервала (a и b), на котором сгенерируются случайные числа" << endl;
		cin >> l;
		cin >> p;
		if (l > p)
			swap(l, p);
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m1; j++)
				a[i][j] = (l + rand() % (p - l) + 1) + ((rand() % 100) / 100.0);
	}

	cout << "Исходная матрица:\n";
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
			printf("%8.2f",a[i][j]);
		cout << endl;
	}

	cout << endl;

	task1(a, n1, m1);
	task2(a, n1, m1);

	for (int i = 0; i < n1; i++)
		delete [] a[i];
	delete [] a;

	return 0;
}