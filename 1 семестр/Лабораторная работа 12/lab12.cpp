#include <iostream>
#include "matrix.cpp"

using namespace std;

int main()
{
    try{
    matrix n1(2, 2);
    matrix n2;
    int k = 1, m1, m2;
    
    for(int i = 0; i < n1.GetM(); i++)
            for(int j = 0; j < n1.GetN(); j++)
                n1.SetEl(i, j, 2); 

    cout << "matrix 1:" << endl;
    cout << n1 << endl; 

    cout << "Enter size of matrix 2 (m and n):" << endl;
    cin >> m1 >> m2;
    n2 = matrix(m1, m2);
    cin >> n2;
    cout << "matrix 2:" << endl;
    cout << n2 << endl;
    
    cout << "(n1 + n2) * (n1 - n2) + 2 * n1:" << endl;
    cout << (n1 + n2) * (n1 - n2) + 2 * n1 << endl;
    }

    catch(matrix::Bad e)
    {
        cout <<"Error: "<< e.getMessage() << endl;
    }
    return 0;
}