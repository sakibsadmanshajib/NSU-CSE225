#include "UnsortedType.h"

UnsortedType::UnsortedType() :
    length(0),
    currentPos(-1)
{}

void UnsortedType::MakeEmpty()
{
    length = 0;
}

bool UnsortedType::IsFull()
{
    return (length == MAX_ITEM);
}

int UnsortedType::LengthIs()
{
    return length;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

void UnsortedType::GetNextItem(Customer& item)
{
    currentPos++;
    item = info [currentPos] ;
}

bool UnsortedType::RetrieveItem(Customer& item)
{
    int location = 0;
    bool moreToSearch = (location < length);
    while (moreToSearch)
    {
        if(item == info[location])
        {
            item = info[location];
            return true;
        }
        else
        {
            location++;
            moreToSearch = (location < length);
        }
    }
    return false;
}

void UnsortedType::InsertItem(Customer item)
{
    if(length==MAX_ITEM) std::cout << "already maxed\n";
    info[length] = item;
    ++length;
}

void UnsortedType::DeleteItem(Customer item)
{
    std::cout << "delete\n";
    int location = 0;
    while (item != info[location])
        location++;
    info[location] = info[length - 1];
    --length;
}
