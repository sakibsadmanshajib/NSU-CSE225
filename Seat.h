#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

class Seat
{
    public:
        Seat();
        void Print();

    private:
        std::string color;
        std::string type;
};

#endif // SEAT_H
