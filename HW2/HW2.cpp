#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string"

#include "Player.h"

using namespace std;

Player *InitializePlayer()
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
    while (max > 20 || max < 6)
    {
        cout << "Please enter a Value Between 6 and 20: ";
        cin >> max;
    }

    Player *p = new Player(Wheel(min, max), t, n);
    return (p);
}

void HouseBet(int betType, Player *House, Player *Player1, int bet)
{
    int spin1, spin2;
    House->getWheel().Spin();
    spin1 = House->getLastSpin();

    if (betType != 1)
    {
        House->getWheel().Spin();
        spin2 = House->getLastSpin();
        cout << "The House Rolled a " << spin1 << " and a " << spin2 << "." << endl;
    }
    else
    {
        cout << "The House Rolled a " << spin1 << "." << endl;
    }

    if (betType == 1)
    {
        if (Player1->getLastSpin() > spin1)
        {
            cout << "You Won!" << endl;
            Player1->setTotal(Player1->getTotal + bet);
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal - bet);
        }
    }
    else if (betType == 2)
    {
        if ((Player1->getLastSpin() > spin1) && (Player1->getLastSpin() > spin2))
        {
            cout << "You Won!" << endl;
            Player1->setTotal(Player1->getTotal + (bet * 2));
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal - (bet * 2));
        }
    }
    else
    {
        if ((Player1->getLastSpin() > spin1) || (Player1->getLastSpin() > spin2))
        {
            cout << "You Won!" << endl;
            Player1->setTotal(Player1->getTotal + (bet / 2));
        }
        else
        {
            cout << "You Lost!" << endl;
            Player1->setTotal(Player1->getTotal - (bet / 2));
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
    Player1->getWheel().Spin();
    cout << "You spun a " << Player1->getLastSpin() << "!" << endl;

    cout << "Enter 1 to keep your bet." << endl;
    cout << "Enter 2 to double your bet." << endl;
    cout << "Enter 3 to half your bet." << endl;
    cout << endl;
    cin >> betChangeNumber;
    while (betChangeNumber != 1 || betChangeNumber != 2 || betChangeNumber != 3)
    {
        cout << "Please enter 1, 2, or 3: ";
        cin >> betChangeNumber;
    }
    if (betChangeNumber == 1)
    {
        bet *= 2;
    }
    else if (betChangeNumber == 2)
    {
        bet /= 2;
    }

    cout << "You are betting" << bet << "after rolling" << Player1->getLastSpin();

    HouseBet(betChangeNumber, House, Player1, bet);

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
    Player *House = new Player(Player1->getWheel(), -1, "House");

    cout << "Press Any Key to Spin..." << endl;
    cin >> PlayPress;
    GamePlay(Player1, House);

    while (PlayPress != 'n')
    {
        cout << "Continue to Play? (y/n): ";
        cin >> PlayPress;
        while (PlayPress != "y" && PlayPress != "n")
        {
            cout << "Please enter 'y' or 'n': ";
            cin >> PlayPress;
        }
        GamePlay(Player1, House);
    }

    return 0;
}