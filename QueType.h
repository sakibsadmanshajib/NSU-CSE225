#include "Customer.h"
#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED

class FullQueue {};
class EmptyQueue {};

class QueType
{
    public:
        QueType();
        QueType(int max);
        ~QueType();
        void MakeEmpty();
        bool IsEmpty();
        bool IsFull();
        void Enqueue(Customer);
        void Dequeue(Customer&);

    private:
        int front;
        int rear;
        Customer* items;
        int maxQue;
};

#endif // QUETYPE_H_INCLUDED
