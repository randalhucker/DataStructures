#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string"

#include "Player.h"
#include "HardWheel.h"

using namespace std;

Player *InitializePlayer();
void HousePlay(int betType, Player *House, Player *Player1, int bet);
void GamePlay(Player *Player1, Player *House);

int main()
{
    string PlayPress = "";
    int mode = 0;
    cout << "Please select the mode for gameplay: " << endl;
    cout << "(0) Normal" << endl;
    cout << "(1) Hard" << endl;
    cin >> mode;
    Player *Player1 = InitializePlayer();
    Player *House;
    if (mode == 0)
    {
        House = new Player(new Wheel(Player1->getWheel()->getMin(), Player1->getWheel()->getMax()), -1, "House");
    }
    else
    {
        House = new Player(new HardWheel(Player1->getWheel()->getMin(), Player1->getWheel()->getMax()), -1, "House");
    }

    cout << "Enter Any Character to Play..." << endl;
    cin >> PlayPress;

    GamePlay(Player1, House);
    if (Player1->getTotal() != 0)
    {
        cout << "Please select one of the following: " << endl;
        cout << "(0) Continue Playing" << endl;
        cout << "(1) Cash out!" << endl;
        cin >> PlayPress;
        while (PlayPress != "0" && PlayPress != "1")
        {
            cout << "Please enter '0' or '1': ";
            cin >> PlayPress;
        }

        while (PlayPress != "1" && Player1->getTotal() != 0)
        {
            GamePlay(Player1, House);
            cout << "Please select one of the following: " << endl;
            cout << "(0) Continue Playing" << endl;
            cout << "(1) Cash out!" << endl;
            cin >> PlayPress;
            while (PlayPress != "0" && PlayPress != "1")
            {
                cout << "Please enter '0' or '1': ";
                cin >> PlayPress;
            }
        }
    }
    cout << "You final total was: $" << Player1->getTotal() << "!" << endl;
    cout << "Play again soon!" << endl;
    return 0;
}