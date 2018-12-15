#include <iostream>
#include <string>
#include <fstream>
#include <bits.h>
#include <vector>
#include <sstream>

#include "StackType.h"
#include "UnsortedType.h"
#include "QueType.h"

using namespace std;

int main()
{
    StackType seats;
    UnsortedType customerInShop;
    QueType customerInLine;

    cout << "1" << endl;

    Seat X;

    cout << "2" << endl;

    while(!seats.IsFull())
        seats.Push(X);

    cout << "3" << endl;

    ifstream inputFile;
    ofstream outputFile;

    cout << "4" << endl;

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

    cout << "5" << endl;

    outputFile << "--------------" << endl;
    outputFile << "Customers In Shop" << endl;
    outputFile << "[ ]\n" << endl;
    outputFile << "Customers Waiting In Line" << endl;
    outputFile << "[ ]\n" << endl;
    outputFile << "Seat Stack" << endl;
    outputFile << "[ X, X, X, X, X]\n" << endl;

    cout << "6" << endl;

    string inputString;

    int i = 7;

    while(inputFile >> inputString && inputString != "CLOSE")
    {
        /*outputFile << "--------------" << endl;
        outputFile << inputString << endl;
        outputFile << "--------------" << endl;
        outputFile << "Customers In Shop" << endl;
        outputFile << "[ ";*/

        cout << i++ << endl;

        vector <string> token;

        string intermediate;

        stringstream line(inputString);

        cout << i++ << endl;

        while(getline(line, intermediate, ' '))
        {
            token.push_back(intermediate);
        }

        cout << i++ << endl;

        if(token[0].compare("ARRIVE"))
        {
            if(!seats.IsEmpty())
            {
                seats.Pop();
                Customer tempC(token[1]);
                customerInShop.InsertItem(tempC);

            }
            else
            {
                Customer tempC(token[1]);
                customerInLine.Enqueue(tempC);
            }

            cout << i++ << endl;
        }
        else if(token[0].compare("LEAVE"))
        {
            if(customerInLine.IsEmpty() && !seats.IsFull())
                seats.Push(X);
            else
            {
                Customer tempC(token[1]);
                customerInShop.DeleteItem(tempC);
                if(!customerInLine.IsEmpty())
                {
                    Customer tempCo;
                    customerInLine.Dequeue(tempCo);
                    customerInShop.InsertItem(tempCo);
                }
            }

            cout << i++ << endl;
        }

        cout << i++ << endl;

        /*outputFile << "Customers Waiting In Line" << endl;
        outputFile << "[ ]\n" << endl;
        outputFile << "Seat Stack" << endl;
        outputFile << "[ X, X, X, X, X]\n" << endl;*/
    }
    inputFile.close();
    outputFile.close();

    return 0;
}
