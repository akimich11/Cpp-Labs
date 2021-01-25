#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <cctype>
#include <windows.h>
using namespace std;

typedef map<string, int> StringIntMap;
typedef set<string> StringSet;

void tosmall(string& s)
{
    unsigned char c;
    for (int i = 0; i < s.size(); i++)
    {
        c = (unsigned char)s[i];
        if (c > 64 && c < 92)
            c = tolower(c);
        if (c > 191 && c < 224)
            c += 32;
        if (c == 168) //буква Ё
            c += 16;
        s[i] = c;
    }
}

void add_words(istream& in, StringIntMap& words_map, StringSet& words_set)
{
    string s;
    while (in >> s)
    {
        tosmall(s);
        words_set.insert(s);
        ++words_map[s];
    }
}

int main()
{
    try
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        ifstream fin("input.txt");

        if (!fin)
            throw "Входной файл не открывается :(";
        if (fin.peek() == EOF)
            throw "Входной файл пустой :(";

        StringIntMap w;
        StringSet ss;

        add_words(fin, w, ss);

        cout << "Cписок слов из файла:" << endl;
        for (StringSet::iterator p = ss.begin(); p != ss.end(); ++p)
            cout << *p << endl;
        cout << "--------------------" << endl;
        cout << "Количество вхождений:" << endl;
        for (StringIntMap::iterator p = w.begin(); p != w.end(); ++p)
            cout << p->first << ": " << p->second << "\n";

        fin.close();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

    return 0;
}