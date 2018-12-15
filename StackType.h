#include "Seat.h"
#ifndef STACKTYPE_H
#define STACKTYPE_H

const int MAX_ITEMS = 5;

class FullStack
{

};

class EmptyStack
{

};

class StackType
{
    public:
        StackType();
        bool IsFull();
        bool IsEmpty();
        void Push(Seat);
        void Pop();
        Seat Top();

    private:
        int top;
        Seat item[MAX_ITEMS];
};

#endif // STACKTYPE_H
