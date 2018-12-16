#include "Customer.h"

Customer::Customer(string nm)
{
    name = nm;
}

Customer::Customer()
{
    name = "";
}

bool Customer::operator!=(Customer cus)
{
    if(cus.name == name)
        return false;
    else
        return true;
}

bool Customer::operator==(Customer cus)
{
    if(cus.name == name)
        return true;
    else
        return false;
}

string Customer::Print()
{
    return name;
}
