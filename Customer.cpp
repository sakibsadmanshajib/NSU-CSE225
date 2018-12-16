#include "Customer.h"

Customer::Customer(const std::string& nm) :
    name(nm)
{}

bool Customer::operator!=(const Customer& cus) const
{
    return name != cus.name;
}

bool Customer::operator==(const Customer& cus) const
{
    return name == cus.name;
}

void Customer::Print()
{
    std::cout << name;
}
