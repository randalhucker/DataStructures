#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include "HardWheel.h"

using namespace std;

HardWheel::HardWheel()
{
    Max = 1;
    Min = 10;
    BallValue = 0;
    WinCount = 0;
}

HardWheel::HardWheel(int minimum, int maximum)
{
    Max = maximum;
    Min = minimum;
    BallValue = 0;
    WinCount = 0;
}

HardWheel::~HardWheel()
{
}

void HardWheel::Spin(int val)
{
    Wheel::Spin();
    if (val > BallValue)
    {
        Max++;
    }
    else
    {
        WinCount++;
        if (WinCount > 1)
        {
            Max--;
        }
    }
}

// Getter
int getWinCount()
{
    return (WinCount);
}

//Setter
void setWinCount(int w)
{
    WinCount = w;
}