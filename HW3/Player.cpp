#pragma once
#include "Player.h"

Player::Player()
{
    name = "";
    D = nullptr;
    SD = nullptr;
}

Player::Player(string n)
{
    name = n;
    D = nullptr;
    SD = nullptr;
}

Player::~Player()
{
}

Deck* Player::getDeck()
{
    return D;
}

SideDeck* Player::getSideDeck()
{
    return SD;
}

string Player::getName()
{
    return name;
}