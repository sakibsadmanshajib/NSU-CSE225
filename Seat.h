#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

using namespace std;

class Seat
{
    public:
        Seat();
        void Print();

    private:
        string color;
        string type;
};

#endif // SEAT_H
