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

void HardWheel::Spin(int val, int max)
{
    srand(time(NULL));
    BallValue = (rand() % Max + Min);
    if (BallValue < val)
    {
        Max++;
    }
    else
    {
        WinCount++;
        if (WinCount > 1 && Max > max)
        {
            Max--;
        }
    }
}

// Getter
int HardWheel::getWinCount()
{
    return (WinCount);
}

// Setter
void HardWheel::setWinCount(int w)
{
    WinCount = w;
}