// #pragma once
#include <string>
#include <cstdlib>
#include "Wheel.h"
#include <iostream>

using namespace std;

class Player
{
private:
    Wheel pWheel;
    int Total;
    string Name;

public:
    Player();                         // Default Constructor
    Player(Wheel w, int T, string N); // Fill constructor
    ~Player();                        // Destructor

    // Getters
    int getLastSpin();
    int getTotal();
    string getName();

    // Setters
    void setTotal(int M);
    void setName(string N);
};