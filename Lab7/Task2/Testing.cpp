#pragma once
#include "MiddleOrderedList.h"
#include "MiddleOrderedList.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    int number = 1;

    while (number != 0)
    {
        if (number == 1)
        {
            cout << "Enter Number to add: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;

            OList.addItem(number);
            // MList.addItem(number);
            cout << OList.Print() << endl;
        }
        else if (number == 2)
        {
            cout << "Enter Number to remove: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;
            OList.removeItem(number);
            // MList.removeItem(number);
            cout << OList.Print() << endl;
        }

        cout << "Enter 0 to quit, 1 to add, 2 to remove: " << endl;
        cout << "> ";
        cin >> number;
        cout << endl;
    }
}