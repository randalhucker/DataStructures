#pragma once
#include "MiddleOrderedList.h"
#include "MiddleOrderedList.cpp"
#include "SpacedOrderedList.h"
#include "SpacedOrderedList.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> rVector = {};
    vector<int> eVector = {};
    MiddleOrderedList<int> MList = MiddleOrderedList<int>();
    OrderedList<int> OList = OrderedList<int>();
    SpacedOrderedList<int> SList = SpacedOrderedList<int>();

    for (int i = 0; i < 25; i++)
    {
        rVector.push_back((rand() % 100) + 1);
    }

    // while (!rVector.empty())
    // {
    //     if (!eVector.empty())
    //     {
    //         if (((rand() % 1) + 1))
    //         { // Add Item Case
    //             int numCheck = (rand() % rVector.size()) + 1;
    //             OList.addItem(rVector[numCheck]);
    //             MList.addItem(rVector[numCheck]);
    //             SList.addItem(rVector[numCheck]);
    //             eVector.push_back(rVector[numCheck]);
    //             rVector.erase(numCheck);
    //         }
    //         else // Remove Item Case
    //         {
    //             int numCheck = (rand() % eVector.size()) + 1;
    //             OList.removeItem(eVector[numCheck]);
    //             MList.removeItem(eVector[numCheck]);
    //             SList.removeItem(eVector[numCheck]);
    //             eVector.erase(numCheck);
    //         }
    //     }
    //     else
    //     {
    //         int numCheck = (rand() % rVector.size()) + 1;
    //         OList.addItem(rVector[numCheck]);
    //         MList.addItem(rVector[numCheck]);
    //         SList.addItem(rVector[numCheck]);
    //         eVector.push_back(rVector[numCheck]);
    //         rVector.erase(numCheck);
    //     }
    // }

    int number = 1;
    int ans = 1;

    while (ans != 0)
    {
        if (ans == 1)
        {
            cout << "Enter Number to add: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;

            // OList.addItem(number);
            // MList.addItem(number);
            SList.addItem(number);
            cout << SList.Print() << endl;
        }
        else if (ans == 2)
        {
            cout << "Enter Number to remove: " << endl;
            cout << "> ";
            cin >> number;
            cout << endl;
            // int x = OList.removeItem(number);
            // int x = MList.removeItem(number);
            int x = SList.removeItem(number);
            cout << SList.Print() << endl;
        }

        cout << "Enter 0 to quit, 1 to add, 2 to remove: " << endl;
        cout << "> ";
        cin >> ans;
        cout << endl;
    }
}