#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#define _CRT_SECURE_NO_WARNINGS
#define D_SCL_SECURE_NO_WARNINGS
using namespace std;

string tosmall(string s)
{
	for(int i = 0; i < s.size(); i++)
		if(s[i] > 64 && s[i] < 92)
			s[i] = tolower(s[i]);
	return s;
}

string sort(string s, int n)
{
	string s1, s2, tmp;
	int k0, k1, k2;
	for(int i = 0; i < n - 1; i++)
	{
		k2 = -1;
		for(int j = 0; j < n - i - 1; j++)
		{
			k1 = s.find_first_of("\n", k2 + 1);
			k0 = s.find_first_of("\n", k1 + 1);

			s1 = s.substr(k2 + 1, k1 - k2 - 1);
			s2 = s.substr(k1 + 1, k0 - k1 - 1);
			if(strcmp(s1.c_str(), s2.c_str()) > 0)
			{
				tmp = s.substr(k2 + 1, k1 - k2 - 1);
				s.replace(k2 + 1, k1 - k2 - 1, s2);
				s.replace(k2 + k0 - k1 + 1, k0 - k1 - 1, tmp);
			}
			k2 = s.find_first_of("\n", k2 + 1);
		}
	}
	return s;
}

string lex(string s)
{
    string s1, alpha;
	int k, col = 0;
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

string frequency(string s, int &n, int freq0)
{
	string s1, s2, s3;
	int k, k1 = 0, freq = 1;
	while(s.size())
	{
		k = s.find_first_of(" ");
		s1 += s.substr(0, k);
		k1 = k;
		s2 += s.substr(k + 1, s.find_first_of(" ", k + 1) - k - 1);
		s1 = tosmall(s1);
		while(k != -1)
		{
			s2 = tosmall(s2);
			if(s1 == s2)
			{
				freq++;
				s2.erase(0, s2.size());
				if(k1 == k)
				{
					k = s.find_first_of(" ", k + 1);
					s.erase(k1, k - k1);
				}
				else
					s.erase(k1, k - k1);
				k = s.find_first_of(" ", k1 + 1);
				s2 += s.substr(k1 + 1, k - k1 - 1);
			}
			else
			{
				s2.erase(0,s2.size());
				k1 = k;
				k = s.find_first_of(" ", k + 1);
				s2 += s.substr(k1 + 1, k - k1 - 1);
			}
		}
		if(freq >= freq0)
		{
			n++;
			s3 += s1;
			s3 += " ";
			s3 += to_string(freq);
			s3 += "\n";
		}
		freq = 1;
		k1 = 0;
		k = s.find_first_of(" ");
		s.erase(0, k + 1);
		if(s.size() == 1)
			s.erase(0, s.size());
		s1.erase(0, s1.size());
	}
	return s3;
}

int main()
{
	int freq0, n = 0;
	char* s = new char[301];
	string str;
	FILE* f1;
	FILE* f2;
	cin >> freq0;
	if ((f1 = fopen("input.txt", "r")) != NULL)
	{
		while (!feof(f1))
		{
			fgets(s, 300, f1);
			str += s;
		}
		if (str.size() == 0)
		{
			cout << "Input file is empty!" << endl;
			system("pause");
			return 1;
		}
		fclose(f1);
	}
	else
	{
		cout << "File can't be open!" << endl;
		system("pause");
		return 1;
	}
	f2 = fopen("output.txt","wt");
	str = lex(str);
	if (str.size() == 1)
	{
		fprintf(f2, "%s", "Input file contains only delimiters!");
		return 1;
	}
	str = frequency(str, n, freq0);
	str = sort(str, n);
	fprintf(f2, "%s", str.c_str());
	fclose(f2);
	
	str.clear();
	delete[] s;
	return 0;
}