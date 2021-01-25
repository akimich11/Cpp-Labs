#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;

void task1(double a[], double n)
{
	double sum = 0, sum_max = -9223372036854775808.0;
	int n1 = 0;
	for (int i = 1; i <= n; i++)
	{ //Циклы для подсчёта максимальной суммы цепочки (ищет сначала цепочку по одному элементу, потом по два и т.д.)
		for (int j = 0; j < n; j++)
		{
			sum += a[j];
			if (j >= i)
				sum -= a[j - i]; //сдвиг суммы на 1 элемент вправо
			if (sum > sum_max)
			{
				sum_max = sum;
				n1 = i; //Сохраняем, сумма какого количества элементов оказалась максимальной
			}
		}
		sum = 0;
	}
	
	for (int i = 0; i < n1; i++)
		sum += a[i]; //Складываем n1 элементов подряд начиная с a[0]
	
	int i = n1 - 1;
	while (sum != sum_max) 
	{
		i++;
		sum += a[i];
		sum -= a[i - n1]; //Сдвигаемся вправо на 1 элемент пока сумма не совпадёт с максимальной
	}
	cout << "Цепочка подряд идущих элементов с наибольшей суммой:\n";
	for (int j = i - n1 + 1; j <= i; j++)
		cout << "  " << a[j];
	cout << " (сумма " << sum_max << ")\n";
	cout << endl;
}

void task2(double a[], double n)
{
	double sum = 0;
	bool is_null = false;
	for (int i = (n - 1); i >= 0; i--) //Так как нужен последний ноль, ищем с конца
	{
		if (a[i] == 0)
		{
			is_null = true;
			for (int j = i; j < n; j++)
				sum += a[j];
			cout << "Сумма элементов массива после последнего нуля:\n";
			cout << "  " << sum << endl;
			break;
		}
	}
	if (!is_null)
		cout << "Массив не содержит элементов, равных нулю\n";
	cout << endl;
}

void task3(double a[], double n)
{
	bool m = false;
	double k = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 2) //У любого числа меньше двойки целая часть не превосходит единицу
		{
			m = true;
			k = a[i];
			for (int j = i; j > 0; j--)
				a[j] = a[j - 1];
			a[0] = k;
		}
	}
	if (!m)
		cout << "Массив не содержит элементов с целой частью <= 1, преобразование массива не требуется" << endl;
	else
	{
		cout << "Массив, в котором элементы с целой частью <= 1 стоят в начале:\n";
		for (int i = 0; i < n; i++)
			cout << "  " << a[i];
	}
	cout << endl;
}

void swap(int &l, int &m)
{
	int tmp = l;
	l = m;
	m = tmp;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	srand(time(0));
	const int n = 100;
	int l, m, n1;
	char d;
	double a[n];
	cout << "Введите число элементов массива" << endl;
	cin >> n1;
	if (n1 > n || n1 < 1)
	{
		cout << "Ошибка ввода" << endl;
		return 0;
	}
	cout<<"Введите единицу, если хотите заполнить массив самостоятельно (или что-нибудь другое, если нет)"<<endl;
	cin >> d;
	if (d == '1')
	{
		cout << "Введите " << n1 << " элементов массива" << endl;
		/*	хороший пример для проверки всех пунктов задачи:
			{-1, 2, -2, 0, 1.5, -0.5, 0, 5, 15, -16}	*/
		for (int i = 0; i < n1; i++)
			cin >> a[i];
	}
	else
	{
		cout << "Введите целочисленные границы интервала (a и b) на котором сгенерируется " << n1 << " случайных чисел" << endl;
		cin >> l;
		cin >> m;
		if (l > m)
			swap(l, m);
		for (int i = 0; i < n1; i++)
			a[i] = (l + rand() % (m-l) + 1) + ((rand() % 100) / 100.0); //Генерация целой и дробной части числа (2 знака после запятой)
	}
	cout << "Исходный массив:\n";
	for (int i = 0; i < n1; i++)
	{
		cout << "  " << a[i];
	}
	cout << endl;
	cout << endl;

	task1(a, n1);
	task2(a, n1);
	task3(a, n1);

	return 0;
}