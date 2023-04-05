#pragma once
#ifndef _HT_
#define _HT_
#include <string>
#include <vector>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "HashTable.h"
#include "HashTable.cpp"

using namespace std;

template <class T>
class LinkedTable : protected HashTable<T>
{

protected:
    int MAX_SIZE;
    LinkedList<T> **arr = new LinkedList<T>*[MAX_SIZE];
    int numItems = 0;

public:
    LinkedTable();
    LinkedTable(int s);
    ~LinkedTable();
    int Hash(string s);
    void AddItem(T *inval);
    T *RemoveItem(T *key);
    T *GetItem(T *key);
    int GetLength();
    bool isEmpty();
};

#endif