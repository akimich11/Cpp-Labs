#include "queue.h"
#define _CRT_SECURE_NO_WARNINGS

Queue::Queue(const Queue& Q)
{
	Clone(Q);
}

Queue::~Queue()
{
	Erase();
}


Queue& Queue::operator = (const Queue& Q) 
{
	if (typeid(Q) != typeid(*this))
		throw QException("Wrong type!");

	if (this != &Q) 
	{
		Erase();
		Clone(Q);
	}
	return *this;
}