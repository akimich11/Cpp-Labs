#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include "windows.h"
using namespace std;

struct SMark 
{
    string Subject;
    int Mark;
    SMark(string s, int m) : Subject(s), Mark(m) {}
    friend ostream& operator << (ostream& cout, const SMark& s) 
    {
        cout << "Предмет: " << s.Subject << endl;
        cout << "Отметка: " << s.Mark;
        return cout;
    }
};

struct SStudData 
{
    string Name;
    int Number;
    vector <SMark> Marks;
    SStudData(string n, int num, vector<SMark>& m) : Name(n), Number(num), Marks(m) {}
    friend ostream& operator << (ostream& cout, SStudData& s) 
    {
        cout << "Имя: " << s.Name << endl;
        cout << "Номер: " << s.Number << endl;
        vector<SMark>::iterator iter;
        for (iter = s.Marks.begin(); iter != s.Marks.end(); iter++)
            cout << (*iter) << endl;
        return cout;
    }
};

bool iequals(const string& a, const string& b) 
{
    return equal(a.begin(), a.end(), b.begin(), b.end(), [](char a, char b)->bool 
        {   return tolower(a) == tolower(b);    });
}

//1
void ReadFromFile(map <int, SStudData>& studentsData, string fileName) 
{
    ifstream fin(fileName, ios_base::in);
    if (!fin)
        throw "Файл не открывается :(";
    if (fin.peek() == EOF)
        throw "Файл пуст :(";
    string line, word, w2, seps = ",;";
    int begin(0), end(0), b2(0), e2(0);
    
    while (getline(fin, line)) 
    {
        if (line.empty())
            continue;
        line.append(",");
        begin = 0; end = 0;
        //фио
        begin = (int)line.find_first_not_of(seps, begin);
        end = (int)line.find_first_of(seps, begin);
        word = line.substr(begin, end - begin);
        string Name = word;
        begin = end;
        //номер зачётки
        begin = (int)line.find_first_not_of(seps, begin);
        end = (int)line.find_first_of(seps, begin);
        word = line.substr(begin + 1, end - begin);
        int Number = stoi(word);
        begin = end;
        //отметки
        vector <SMark> Marks;
        while ((begin = (int)line.find_first_not_of(seps, begin)) != -1) 
        {
            end = (int)line.find_first_of(seps, begin);
            word = line.substr(begin, end - begin);
            word += " "; b2 = 0; e2 = 0;
            b2 = (int)word.find_first_not_of(" ", b2);
            e2 = (int)word.find_first_of(" ", b2);
            string Subject = word.substr(b2, e2 - b2);
            b2 = e2;
            b2 = (int)word.find_first_not_of(" ", b2);
            e2 = (int)word.find_first_of(" ", b2);
            int Mark = stoi(word.substr(b2, e2 - b2));
            Marks.push_back(SMark(Subject, Mark));
            begin = end;
        }
        studentsData.insert(make_pair(Number, SStudData(Name, Number, Marks)));
    }
    fin.close();
}
//3
double AverageMarkOfStudent(SStudData& s) 
{
    vector<SMark>::iterator iter2;
    int sum(0), kol(0);
    for (iter2 = s.Marks.begin(); iter2 != s.Marks.end(); iter2++)
    {
        sum += (*iter2).Mark;
        kol++;
    }
    return (double)sum / kol;
}
//4.1
bool GreaterByAverageMark(const pair<double, SStudData>& a, const pair<double, SStudData>& b) 
{
    return a.first > b.first;
}
//4.2
bool GreaterByAlphabet(const pair<double, SStudData>& a, const pair<double, SStudData>& b) 
{
    return a.second.Name.compare(b.second.Name) < 0;
}
//5.1
void GetRange(double& a, double& b) 
{
    string line;
    cout << "Введите диапазон" << endl;
    cout << "Левая граница: "; cin >> line; a = stoi(line);
    if (a < 0 || a > 10)
        do 
        {
            cout << "Некорректный ввод! Попробуйте снова" << endl;
            cin >> line; 
            a = stoi(line);
        } while (a < 0 || a > 10);
    
    cout << "Правая граница: "; cin >> line; b = stoi(line);
    if (b < a || b > 10)
        do 
        {
            cout << "Некорректный ввод! Попробуйте снова" << endl;
            cin >> line; 
            b = stoi(line);
        } while (b < a || b > 10);
}
//5.2
bool PrintFromRange(vector <pair<double, SStudData>>& studentsVector, double& a, double& b) 
{
    bool found = false;
    vector <pair<double, SStudData>>::iterator iter2;
    for (iter2 = studentsVector.begin(); iter2 != studentsVector.end(); iter2++) 
        if ((*iter2).first >= a && (*iter2).first <= b) 
        {
            cout << (*iter2).second.Name << endl;
            found = true;
        }
    return found;
}
//6
bool PrintBySubject(map <int, SStudData>& studentsData, string& subject) 
{
    bool found = false;
    map<int, SStudData>::iterator iter;
    for (iter = studentsData.begin(); iter != studentsData.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++) 
            if (iequals((*iter2).Subject, subject))
                cout << (*iter).second.Name << endl; found = true;
    }
    return found;
}
//7
void CountStudentsForEachSubject(map <int, SStudData>& studentsData, map<string, int>& subjects) 
{
    subjects.clear();
    //добавление всех предметов в map
    map<int, SStudData>::iterator iter;
    for (iter = studentsData.begin(); iter != studentsData.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++)
            subjects.insert(make_pair((*iter2).Subject, 0));
    }
    //подсчёт каждого предмета
    for (iter = studentsData.begin(); iter != studentsData.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++)
            subjects.find((*iter2).Subject)->second++;
    }
}
//8
void CountAverageForEachSubject(vector <pair<double, SStudData>>& studentsVector,
    map<string, double>& GPA, map<string, int>& subjects) 
{
    GPA.clear();
    //добавление всех предметов в map
    vector <pair<double, SStudData>>::iterator iter;
    for (iter = studentsVector.begin(); iter != studentsVector.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++)
            GPA.insert(make_pair((*iter2).Subject, 0));
    }
    //подсчёт среднего балла по каждому предмету
    for (iter = studentsVector.begin(); iter != studentsVector.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++)
            GPA.find((*iter2).Subject)->second += (*iter2).Mark;
    }
    map<string, int>::iterator iter3;
    for (iter3 = subjects.begin(); iter3 != subjects.end(); ++iter3)
        GPA.find((*iter3).first)->second = GPA.find((*iter3).first)->second / (*iter3).second;
}
//9
void PrintStudentsWithMaxAmountOfPoint(vector <pair<double, SStudData>>& studentsVector) 
{
    double max = 0;
    vector <pair<double, SStudData>>::iterator iter;
    for (iter = studentsVector.begin(); iter != studentsVector.end(); iter++)
        if ((*iter).first > max)
            max = (*iter).first;
    
    for (iter = studentsVector.begin(); iter != studentsVector.end(); iter++) 
        if ((*iter).first == max)
            cout << (*iter).second.Name << endl;
}
//10
bool PrintStudentsWithUnsatisfactoryMarks(vector <pair<double, SStudData>>& studentsVector) 
{
    bool found = false;
    vector <pair<double, SStudData>>::iterator iter;
    for (iter = studentsVector.begin(); iter != studentsVector.end(); iter++) 
    {
        vector<SMark>::iterator iter2;
        for (iter2 = (*iter).second.Marks.begin(); iter2 != (*iter).second.Marks.end(); iter2++) 
            if ((*iter2).Mark < 4) 
            {
                cout << (*iter).second.Name << endl;
                found = true;
            }
    }
    return found;
}

