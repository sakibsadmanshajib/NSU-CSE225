#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
    public:
        Customer();
        Customer(string);
        bool operator!=(Customer);
        bool operator==(Customer);
        void Print();

    private:
        string name;
};

#endif // CUSTOMER_H
