#include <iostream>
#include <set>
#include <algorithm>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введите N: ";
    cin >> N;
    
    int* a = new int[N + 1];
    for (int i = 0; i < N + 1; i++)
        a[i] = i;
    set <int> simple(a + 2, a + N + 1);
    delete[] a;
    for (int i = 2; i < N / 2; i++)
    {
        if (simple.find(i) != simple.end())
        {
            int j = 2 * i;
            int M = *max_element(simple.begin(), simple.end());
            while (j <= M)
            {
                simple.erase(j);
                j += i;
            }
        }
    }
    for (set<int>::iterator i = simple.begin(); i != simple.end(); i++)
        cout << *i << " "; 
    cout << endl;

    return 0;
}