#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string"

#include "Player.h"

using namespace std;

Player InitializePlayer()
{
    string n;
    int t, max;
    int min = 1;
    cout << "Please enter your name:" << endl;
    cin.ignore();
    getline(cin, n);
    cout << "Please enter the amount of money you wish to play with: " << endl;
    cin >> t;
    cout << "Please enter the numer of values on the wheel: " << endl;
    cin >> max;
    Player p = Player(Wheel(min, max), t, n);
    return (p);
}

void GamePlay(Player player1)
{
}

int main()
{
    string PlayPress;
    Player player1 = InitializePlayer();
    cout << "Press Any Key to Spin..." << endl;
    cin >> PlayPress;
    GamePlay(player1);
}