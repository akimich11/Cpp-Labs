/*Словом в строке считается последовательность букв латинского
алфавита, остальные символы рассматриваются как разделители между
словами. Слова в каждой из двух исходных строк упорядочены по алфавиту.
Необходимо сформировать новую строку из всех слов исходных строк. Слова
в новой строке должны быть также упорядочены по алфавиту. Прописные и
строчные буквы в словах не различать. Слова в новой строке должны
разделяться ровно одним пробелом.*/
#include <iostream>
#include <cstdio> 
#include <cstring>
#include <string>
#include <cctype>
#define _CRT_SECURE_NO_WARNINGS
#define D_SCL_SECURE_NO_WARNINGS
using namespace std;

string lex(string s)
{
    string s1, alpha;
	int k, col = 0, l = 0;
	for (int i = 65; i < 91; i++)
		alpha += (char)i;
    for (int i = 97; i < 123; i++)
		alpha += (char)i;

	while(s.size())
	{
		k = s.find_first_of(alpha);
		s.erase(0, k);
		k = s.find_first_not_of(alpha);
		s1 += s.substr(0, k);
		s1 += " ";
		s.erase(0, k);
	}
		return s1;
}

string merge(string s1, string s2)
{
	int i = 0;
	string s3;
	while (s1.size() || s2.size())
	{
		if (!s1.size())
		{
			s3 += s2.substr(0, s2.size());
			s2.erase(0, s2.size() + 1);
		}
		else if (!s2.size())
		{
			s3 += s1.substr(0, s1.size());
			s1.erase(0, s1.size() + 1);
		}
		else
		{
			if (toupper(s1[i]) == toupper(s2[i]) && s1[i + 1] == ' ' && s2[i + 1] == ' ')
			{
				s3 += s1.substr(0, s1.find(" "));
				s3 += " ";
				s3 += s2.substr(0, s2.find(" "));
				s3 += " ";
				s1.erase(0, s1.find(" ") + 1);
				s2.erase(0, s2.find(" ") + 1);
				i = 0;
			}
			else if (toupper(s1[i]) == toupper(s2[i]))
				i++;
			else if (toupper(s1[i]) < toupper(s2[i]))
			{
				s3 += s1.substr(0, s1.find(" "));
				s3 += " ";
				s1.erase(0, s1.find(" ") + 1);
				i = 0;
			}
			else
			{
				s3 += s2.substr(0, s2.find(" "));
				s3 += " ";
				s2.erase(0, s2.find(" ") + 1);
				i = 0;
			}
		}
	}
	return s3;
}

int main()
{
	string s1, s2, s3;
	cout << "Enter string 1:" << endl;
	getline(cin, s1);
	cout << "Enter string 2:" << endl;
	getline(cin, s2);

	if (s1.size() == 0 && s2.size() == 0)
	{
		cout << "Strings are empty!" << endl;
		system("pause");
		return 0;
	}

	s1 = lex(s1);
	s2 = lex(s2);

	cout << "Words in strings:" << endl;
	cout << s1 << endl;
	cout << s2 << endl;

	s3 = merge(s1, s2);
	cout << "Merged string:" << endl;
	cout << s3 << endl;

	s1.clear();
	s2.clear();
	s3.clear();
	
	system("pause");
	return 0;
}