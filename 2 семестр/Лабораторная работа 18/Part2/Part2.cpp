#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct record
{
	string fio;
	char course;
	int group;
};

bool compare_by_fio(const record& a, const record& b)
{
	return a.fio < b.fio;
}

bool compare_by_course(const record& a, const record& b)
{
	if (a.course != b.course)
		return a.course < b.course;
	else if (a.group != b.group)
			return a.group < b.group;
	else
		return a.fio < b.fio;
}


int main()
{
	setlocale(LC_ALL, ".1251");
	ifstream fin("Students.txt");
	ofstream out_fio("Fio.txt");
	ofstream out_groups("Groups.txt");

	vector <record> a;
	record student;
	string s;
	int k = 0;

	if (!fin.is_open())
	{
		cout << "Входной файл не может быть открыт!\n";
		fin.close();
		out_fio.close();
		out_groups.close();
		return 1;
	}
	if (!out_fio.is_open() || !out_groups.is_open())
	{
		cout << "Выходной файл не может быть создан!\n";
		fin.close();
		out_fio.close();
		out_groups.close();
		return 1;
	}
	if (fin.peek() == EOF)
	{
		cout << "Входной файл пуст!\n";
		fin.close();
		out_fio.close();
		out_groups.close();
		return 1;
	}
    
	while (getline(fin, s))
	{
		if (s.size())
		{
			student.fio = s.substr(0, s.find_first_of(";"));
			k = s.find_first_of(";");
			student.course = s[k + 1];
			k = s.find_first_of(";", k + 1);
			k++;
			student.group = stoi(s.substr(k, s.size() - k));
			a.push_back(student);
			k = 0;
		}
	}

	sort(a.begin(), a.end(), compare_by_fio);
	out_fio << setw(5) << "Курс" << setw(9) << "| Группа" << " | " << "ФИО" << endl;
	for (int i = 0; i < a.size(); i++)
		out_fio << setw(5)<< a[i].course << setw(9) << a[i].group << "   " << a[i].fio << endl;

	sort(a.begin(), a.end(), compare_by_course);
	out_groups << setw(5) << "Курс" << setw(9) << "| Группа" << " | " << "ФИО" << endl;
	for (int i = 0; i < a.size(); i++)
		out_groups << setw(5) << a[i].course << setw(9) << a[i].group << "   " << a[i].fio << endl;

	fin.close();
	out_fio.close();
	out_groups.close();

	return 0;
}