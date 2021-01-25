#include <iostream>
#include <cmath>
using namespace std;

double f1(double x) 
{
	return (sin(0.4 * x) * pow(x, 0.23));
}
double f2(double x)
{
	double e = 2.71828182845904523536;
	return (pow(e, -x * x) * ((sin(0.4 * x) * sin(0.4 * x)) / (x * x + 3.5)));
}
double f3(double x)
{
	double e = 2.71828182845904523536;
	return (pow(e, (1.1 * x) / (1 + x * x)) / (x * x + 1.1));
}

double rectangle_integral(double eps, double a, double b, double(*f)(double), int *n) 
{
	double s2 = eps + 1, s1 = 0;
	*n = 1;
	do
	{
		s1 = s2;
		*n *= 2;
		double h;
		double sum = 0;
		h = (b - a) / *n;
		for (int i = 1; i <= *n; i++)
			sum += f(a + i * h);
		s2 = (sum * h);
	}while(fabs(s2 - s1) > eps);
	return s1;
}
double simpson_integral(double eps, double a, double b, double(*f)(double), int *n)
{
	double s1 = eps + 1, s2 = 0;
	*n = 1;
	do
	{
		*n *= 2;
		double h, sum2 = 0, sum4 = 0, sum = 0;
		h = (b - a) / (2 * (*n));
		for (int i = 1; i <= 2 * *n - 1; i += 2)
		{
			sum4 += f(a + h * i);
			sum2 += f(a + h * (i + 1));
		}
		sum = f(a) + 4 * sum4 + 2 * sum2 - f(b);
		s1 = s2;
		s2 = (h / 3) * sum;
	}while (fabs(s2 - s1) > eps);
	return s2;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	double a, b, eps;
	int n = 1;

	cout << "Введите левую границу интегрирования a = ";
	cin >> a;
	cout << "Введите правую границу интегрирования b = ";
	cin >> b;
	if (a > b) swap(a, b);
	if (a == b)
	{
		cout << "Промежуток равен нулю" << endl;
		return 0;
	}
	cout << "Введите требуемую точность eps = ";
	cin >> eps;

	cout << "\nЗначения интегралов по формуле правых прямоугольников:" << endl;
	cout << "Интеграл 1 = " << rectangle_integral(eps, a, b, f1, &n);
	cout << ", точность достигнута при n = " << n << endl;
	cout << "Интеграл 2 = " << rectangle_integral(eps, a, b, f2, &n);
	cout << ", точность достигнута при n = " << n << endl;
	cout << "Интеграл 3 = " << rectangle_integral(eps, a, b, f3, &n);
	cout << ", точность достигнута при n = " << n << endl;

	cout << "\nЗначения интегралов по формуле Симпсона:" << endl;
	cout << "Интеграл 1 = " << simpson_integral(eps, a, b, f1, &n);
	cout << ", точность достигнута при n = " << n << endl;
	cout << "Интеграл 2 = " << simpson_integral(eps, a, b, f2, &n);
	cout << ", точность достигнута при n = " << n << endl;
	cout << "Интеграл 3 = " << simpson_integral(eps, a, b, f3, &n);
	cout << ", точность достигнута при n = " << n << endl;

	return 0;
}