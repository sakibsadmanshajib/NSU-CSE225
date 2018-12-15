#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

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

void UnsortedType::RetrieveItem(Customer& item, bool& found)
{
    int location = 0;
    bool moreToSearch = (location < length);
    found = false;
    while (moreToSearch && !found)
    {
        if(item == info[location])
        {
            found = true;
            item = info[location];
        }
        else
        {
            location++;
            moreToSearch = (location < length);
        }
    }
}

void UnsortedType::InsertItem(Customer item)
{
    info[length] = item;
    length++;
}

void UnsortedType::DeleteItem(Customer item)
{
    int location = 0;
    while (item != info[location])
        location++;
    info[location] = info[length - 1];
    length--;

}
