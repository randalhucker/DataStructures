#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "Wheel.h"

using namespace std;

class HardWheel: protected Wheel
{
    protected:
        int WinCount;
    
    public:
        HardWheel(); // default constructor
        HardWheel(int minimum, int maximum); // fill constructor
        ~HardWheel(); // destructor
        void Spin(int val); // overload spin to take in player spin value

        // Getter
        int getWinCount();

        //Setter
        void setWinCount(int w);
};