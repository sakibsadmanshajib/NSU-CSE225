#include "QueType.h"

QueType::QueType(int max) :
    maxQue(max + 1),
    front(maxQue - 1),
    rear(maxQue - 1),
    items(new Customer[maxQue])
{}

QueType::QueType() : QueType(49) {}

QueType::~QueType()
{
    delete[] items;
}

void QueType::MakeEmpty()
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty()
{
    return (rear == front);
}

bool QueType::IsFull()
{
    return ((rear+1)%maxQue == front);
}

void QueType::Enqueue(Customer newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear +1) % maxQue;
        items[rear] = newItem;
    }
}

void QueType::Dequeue(Customer& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}
