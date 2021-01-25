#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Train.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin("input.txt");

	vector <Train> a, b, c;
	vector<Train>::iterator iter;
	Train train;
	string s, s2;
	int k = 0;

	if (!fin.is_open())
	{
		cout << "Входной файл не может быть открыт!\n";
		fin.close();
		return 1;
	}
	if (fin.peek() == EOF)
	{
		cout << "Входной файл пуст!\n";
		fin.close();
		return 1;
	}

	while (getline(fin, s))
	{
		if (s.size())
		{
			train.SetNumber(stoi(s.substr(0, s.find_first_of(";"))));
			k = s.find_first_of(";") + 1;
			train.SetDest(s.substr(k, s.find_first_of(";", k + 1) - k));
			k = s.find_first_of(";", k + 1) + 1;
			train.SetType(s.substr(k, s.find_first_of(";", k + 1) - k));
			k = s.find_first_of(";", k + 1) + 1;
			train.SetDep(s.substr(k, 5));
			k += 6;
			train.SetTime(stoi(s.substr(k, s.size() - k)));
			a.push_back(train);
			k = 0;
		}
	}

	sort(a.begin(), a.end(), [](Train tr1, Train tr2) { return tr1.GetDep() < tr2.GetDep(); });

	cout << "-------------------------------ТАБЛО------------------------------" << endl;
	cout << setw(5) << "Отпр." << setw(14) << "| Вр. пути*" << setw(9)
		<< "| Номер" << setw(15) << "|   Тип поезда" << "| " << "Пункт назначения" << endl;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	cout << "*в минутах" << endl;
	cout << "------------------------------------------------------------------" << endl;

	cout << "Введите нижнюю границу диапазона времени в формате ЧЧ:ММ : ";
	cin >> s;
	cout << "Введите верхнюю границу диапазона времени в формате ЧЧ:ММ : ";
	cin >> s2;
	if (s2 < s)
		swap(s, s2);
	if (s.size() != 5 || s2.size() != 5 || s[2] != ':' || s2[2] != ':')
		cout << "Диапазон введён некорректно. Список поездов не будет выведен." << endl;
	else
	{
		iter = find_if(a.begin(), a.end(), [s, s2](Train info) {return (info.GetDep() >= s && info.GetDep() <= s2); });
		if (iter != a.end())
		{
			cout << "Список интересующих вас поездов:" << endl;
			cout << *iter << endl;
			while (iter != a.end())
			{
				iter = find_if(iter + 1, a.end(), [s, s2](Train info) {return (info.GetDep() >= s && info.GetDep() <= s2); });
				if (iter != a.end())
					cout << *iter << endl;
			}
		}
		else
			cout << "Интересующих вас поездов не найдено" << endl;
	}
	cout << "------------------------------------------------------------------" << endl;

	cout << "Введите интересующий вас пункт назначения : ";
	getline(cin, s);
	getline(cin, s);
	
	iter = find_if(a.begin(), a.end(), [s](Train info) {return info.GetDest() == s; });
	if (iter != a.end())
	{
		cout << "Список поездов, следующих в город " << s << ":" << endl;
		cout << *iter << endl;
		b.push_back(*iter);
		if ((*iter).GetType() == "Скорый")
			c.push_back(*iter);
		while (iter != a.end())
		{
			iter = find_if(iter + 1, a.end(), [s](Train info) {return info.GetDest() == s; });
			if (iter != a.end())
			{
				cout << *iter << endl;
				b.push_back(*iter);
				if ((*iter).GetType() == "Скорый")
					c.push_back(*iter);
			}
		}
		if (c.size())
		{
			cout << "Из них скорые:\n";
			for (int i = 0; i < c.size(); i++)
				cout << c[i] << endl;
		}
		else
			cout << "Среди них нет скорых.\n";

		cout << "\nСамый быстрый из поездов отправляется в ";
		iter = min_element(b.begin(), b.end(), [](Train tr1, Train tr2) { return tr1.GetTime() < tr2.GetTime(); });
		cout << (*iter).GetDep() << endl;
	}
	else
		cout << "Интересующих вас поездов не найдено" << endl;
	cout << "------------------------------------------------------------------" << endl;

    return 0;
}