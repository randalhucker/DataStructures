#pragma once

#include "Deck.h"
#include "Sidedeck.h"
#include <string>

using namespace std;

class Player
{
protected:
    Deck* Deck;
    SideDeck* SideDeck
public:
    Player(); // Default Constructor
    ~Player();
};