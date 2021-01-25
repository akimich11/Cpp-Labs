#include "Train.h"
#include <iomanip>

Train::Train() : number(0), destination("Nowhere"), tt(������������), departure_time("0"), way_time(0) {};

void Train::SetType(string t)
{
	if (t == "������") 
		tt = ������; 
	else 
		tt = ������������;
}

string Train::GetType()
{
	if (tt) 
		return "������"; 
	else 
		return "������������";
}

ostream& operator << (ostream& cout, const Train& Tr)
{
	if (Tr.tt)
		cout << setw(5) << Tr.departure_time << setw(14) << Tr.way_time << setw(9)
		<< Tr.number << setw(15) << "������" << "  " << Tr.destination;
	else
		cout << setw(5) << Tr.departure_time << setw(14) << Tr.way_time << setw(9)
		<< Tr.number << setw(15) << "������������" << "  " << Tr.destination;
	return cout;
}
