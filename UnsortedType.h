#include "Customer.h"
#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

const int MAX_ITEM = 5;

class UnsortedType
{
    public :
        UnsortedType();
        void MakeEmpty();
        bool IsFull();
        int LengthIs();
        void InsertItem(Customer);
        void DeleteItem(Customer);
        void RetrieveItem(Customer&, bool&);
        void ResetList();
        void GetNextItem(Customer&);
    private:
        int length;
        Customer info[MAX_ITEM];
    int currentPos;
};

#endif // UNSORTEDTYPE_H
