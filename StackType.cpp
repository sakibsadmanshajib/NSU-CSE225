#include "StackType.h"

StackType::StackType() : top(-1) {}

bool StackType::IsEmpty()
{
    return (top == -1);
}

bool StackType::IsFull()
{
    return (top == MAX_ITEMS-1);
}

void StackType::Push(Seat newItem)
{
    if(IsFull()) throw FullStack();
    ++top;
    item[top] = newItem;
}

void StackType::Pop()
{
    if( IsEmpty() ) throw EmptyStack();
    --top;
}

Seat StackType::Top()
{
    if( IsEmpty() ) throw EmptyStack();
    return item[top];
}
