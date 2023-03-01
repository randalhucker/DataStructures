#pragma once
#include "MiddleOrderedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    int number = 1;

    while (number != 0)
    {

        cout << "Enter Number for List: " << endl;
        cout << "> ";
        cin >> number;
        cout << endl;

        MList.addItem(number);

        MList.Print();

        cout << "Enter 0 to exit: " << endl;
        cout << "> ";
        cin >> number;
        cout << endl;
    }
}