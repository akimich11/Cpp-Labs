#pragma once
#include <string>
using namespace std;

enum TrainType
{
	Пассажирский,
	Скорый
};

class Train
{
	private:
		int number;
		string destination;
		TrainType tt;
		string departure_time;
		int way_time;
	public:
		Train();
		void SetNumber(int n) { number = n; }
		void SetDest(string s) { destination = s; }
		void SetType(string);
		void SetDep(string h) { departure_time = h; }
		void SetTime(int w) { way_time = w; }
		string GetDest() { return destination; }
		string GetType();
		string GetDep() { return departure_time; }
		int GetTime() { return way_time; }
		friend ostream& operator << (ostream&, const Train&);
};

