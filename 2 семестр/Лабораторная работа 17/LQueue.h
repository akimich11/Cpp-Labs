#pragma once
#include "queue.h"

class LQueue : public Queue
{
    private:
        struct QItem 
        {
            InfoType info;
            QItem* next;
            QItem(InfoType Ainfo) : info(Ainfo), next(NULL) {}
        };
        QItem *front, *rear;
        unsigned size;
        virtual void Erase();
        virtual void Clone(const Queue&);
    public:
        LQueue() : front(NULL), rear(NULL), size(0) {};
        LQueue(const LQueue&);
        virtual ~LQueue(); // только сообщение о вызове
        virtual void Push(InfoType AInfo);
        virtual bool Pop();
        virtual InfoType GetFirst() const;
        virtual bool IsEmpty()const;
        virtual unsigned GetSize() const;
        virtual LQueue& operator = (const LQueue&);
        virtual InfoType& operator [] (unsigned);
        virtual const InfoType& GetByIndex(unsigned) const;
        virtual void Browse(void ItemWork(InfoType)) const;
        virtual void Browse(void ItemWork(InfoType&));
};