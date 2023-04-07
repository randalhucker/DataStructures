#pragma once
#ifndef _HT_
#define _HT_
#include <string>
#include <vector>
#include "HashTable.h"
#include "HashTable.cpp"

using namespace std;

template <class T>
class LinkedTable : public HashTable<T>
{

protected:
    LinkedList<T> **arr;

public:
    LinkedTable(int s = 100);
    ~LinkedTable();
    int Hash(string s);
    void AddItem(T *inval);
    T *RemoveItem(T *key);
    T *GetItem(T *key);
    int GetLength();
    bool isEmpty();
    int getComps();
    void ResetComps();
};

#endif