#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	double x, e, arcctg = 2*atan(1), a = 1; //2*atan(1) = �� �������
	int n = 3;
	cout << "������� X � E" << endl;
	cin >> x;
	cin >> e;
	if ((x <= -1) || (x >= 1))
	{
		cout << "Error" << endl;
		return 0;
	}
	a = -1*x;
	arcctg += a;
	while (fabs(a) > e)
	{
		a *= (-1 * x * x * (n - 2)) / n;
		arcctg += a;
		n += 2;
	}
	cout << "arcctg " << x << " = " << arcctg << endl;
	cout <<"arcctg "<< x << " (����� cmath) = "<< 2*atan(1) - atan(x) << endl; // ��� ��� arctg(x) + arcctg(x) = �� �������
	return 0;
}