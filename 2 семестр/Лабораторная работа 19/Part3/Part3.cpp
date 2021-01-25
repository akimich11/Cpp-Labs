/*
Примечания и комментарии:
1. При наличии нескольких книг с одинаковым названием удаляются ВСЕ эти книги
2. При наличии нескольких книг с одинаковым названием и автором автор удаляется из ВСЕХ книг
3. Сортировка авторов по фамилии происходит в конструкторе класса Book.
4. Если у автора нет отчества, это обозначается как "-"
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <cctype>
#include <windows.h>
#include "Author.h"
#include "Book.h"
using namespace std;

//Проверка на равенство строк (строчные и прописные символы не различаются)
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
        if (c == 168)
            c += 16;
        s[i] = c;
    }
}
bool identity(const string& a, const string& b) 
{
    string a1 = a, b1 = b;
    tosmall(a1);
    tosmall(b1);
    return a1 == b1;
}
//Добавление книги
void add_book(list<Book>& library, Book& book) 
{
    library.push_back(book);
    library.sort();
}
//Удаление книги
bool delete_book(list<Book>& library, string& title) 
{
    bool found = false;
    list<Book>::iterator iter, iter0;
    for (iter = library.begin(); iter != library.end();) 
    {
        if (identity((*iter).GetTitle(), title))
        {
            if (iter != library.begin())
            {
                library.erase(iter--);
                iter++;
            }
            else
            {
                library.erase(library.begin());
                iter = library.begin();
            }
            found = true;
        }
        else 
            iter++;
    }
    return found;
}
//Поиск книг по названию
bool search_by_title(list<Book>& library, string& title) 
{
    bool found = false;
    list<Book>::iterator iter;
    for (iter = library.begin(); iter != library.end(); iter++) 
    {
        if (identity((*iter).GetTitle(), title)) 
        {
            cout << *iter << endl;
            found = true;
        }
    }
    return found;
}
//Поиск книг указанного автора
bool search_by_author(list<Book>& library, string& surname, string& name, string& lastname) 
{
    bool found = false;
    list<Book>::iterator iter;
    for (iter = library.begin(); iter != library.end(); iter++) 
    {
        list<Author> aList;
        (*iter).GetAuthors(aList);
        for (auto el : aList) 
        {
            if (identity(el.GetSurname(), surname) && identity(el.GetName(), name) && identity(el.GetLastname(), lastname)) 
            {
                cout << *iter << endl << endl;
                found = true;
            }
        }
    }
    return found;
}
//Добавление автора указанной книги
bool add_author(list<Book>& library, string title, Author& author) 
{
    bool found = false;
    list<Book>::iterator iter;
    for (iter = library.begin(); iter != library.end(); iter++) 
    {
        if (identity((*iter).GetTitle(), title)) 
        {
            list<Author> aList;
            (*iter).GetAuthors(aList);
            aList.push_back(author);
            aList.sort();
            (*iter).SetAuthors(aList);
            found = true;
        }
    }
    return found;
}
//Удаление автора указанной книги
bool delete_author(list<Book>& library, string title, Author& author) 
{
    bool found = false;
    list<Book>::iterator iter;
    for (iter = library.begin(); iter != library.end(); iter++) 
    {
        if (identity((*iter).GetTitle(), title))
        {
            list<Author> aList;
            (*iter).GetAuthors(aList);
            list<Author>::iterator iter2;

            iter2 = aList.begin();
            while (iter2 != aList.end())
            {
                if (identity((*iter2).GetSurname(), author.GetSurname()) &&
                    identity((*iter2).GetName(), author.GetName()) &&
                    identity((*iter2).GetLastname(), author.GetLastname()))
                {
                    if (iter2 != aList.begin())
                    {
                        aList.erase(iter2--);
                        iter2++;
                    }
                    else
                    {
                        aList.erase(aList.begin());
                        iter2 = aList.begin();
                    }
                    found = true;
                }
                else
                    iter2++;
            }
            (*iter).SetAuthors(aList);
        }
    }
    return found;
}

int main() 
{
    try 
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        fstream fin("input.txt");
        list<Book> library;
        string record;

        if (!fin)
            throw "Входной файл не может быть открыт!";
        if (fin.peek() == EOF)
            throw "Входной файл пуст!";
        
        int begin1, end1, begin2, end2;
        string word1, word2, a[3], razd = ",;";
        
        while (getline(fin, record)) 
        {
            if (!record.size())
                continue;
            record += ",";
            begin1 = end1 = 0;
            for (int i = 0; i < 3; i++) 
            {
                begin1 = record.find_first_not_of(razd, begin1);
                end1 = record.find_first_of(razd, begin1);
                word1 = record.substr(begin1, end1 - begin1);
                a[i] = word1;
                begin1 = end1;
            }
            int number = stoi(a[0]);
            string title = a[1].substr(1);
            int year = stoi(a[2].substr(1));

            list<Author> authors;
            while ((begin1 = record.find_first_not_of(razd, begin1)) != -1) 
            {
                end1 = record.find_first_of(razd, begin1);
                word1 = record.substr(begin1, end1 - begin1);

                begin2 = end2 = 0;
                for (int i = 0; i < 3; i++) 
                {
                    word1 += " ";
                    begin2 = word1.find_first_not_of(" ", begin2);
                    end2 = word1.find_first_of(" ", begin2);
                    word2 = word1.substr(begin2, end2 - begin2);
                    a[i] = word2;
                    begin2 = end2;
                }
                Author author(a[0], a[1], a[2]);
                authors.push_back(author);

                begin1 = end1;
            }

            Book book(number, authors, title, year);
            library.push_back(book);
        }
        fin.close();
        library.sort();

        while (true) 
        {
            cout << "----------------------МЕНЮ------------------------" << endl;
            cout << "1. Добавить книгу в библиотеку" << endl;
            cout << "2. Удалить книгу по названию" << endl;
            cout << "3. Найти книгу по названию" << endl;
            cout << "4. Найти книги заданного автора" << endl;
            cout << "5. Добавить автора книги (по названию)" << endl;
            cout << "6. Удалить автора книги (по названию)" << endl;
            cout << "7. Вывести список всех книг" << endl;
            cout << "8. Выход" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Введите номер пункта меню:" << endl;
            int choice;
            cin >> choice;
            if (choice < 1 || choice > 8)
                continue;
            switch (choice) 
            {
            case 1: 
            {
                int number, n, year;
                string surname, name, lastname, title;
                cout << "Номер УДК: ";
                cin >> number;
                cout << "Сколько авторов вы хотите добавить? ";
                cin >> n;
                if (n < 1)
                    do 
                    {
                        cout << "Некорректный ввод. Попробуйте снова" << endl;
                        cin >> n;
                    } while (n < 1);
                
                list<Author> authors;
                for (int i = 0; i < n; i++) 
                {
                    cout << "Фамилия: ";
                    cin >> surname;
                    cout << "Имя: ";
                    cin >> name;
                    cout << "Отчество: ";
                    cin >> lastname;
                    Author author(surname, name, lastname);
                    authors.push_back(author);
                }
                cout << "--------------------------------------------------" << endl;
                cout << "Название книги: ";
                while (getchar() != '\n');
                getline(cin, title);
                cout << "Год публикации: ";
                cin >> year;
                Book book(number, authors, title, year);
                add_book(library, book);
                break;
            }
            case 2: 
            {
                string title;
                cout << "Введите название книги, которую вы хотите удалить:" << endl;
                while (getchar() != '\n');
                    getline(cin, title);
                cout << "--------------------------------------------------" << endl;
                if (!delete_book(library, title))
                    cout << "Книг с таким названием нет в библиотеке" << endl;
                else
                    cout << "Удаление завершено успешно" << endl;
                break;
            }
            case 3: 
            {
                string title;
                cout << "Введите название книги, которую вы хотите найти:" << endl;
                while (getchar() != '\n');
                getline(cin, title);
                cout << "--------------------------------------------------" << endl;
                cout << "Книги с таким названием:" << endl;
                if (!search_by_title(library, title))
                    cout << "Книг с таким названием нет в библиотеке" << endl;
                break;
            }
            case 4: 
            {
                cout << "Введите автора." << endl;
                string surname, name, lastname;
                cout << "Фамилия: ";
                cin >> surname;
                cout << "Имя: ";
                cin >> name;
                cout << "Отчество: ";
                cin >> lastname;
                cout << "--------------------------------------------------" << endl;
                cout << "Книги данного автора:" << endl;
                if (!search_by_author(library, surname, name, lastname))
                    cout << "Книг данного автора нет в библиотеке" << endl;
                break;
            }
            case 5: 
            {
                string title, surname, name, lastname;
                cout << "Введите название книги:" << endl;
                while (getchar() != '\n');
                getline(cin, title);
                cout << "Введите автора." << endl;
                cout << "Фамилия: ";
                cin >> surname;
                cout << "Имя: ";
                cin >> name;
                cout << "Отчество: ";
                cin >> lastname;
                cout << "--------------------------------------------------" << endl;
                Author author(surname, name, lastname);
                if (!add_author(library, title, author))
                    cout << "Книг с таким названием нет в библиотеке" << endl;
                else
                    cout << "Автор успешно добавлен" << endl;
                break;
            }
            case 6: 
            {
                string title, surname, name, lastname;
                cout << "Введите название книги:" << endl;
                while (getchar() != '\n');
                getline(cin, title);
                cout << "Введите автора." << endl;
                cout << "Фамилия: ";
                cin >> surname;
                cout << "Имя: ";
                cin >> name;
                cout << "Отчество: ";
                cin >> lastname;
                cout << "--------------------------------------------------" << endl;
                Author author(surname, name, lastname);
                if (!delete_author(library, title, author))
                    cout << "Книг данного автора с таким названием нет в библиотеке" << endl;
                else
                    cout << "Удаление завершено успешно" << endl;
                break;
            }
            case 7:
                if (library.size())
                    for (auto book : library)
                        cout << book << endl;
                else
                    cout << "Библиотека пуста" << endl;
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
        cout << "Ошибка в процессе выполнения программы" << endl;
    }
}
