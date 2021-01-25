//Примечание: все модифицирующие алгоритмы применяются к ИСХОДНОМУ вектору
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	vector <int> a, b;
	vector <int>::iterator iter1, iter2, it2;
	int i1, i2, sum2;
	string s;
	int n, k = 0, c = 0;
	
	cout << "Введите элементы вектора (целые числа) через пробел:" << endl;
	getline(cin, s);
	while (k != -1)
	{
		k = s.find_first_not_of(" ", k);
		if (k < s.size() && k > -1)
			a.push_back(stoi(s.substr(k, s.find_first_of(" ", k) - k)));
		k = s.find_first_of(" ", k);
	}
	cout << "Исходный вектор:" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	b = a;
	cout << "\n-------------------------------------------------------------------------------------\n"<< endl;

	int sum = accumulate(a.begin(), a.end(), NULL);
	cout << "Сумма элементов вектора: " << sum << endl;
	cout << "Количество чисел в векторе: " << a.size() << endl;
	cout << "-------------------------------------------------------------------------------------\n" << endl;

	cout << "Введите целое число: ";
	cin >> n;

	iter1 = find(a.begin(), a.end(), n);
	while (iter1 != a.end())
	{
		iter1 = find(iter1 + 1, a.end(), n);
		c++;
	}
	cout << "Чисел, равных данному: " << c << endl;
	c = 0;

	iter1 = find_if(a.begin(), a.end(), [n](int i) {return i > n; });
	while (iter1 != a.end())
	{
		iter1 = find_if(iter1 + 1, a.end(), [n](int i) {return i > n; });
		c++;
	}
	cout << "Чисел, больших данного: " << c << endl;
	cout << "-------------------------------------------------------------------------------------\n" << endl;

	int arithm = sum / a.size();
	replace(a.begin(), a.end(), 0, arithm);
	cout << "Вектор, в котором нули заменены на среднее арифметическое: " << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	a = b;
	cout << "-------------------------------------------------------------------------------------\n" << endl;

	cout << "Введите интервал (2 положительных числа, меньших размера вектора ("<<a.size()<<")): ";
	cin >> i1 >> i2;
	iter1 = iter2 = a.begin();
	iter1 += i1 - 1;
	iter2 += i2;
	sum2 = accumulate(iter1, iter2, NULL);
	for_each(a.begin(), a.end(), [sum2](int &i) {i += sum2; });
	
	cout << "Вектор, в котором к каждому элементу добавили сумму всех чисел из заданного интервала ("<<sum2<<"):" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	a = b;
	cout << "-------------------------------------------------------------------------------------\n" << endl;
	
	replace_if(a.begin(), a.end(), [](int i) {return !(abs(i) % 2); }, *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()));
	
	cout << "Вектор, в котором все чётные числа заменили на разность максимального и минимального элементов: " << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	a = b;
	cout << "-------------------------------------------------------------------------------------\n" << endl;

	for (int i = 0; i < a.size(); i++)
		for (int j = i + 1; j < a.size(); j++)
			if (abs(a[i]) == abs(a[j]))
			{
				a.erase(a.begin() + j);
				j--;
			}
	cout << "Вектор, из которого удалили все равные по модулю числа, кроме первого из них:" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
	
	return 0;
}