int main() 
{
    try {
        setlocale(LC_ALL, ".1251");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        string fileName = "input.txt";

        map <int, SStudData> studentsData; map<int, SStudData>::iterator iter;
        //map с количеством студентов, сдававших каждый предмет
        map<string, int> subjects; map<string, int>::iterator iter3;
        //map со средним баллом по каждому предмету
        map<string, double> GPA; map<string, double>::iterator iter4;
        //вектор со средним баллом каждого студента
        vector <pair<double, SStudData>> studentsVector;
        vector <pair<double, SStudData>>::iterator iter2;

        ReadFromFile(studentsData, fileName);
        
        for (iter = studentsData.begin(); iter != studentsData.end(); iter++)
            studentsVector.push_back(make_pair(AverageMarkOfStudent((*iter).second), (*iter).second));
       
        while (true) 
        {
            cout << "---------------------------МЕНЮ----------------------------" << endl;
            cout << "1. Вывести список студентов из текстового файла" << endl;
            cout << "2. Отсортировать студентов по номеру зачётки и вывести" << endl;
            cout << "3. Отобразить средний балл каждого студента" << endl;
            cout << "4. Отобразить студентов в алфавитном порядке (и по убыванию ср. балла)" << endl;
            cout << "5. Отобразить студентов со ср. баллом из заданного диапазона" << endl;
            cout << "6. Отобразить список студентов, которые сдавали заданный предмет" << endl;
            cout << "7. Вычислить сколько студентов сдавало каждый предмет" << endl;
            cout << "8. Для каждого предмета определить средний балл" << endl;
            cout << "9. Найти всех студентов с максимальной суммой баллов" << endl;
            cout << "10. Найти всех студентов с неудовлетворительными оценками(1,2,3)." << endl;
            cout << "0. Выход" << endl;
            cout << "Введите номер пункта меню:" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
            case 1:
                for (iter = studentsData.begin(); iter != studentsData.end(); iter++)
                    cout << (*iter).second << endl;
                break;
            case 2:
                for (iter = studentsData.begin(); iter != studentsData.end(); iter++)
                    cout << (*iter).second << endl;
                break;
            case 3:
                for (iter = studentsData.begin(); iter != studentsData.end(); iter++)
                    cout << (*iter).second.Name << ": " << AverageMarkOfStudent((*iter).second) << endl;
                break;
            case 4: 
            {
                sort(studentsVector.begin(), studentsVector.end(), GreaterByAverageMark);
                sort(studentsVector.begin(), studentsVector.end(), GreaterByAlphabet);
                int i(1);
                for (iter2 = studentsVector.begin(); iter2 != studentsVector.end(); iter2++)
                    cout << i++ << ". " << (*iter2).second.Name << ", " << (*iter2).second.Number << ", " << (*iter2).first << endl;
                break;
            }
            case 5: 
            {
                double a, b;
                GetRange(a, b);
                sort(studentsVector.begin(), studentsVector.end(), GreaterByAverageMark);
                if (!PrintFromRange(studentsVector, a, b))
                    cout << "Студентов со средним баллом в заданном диапазоне нет!" << endl;
                break;
            }
            case 6:
            {
                string line;
                cout << "Введите название предмета: ";
                cin >> line;
                if (!PrintBySubject(studentsData, line))
                    cout << "Студентов, сдававших этот предмет, нет!" << endl;
                break;
            }
            case 7: {
                CountStudentsForEachSubject(studentsData, subjects);
                for (iter3 = subjects.begin(); iter3 != subjects.end(); ++iter3)
                    cout << (*iter3).first << " " << (*iter3).second << endl;
                break;
            }
            case 8: {
                CountStudentsForEachSubject(studentsData, subjects);
                CountAverageForEachSubject(studentsVector, GPA, subjects);
                set<pair<double, string>> setGPA;
                for (iter4 = GPA.begin(); iter4 != GPA.end(); ++iter4)
                    setGPA.insert(make_pair((*iter4).second, (*iter4).first));
                set<pair<double, string>>::reverse_iterator iter5;
                for (iter5 = setGPA.rbegin(); iter5 != setGPA.rend(); ++iter5)
                    cout << (*iter5).second << " " << (*iter5).first << endl;
                break;
            }
            case 9: {
                PrintStudentsWithMaxAmountOfPoint(studentsVector);
                break;
            }
            case 10:
                if (!PrintStudentsWithUnsatisfactoryMarks(studentsVector))
                    cout << "Студентов с неудовлетворительными отметками нет!" << endl;
                break;
            default:
                return 0;
                break;
            }
        }
    }
    catch (const char* e) 
    {
        cout << e << endl;
    }
    catch (...)
    {
        cout << "Неизвестная ошибка" << endl;
    }
}