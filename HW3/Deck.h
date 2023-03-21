#pragma once
#include <string>

using namespace std;

class Deck
{
private:
    Node<T> *head = nullptr;
    int length = 0;
    Node<T> *pnext;

public:
    Deck(T h);
    ~Deck();
    void InsertHead(T inVal);
    void InsertTail(T InVal);
    void InsertOrdered(T InVal);
    T RemoveFront();
    T RemoveEnd();
    T Remove(T key);
    void PrintList();
    T Find(T key);
    T GetNext(); // goes through list and throws exception when reaches the end of
};