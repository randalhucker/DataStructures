#pragma once
#ifndef _LHT_
#define _LHT_
#include <string>
#include <vector>

using namespace std;

template <class T>
class HashTable
{

protected:
    int MAX_SIZE = 100;
    T **arr = new T*[MAX_SIZE];
    bool *deleted = new bool[MAX_SIZE]; // initialize to false
    int numItems = 0;

public:
    HashTable();
    HashTable(int s);
    ~HashTable();
    int Hash(string s);
    void AddItem(T *inval);
    T *RemoveItem(T *key);
    int Find(T *key);
    T *GetItem(T *key);
    int GetLength();
    bool isEmpty();
};

#endif