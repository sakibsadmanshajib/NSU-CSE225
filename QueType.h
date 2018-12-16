#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED
#include "Customer.h"

class FullQueue {};
class EmptyQueue {};

class QueType
{
    public:
        QueType();
        QueType(int max);
        QueType(const QueType&) = delete;
        QueType(QueType&&) = delete;
        ~QueType();
        QueType& operator=(const QueType&) = delete;
        QueType& operator=(QueType&&) = delete;
        void MakeEmpty();
        bool IsEmpty();
        bool IsFull();
        void Enqueue(Customer);
        void Dequeue(Customer&);

    private:
        int maxQue;
        int front;
        int rear;
        Customer* items;
};

#endif // QUETYPE_H_INCLUDED
