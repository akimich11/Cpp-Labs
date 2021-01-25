#pragma once
#include <iostream>
using namespace std;
typedef int InfoType;

class QException : public exception 
{
    public:
        QException(const char* message) : exception(message) {}
        QException(const QException& right) : exception(right) {}
};
class Queue 
{
    private:
        virtual void Erase() = 0 {};
        virtual void Clone(const Queue&) = 0 {};
    public:
        Queue() {}
        Queue(const Queue&);
        virtual ~Queue();
        virtual Queue& operator = (const Queue&);
    
        virtual void Push(InfoType AInfo) = 0;
        virtual bool Pop() = 0;
        virtual InfoType GetFirst() const = 0;
        virtual bool IsEmpty() const = 0;
        virtual unsigned GetSize() const = 0;
        virtual InfoType& operator [] (unsigned) = 0;
        virtual const InfoType& GetByIndex(unsigned) const = 0;
        virtual void Browse(void ItemWork(InfoType)) const = 0;
        virtual void Browse(void ItemWork(InfoType&)) = 0;
};