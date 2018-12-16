#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>

#include "Seat.h"
#include "Customer.h"

#include "StackType.cpp"
#include "UnsortedType.cpp"
#include "QueType.cpp"

using namespace std;


void out(ofstream &outputFile, string inputString, UnsortedType<Customer> customerInShop, StackType<Seat> seats, QueType<Customer> customerInLine)
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
    Customer tempC = Customer("temp");
    for(int i=0; i<customerInShopTemp.LengthIs(); i++)
    {
        customerInShopTemp.GetNextItem(tempC);
        outputFile << tempC.Print() << ", ";
    }
    outputFile << "]" << endl;

    outputFile << "Customers Waiting In Line" << endl;
    outputFile << "[ ";

    customerInLineTemp = customerInLine;
    while(true)
    {
        try{
            customerInLineTemp.Dequeue(tempC);
            outputFile << tempC.Print() << ", ";
        }
        catch(EmptyQueue e){
            break;
        }
    }

    outputFile << "]" << endl;

    outputFile << "Seat Stack" << endl;
    outputFile << "[ ";

    Seat tempS;
    seatsTemp = seats;
    while(!seatsTemp.IsEmpty())
    {
        tempS = seatsTemp.Top();
        outputFile << tempS.Print() << ", ";
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
    vector <string> token;

    while(inputFile >> inputString && inputString != "CLOSE")
    {
        token.clear();
        if((string)inputString == "ARRIVE" || (string)inputString == "LEAVE"){
            string tString;
            inputFile >> tString;
            inputString += (" " + tString);
        }
        string intermediate;

        stringstream line(inputString);

        while(getline(line, intermediate, ' '))
        {
            token.push_back(intermediate);
        }

        Customer tempC(token[1]);
        Seat tempS;

        if(token[0] == "ARRIVE" )
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
        else if(token[0] == "LEAVE")
        {
            if(customerInLine.IsEmpty() && !seats.IsFull())
            {
                customerInShop.DeleteItem(tempC);
                seats.Push(X);
            }
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
