#pragma once
#include "queue.h"
class CQueue : public Queue 
{
    private:
        InfoType* Arr;
        unsigned first, last, capacity;
        void Erase();
        void Clone(const Queue&);
    public:
        CQueue(int cpty = 100);
        CQueue(const CQueue&);
        virtual ~CQueue(); // только сообщение о вызове
        virtual void Push(InfoType);
        virtual bool Pop();
        virtual InfoType GetFirst() const;
        virtual bool IsEmpty() const;
        virtual unsigned GetSize() const;
        virtual CQueue& operator = (const CQueue&);
        virtual InfoType& operator [] (unsigned);
        virtual const InfoType& GetByIndex(unsigned) const;
        virtual void Browse(void ItemWork(InfoType)) const;
        virtual void Browse(void ItemWork(InfoType&));
};


