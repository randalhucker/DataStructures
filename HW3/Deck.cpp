#pragma once
#include "Deck.h"

Deck::Deck(Card *h)
{
    head = h;
}

Deck::Deck()
{
    head = nullptr;
}

Deck::~Deck()
{
}

void Deck::Enqueue(Card *inVal)
{
    if (isEmpty())
    {
        head = inVal;
    }
    else
    {
        Card *h = inVal;
        h->next = head;
        head = h;
    }
    length++;
}

Card* Deck::Dequeue()
{
    if (isEmpty())
    {
        throw EmptyDeckException();
    }
    if (length == 1)
    {
        Card* retval = head;
        delete head;
        head = nullptr;
        length--;
        return retval;
    }
    Card *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    Card* retval = temp->next;
    delete temp->next;
    length--;
    return retval;
}

Card* Deck::Peek()
{
    return head;
}

bool Deck::isEmpty()
{
    if (length == 0)
    {
        return true;
    }
    return false;
}

int Deck::getLength(){
    return length;
}
