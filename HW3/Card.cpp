#include "Card.h"

using namespace std;

Card::Card(int inval)
{
    data = inval;
    next = nullptr;
}

void Card::setData(int inval)
{
    data = inval;
}

void Card::setNext(Card *n)
{
    next = n;
}

int Card::getData()
{
    return (data);
}

Card *Card::getNext()
{
    return (next);
}