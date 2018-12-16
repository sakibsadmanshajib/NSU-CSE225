#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer
{
    public:
        Customer(const std::string& n=std::string(""));
        bool operator!=(const Customer&) const;
        bool operator==(const Customer&) const;
        void Print();

    private:
        std::string name;
};

#endif // CUSTOMER_H
