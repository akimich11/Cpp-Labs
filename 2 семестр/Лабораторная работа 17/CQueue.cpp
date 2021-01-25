#include "CQueue.h"
#define _CRT_SECURE_NO_WARNINGS

void CQueue::Erase()
{
	delete[] Arr;
	first = 0;
	last = 0;
	capacity = 0;
}

void CQueue::Clone(const Queue& q)
{
	if (typeid(q) != typeid(*this))
		throw QException("Wrong type!");

	const CQueue* Q = (const CQueue*)&q;
	capacity = Q->capacity;
	first = Q->first;
	last = Q->last;
	Arr = new InfoType[capacity];
	for (int i = 0; i < capacity; i++)
		Arr[i] = Q->Arr[i];

}

CQueue::CQueue(int cpty)
{
	last = first = 0;
	Arr = new InfoType[cpty];
	capacity = cpty;
}

CQueue::CQueue(const CQueue& Q)
{
	Clone(Q);
}

CQueue::~CQueue()
{
	cout << "CQueue destructor was called" << endl;
}

CQueue& CQueue::operator = (const CQueue& Q) 
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

InfoType& CQueue::operator [] (unsigned u)
{
	if (u >= capacity - 1)
		throw QException("Wrong index!\n");
	if (first + u >= capacity)
		return Arr[first + u - capacity];
	return Arr[first + u];
}

bool CQueue::IsEmpty() const
{
	if (first == last)
		return true;
	return false;
}

void CQueue::Push(InfoType info) 
{
	if (last + 1 == first || (last + 1 == capacity && !first))
		throw QException("Queue is full!");
	
	if (last == capacity) 
		last = 0;
	Arr[last++] = info;
}

bool CQueue::Pop() 
{
	if (IsEmpty())
		return false;
	
	first++;
	if (first == capacity) 
		first = 0;
	return true;
}

InfoType CQueue::GetFirst() const 
{
	if (IsEmpty())
		throw QException("Queue is empty!");
	return Arr[first];
}

unsigned CQueue::GetSize() const 
{
	if (last >= first)
		return last - first;
	return(last + capacity - first);
}

const InfoType& CQueue::GetByIndex(unsigned u) const 
{
	if (u >= capacity - 1)
		throw QException("Wrong index!\n");
	if (first + u >= capacity)
		return Arr[first + u - capacity];
	return Arr[first + u];
}

void CQueue::Browse(void ItemWork(InfoType)) const 
{
	if (IsEmpty())
		throw QException("Queue is empty!");
	if (last > first)
		for (unsigned i = first; i < last; i++)
			ItemWork(Arr[i]);
	else
	{
		for (unsigned i = first; i < capacity; i++)
			ItemWork(Arr[i]);
		for (unsigned i = 0; i < last; i++)
			ItemWork(Arr[i]);
	}
}

void CQueue::Browse(void ItemWork(InfoType&)) 
{
	if (IsEmpty())
		throw QException("Queue is empty!");
	if (last > first)
		for (unsigned i = first; i < last; i++)
			ItemWork(Arr[i]);
	else
	{
		for (unsigned i = first; i < capacity; i++)
			ItemWork(Arr[i]);
		for (unsigned i = 0; i < last; i++)
			ItemWork(Arr[i]);
	}
}