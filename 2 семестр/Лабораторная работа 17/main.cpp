#include <iostream>
#include <iomanip>
#include "CQueue.h"
#include "LQueue.h"

using namespace std;

void Print(const InfoType);

int main()
{
	try
	{
		cout << "----- Linear queues test (static objects) -----\n" << endl;
		LQueue LQ;
		LQ.Push(16);
		LQ.Push(23);
		LQ.Push(41);
		LQ.Push(58);
		LQ.Pop();
		cout << "Queue LQ:\n";
		LQ.Browse(Print);

		LQueue LQ1;
		LQ1 = LQ;

		cout << "\nQueue LQ1:\n";
		LQ1.Browse(Print);
		LQ1.Pop();
		LQ1.Pop();
		LQ1.Push(LQ[0]);

		LQueue LQ2 = LQ1;

		cout << "\nQueue LQ2:\n";
		LQ2.Browse(Print);

		cout << "\n\n----- Cycle queues test (static objects) -----" << endl;

		CQueue CQ;
		CQueue CQ1;
		CQ.Push(-11);
		CQ.Push(33);
		CQ.Push(-44);
		CQ.Push(22);
		CQ.Push(55);
		CQ.Pop();

		CQ1 = CQ;

		cout << endl << "Queue CQ:\n";
		CQ.Browse(Print);
		cout << endl << "Queue CQ1:\n";
		CQ1.Browse(Print);

		CQueue CQ2 = CQ;

		cout << endl << "Queue CQ2:\n";
		CQ2.Browse(Print);
		cout << endl;


		cout << "\n----- Dynamic objects test -----\n" << endl;

		Queue* LQ3 = new LQueue;
		LQ3->Push(18);
		LQ3->Push(36);
		cout << "Queue LQ3:" << endl;
		LQ3->Browse(Print);
		
		Queue* CQ3 = new CQueue;
		CQ3->Push(-80);
		CQ3->Push(160);
		cout << "\nQueue CQ3:" << endl;
		CQ3->Browse(Print);

		Queue* qpointer1 = &LQ;
		Queue* qpointer2 = new LQueue;
		*qpointer2 = *qpointer1;
		cout << "\nqpointer1:\n";
		qpointer1->Browse(Print);
		cout << "\nqpointer2:\n";
		qpointer2->Browse(Print);
		cout << endl;
		
		cout << "\n----- Queue destructors test -----\n" << endl;

		delete LQ3; //вызов деструкторов для динамических объектов
		delete CQ3;
		delete qpointer2;
		cout << endl;
	}
	catch (QException & e)
	{
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}

void Print(const InfoType info)
{
	cout << setw(4) << info;
}