#include "MyString.cpp"
using namespace std;

int main()
{
    try
    {
        MyString a("My");
        MyString b = " string";
        MyString c = a + b;
        cout << c[1] << endl;
        cout << c << endl;
        MyString d = a;
        MyString e(d);
        c = d;
        cout << c << endl;
        d = d + a;
        //d=d+" bbb";
        cout << a << endl;
        cout << d << endl;
        cout << e << endl;
    }
    catch(const char* e)
    {
        cout << "Ошибка: "<< e << endl;
    }
}
