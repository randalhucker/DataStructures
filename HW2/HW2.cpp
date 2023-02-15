#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string"

#include "Player.h"
#include "HardWheel.h"

using namespace std;

Player *InitializePlayer()
{
    string n;
    int t, max;
    int min = 1;
    cout << "Please enter your name: ";
    cin.ignore();
    getline(cin, n);
    cout << "Please enter the amount of money you wish to play with: ";
    cin >> t;
    cout << "Please enter the numer of values on the wheel: ";
    cin >> max;
    while (max > 20 || max < 6)
    {
        cout << "Please enter a Value Between 6 and 20: ";
        cin >> max;
    }

    Player *p = new Player(new Wheel(min, max), t, n);
    return (p);
}

void HousePlay(int betType, Player *House, Player *Player1, int bet)
{
    int spin1, spin2;
    int pspin = Player1->getWheel()->getBallValue();
    House->getWheel()->Spin(pspin, Player1->getWheel()->getMax());
    spin1 = House->getLastSpin();

    if (betType != 1)
    {
        House->getWheel()->Spin(pspin, Player1->getWheel()->getMax());
        spin2 = House->getLastSpin();
        cout << "The House Rolled a " << spin1 << " and a " << spin2 << "." << endl;
    }
    else
    {
        cout << endl
             << "The House Rolled a " << spin1 << "." << endl;
    }

    if (betType == 1)
    {
        // cout << Player1->getLastSpin() << " This is PreDecision" << spin1 << endl;
        if (Player1->getLastSpin() > spin1)
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + bet);
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - bet);
        }
    }
    else if (betType == 2)
    {
        if ((Player1->getLastSpin() > spin1) && (Player1->getLastSpin() > spin2))
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + bet);
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - bet);
        }
    }
    else
    {
        if ((Player1->getLastSpin() > spin1) || (Player1->getLastSpin() > spin2))
        {
            cout << "You Won! Congrats " << Player1->getName() << "!" << endl;
            Player1->setTotal(Player1->getTotal() + bet);
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal() - bet);
        }
    }
}

void GamePlay(Player *Player1, Player *House)
{
    int betChangeNumber;
    int bet = 0;
    cout << "Please enter your bet: ";
    cin >> bet;
    while (bet <= 0 || bet > Player1->getTotal())
    {
        if (bet <= 0)
        {
            cout << "Please enter a positive number for your bet: ";
        }
        else
        {
            cout << "You cannot bet more than you have... Please enter a different bet: ";
        }
        cin >> bet;
    }
    Player1->getWheel()->Spin(0, 0);

    cout << "You spun a " << Player1->getWheel()->getBallValue() << "!" << endl
         << endl;

    cout << "Enter 1 to keep your bet." << endl;
    cout << "Enter 2 to double your bet." << endl;
    cout << "Enter 3 to half your bet." << endl;
    cout << endl;
    cout << "Bet type: ";
    cin >> betChangeNumber;
    cout << endl;
    while (betChangeNumber != 1 && betChangeNumber != 2 && betChangeNumber != 3)
    {
        cout << "Please enter 1, 2, or 3: ";
        cin >> betChangeNumber;
    }

    cout << "You are betting " << bet << " after rolling " << Player1->getLastSpin() << endl;

    HousePlay(betChangeNumber, House, Player1, bet);

    cout << "Your Total is Now: " << Player1->getTotal() << endl;
}

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