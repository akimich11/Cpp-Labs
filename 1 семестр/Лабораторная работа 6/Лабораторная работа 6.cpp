/*
Строка состоит из слов. 
За один просмотр символов строки найти все самые длинные слова,  
символы в которых идут в строгом возрастании кодов, и занести их в новую строку.
Слова в новой строке должны разделяться ровно одним пробелом
*/
#pragma warning (disable:4996) 
#include <iostream>
#include <stdio.h> 
#include <string.h> 
#include <limits.h> 
#include <ctype.h>
using namespace std;

void vstavka(char* st, const char* word)
{
	int k = strlen(word);
	int l = strlen(st);
	for (int i = l + 1; i >= 0; i--)
		*(st + i + 1) = *(st + i);
	*st = *(" ");
	for (int i = l + 1; i >= 0; i--)
		*(st + i + k) = *(st + i);
	for (int i = 0; i < k; i++)
		*(st + i) = *(word + i);
}

int main()
{
	setlocale(LC_ALL, ".1251");
	const int p = 300;
	char* st = new char[p];
	char* raz = new char[p];
	char* n[p];
	char* k;
	int i = 0;
	int s = 0;

	cout << "Введите строку" << endl;
	cin.getline(st, p + 1);
	if (strlen(st) == NULL || strlen(st) > p)
	{
		cout << "Ошибка ввода" << endl;
		return 0;
	}
	cout << "Введите разделитель" << endl;
	cin.getline(raz, p + 1);
	
	vstavka(st, "1"); //вставка в строку символа, с которым будем сравнивать длину первого слова
	vstavka(st, raz);
	
	k = strtok(st, raz);
	if (k == NULL)
	{
		cout << "Ошибка: строка состоит только из разделителей" << endl;
		return 0;
	}

	n[i] = k;
	i++;
	k = strtok(0, raz);

	while(k)
	{	
		for (int j = 0; j < strlen(k) - 1; j++)
			if (k[j] >= k[j + 1])
				s++;

		if (!s && strlen(k) >= strlen(n[i - 1])) // сравнение длины слова с длиной предыдущего слова
		{
			if (strlen(k) == strlen(n[i - 1])) // при равенстве длин добавляем слово в массив указателей
			{
				n[i] = k;
				i++;
			}
			else // если длина слова больше, то очищаем массив указателей и потом добавляем туда это слово
			{
				for (int j = 0; j < i; j++)
					n[j] = NULL;
				n[0] = k;
				i = 1;
			}
		}	
		s = 0;
		k = strtok(0, raz);
	}
	cout << n[1];
	char* st0 = new char[p];
	if (strlen(n[0]) == 1) //удаление вставленного в начале программы символа
	{
		n[0] = NULL;
		strcpy(st0, n[1]);
		for (int j = 2; j < i; j++)
			vstavka(st0, n[j]);
	}
	else
	{
		strcpy(st0, n[0]);
		for (int j = 1; j < i; j++)
			vstavka(st0, n[j]);
	}
	
	cout << "Слова максимальной длины со строгим возрастанием кодов (разделены одним пробелом):" << endl;
	cout << st0 << endl;

	delete[] st;
	delete[] raz;
	delete[] st0;

	return 0;
}