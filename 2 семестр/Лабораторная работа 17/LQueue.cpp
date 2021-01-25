#include "LQueue.h"
#define _CRT_SECURE_NO_WARNINGS

void LQueue::Clone(const Queue& Q) 
{
	if (typeid(Q) != typeid(*this))
		throw QException("Wrong type!");
	const LQueue* Qu = (const LQueue*)&Q;
	front = NULL;
	rear = NULL;
	size = 0;
	QItem* tmp = Qu->front;
	for (int i = 0; i < Qu->size; ++i)
	{
		Push(tmp->info);
		tmp = tmp->next;
	}

}

bool LQueue::IsEmpty() const
{
	return (!front);
}

void LQueue::Erase()
{
	while (!IsEmpty())
		Pop();
}

LQueue::LQueue(const LQueue& Q) 
{
	front = rear = NULL;
	size = 0;
	Clone(Q);
}
LQueue::~LQueue()
{
	cout << "LQueue destructor was called" << endl;
}

LQueue& LQueue::operator = (const LQueue& Q)
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

InfoType& LQueue::operator [] (unsigned u)
{
	if (u > size)
		throw QException("Wrong index!\n");
	size_t cnt = 0u;
	QItem* iter = front;
	while (cnt != u)
	{
		cnt++;
		iter = iter->next;
	}
	return iter->info;

}

void LQueue::Push(InfoType AInfo) 
{
	QItem* item = new QItem(AInfo);
	if (size > 0) 
		rear->next = item;
	else 
	{
		front = item;
		front -> next = rear;
	}
	rear = item;
	size++;
}

bool LQueue::Pop() 
{
	if (IsEmpty())
		return false;
	QItem* tmp = front;
	front = front->next;
	delete tmp;
	size--;
	if (!size)
		rear = NULL;
	return true;
}

InfoType LQueue::GetFirst() const 
{
	if (IsEmpty())
		throw QException("Queue is empty!\n");
	return front -> info;
}

unsigned LQueue::GetSize() const 
{
	unsigned counter = 0;
	const QItem* temp = front;
	do 
	{
		counter++;
		temp = temp->next;
	} while (temp != rear->next);
	return counter;
}

const InfoType& LQueue::GetByIndex(unsigned u) const 
{
	if (u > size)
		throw QException("Wrong index!\n");
	unsigned counter = 0;
	QItem* temp = front;
	while (counter != u)
	{
		counter++;
		temp = temp -> next;
	}
	return temp -> info;
}

void LQueue::Browse(void ItemWork(InfoType)) const 
{
	if (this->IsEmpty())
		throw QException("Queue is empty!");
	QItem* temp = front;
	while (temp != rear)
	{
		ItemWork(temp -> info);
		temp = temp -> next;
	}
	ItemWork(temp -> info);
}
void LQueue::Browse(void ItemWork(InfoType&)) 
{
	if (this->IsEmpty())
		throw QException("Queue is empty!");
	QItem* temp = front;
	while (temp != rear)
	{
		ItemWork(temp->info);
		temp = temp->next;
	}
	ItemWork(temp->info);
}