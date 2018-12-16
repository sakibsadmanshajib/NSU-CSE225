#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cassert>

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

    while(getline(inputFile, inputString))
    {
        std::cout << ">" << inputString << "<\n";
        if(inputString=="CLOSE") break;
        stringstream line(inputString);
        vector<string> token;
        string intermediate;
        while(line >> intermediate)
            token.emplace_back(std::move(intermediate));
        assert(token.size()==2);

        if(token[0]=="ARRIVE")
        {
            if(!seats.IsEmpty())
            {
                for(auto & s : token) std::cout << " " << s << " (token)\n";
                seats.Pop();
                Customer tempC(token[1]);
                std::cout << "customerInShop.InsertItem\n";
                customerInShop.InsertItem(tempC);
            }
            else
            {
                for(auto & s : token) std::cout << " " << s << " (token)\n";
                Customer tempC(token[1]);
                std::cout << "customerInLine.Enqueue\n";
                customerInLine.Enqueue(tempC);
            }
        }
        else if(token[0]=="LEAVE")
        {
            for(auto & s : token) std::cout << " " << s << " (token)\n";

            if(customerInLine.IsEmpty() && !seats.IsFull()) {
                std::cout << "leave seats push" << token[1] << "\n";
                seats.Push(X);
            }
            std::cout << "leave " << token[1] << "\n";
            Customer tempC(token[1]);
            customerInShop.DeleteItem(tempC);
            if(!customerInLine.IsEmpty())
            {
                Customer tempCo;
                customerInLine.Dequeue(tempCo);
                customerInShop.InsertItem(tempCo);
            }
        }
    }
    inputFile.close();
    outputFile.close();

    return 0;
}
