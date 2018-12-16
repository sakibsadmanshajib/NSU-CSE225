#include <iostream>
#include <string>
#include <fstream>
#include <bits.h>
#include <vector>
#include <sstream>

#include "Seat.h"
#include "Customer.h"

#include "StackType.h"
#include "UnsortedType.h"
#include "QueType.h"

using namespace std;

void out(ofstream outputFile, string inputString, UnsortedType customerInShop, StackType seats, QueType customerInLine)
{
    StackType <Seat> seatsTemp;
    UnsortedType <Customer> customerInShopTemp;
    QueType <Customer> customerInLineTemp;

    outputFile << "--------------" << endl;
    outputFile << inputString << endl;
    outputFile << "--------------" << endl;
    outputFile << "Customers In Shop" << endl;
    outputFile << "[ ";

    customerInShopTemp = customerInShop;
    customerInShopTemp.ResetList();
    while(tempC != NULL)
    {
        customerInShopTemp.GetNextItem(tempC);
        outputFile << tempC.Print() << ", ";
    }

    outputFile << "]" << endl;

    outputFile << "Customers Waiting In Line" << endl;
    outputFile << "[ " << endl;

    customerInLineTemp = customerInLine;
    while(tempC != NULL)
    {
        customerInLineTemp.Dequeue(tempC);
        outputFile << tempC.Print() << ", ";
    }

    outputFile << "]" << endl;

    outputFile << "Seat Stack" << endl;
    outputFile << "[ ";

    seatsTemp = seats;
    while(!seatsTemp.IsEmpty())
    {
        seatsTemp.Top(tempS);
        string tempStr = tempS.Print();
        outputFile << tempStr << ", ";
        seatsTemp.Pop();
    }

    outputFile << "]" << endl;
}

int main()
{
    StackType <Seat> seats;
    UnsortedType <Customer> customerInShop;
    QueType <Customer> customerInLine;

    Seat X;

    while(!seats.IsFull())
        seats.Push(X);

    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("shopevents.txt");

    if(!inputFile)
    {
        cerr << "File not Found";
        exit(1);
    }

    outputFile.open("shoplog.txt");

    if(!outputFile)
    {
        cerr << "File not Created";
        exit(1);
    }

    outputFile << "--------------" << endl;
    outputFile << "Customers In Shop" << endl;
    outputFile << "[ ]\n" << endl;
    outputFile << "Customers Waiting In Line" << endl;
    outputFile << "[ ]\n" << endl;
    outputFile << "Seat Stack" << endl;
    outputFile << "[ X, X, X, X, X]\n" << endl;

    string inputString;

    while(inputFile >> inputString && inputString != "CLOSE")
    {
        vector <string> token;

        string intermediate;

        stringstream line(inputString);

        while(getline(line, intermediate, ' '))
        {
            token.push_back(intermediate);
        }

        Customer tempC(token[1]);
        Seat tempS;

        if(token[0].compare("ARRIVE"))
        {
            if(!seats.IsEmpty())
            {
                seats.Pop();
                customerInShop.InsertItem(tempC);

            }
            else
            {
                customerInLine.Enqueue(tempC);
            }
        }
        else if(token[0].compare("LEAVE"))
        {
            if(customerInLine.IsEmpty() && !seats.IsFull())
                seats.Push(X);
            else
            {
                customerInShop.DeleteItem(tempC);
                if(!customerInLine.IsEmpty())
                {
                    Customer tempCo;
                    customerInLine.Dequeue(tempCo);
                    customerInShop.InsertItem(tempCo);
                }
            }
        }
        out(outputFile, inputString, customerInShop, seats, customerInLine);
    }

    out(outputFile, "CLOSED", customerInShop, seats, customerInLine);

    inputFile.close();

    outputFile << "End of processing.";
    outputFile.close();

    return 0;
}
