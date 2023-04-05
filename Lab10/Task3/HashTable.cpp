#pragma once
#include "HashTable.h"
#include "HashExceptions.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

template <class T>
HashTable<T>::HashTable()
{
    MAX_SIZE = 100;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = nullptr;
        deleted[i] = false;
    }
}

template <class T>
HashTable<T>::HashTable(int s)
{
    MAX_SIZE = s;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = nullptr;
        deleted[i] = false;
    }
}

template <class T>
HashTable<T>::~HashTable()
{
}

// The sum of all the ASCII values for the passed in string and modulus by the maximum size of the table
template <class T>
int HashTable<T>::Hash(string s)
{
    int HashValue = 0;
    for (int i = 0; i < s.length(); i++)
    {
        HashValue += (int)s[i];
    }
    return (HashValue % MAX_SIZE);
}

template <class T>
void HashTable<T>::AddItem(T *inval)
{ // Linear probing
    int index = Hash(string(*inval));

    if (arr[index] == nullptr)
    {
        arr[index] = inval;
        deleted[index] = false;
        numItems++;
        return;
    }

    while ((arr[index] != nullptr && arr[index] != inval) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE; // wraps around
    }
    arr[index] = inval;
    numItems++;
    deleted[index] = false;
}

template <class T>
int HashTable<T>::Find(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash((string)*key);
    while ((arr[index] != nullptr && arr[index] != *key) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    return index;
}

template <class T>
T *HashTable<T>::GetItem(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash((string)*key);
    while ((arr[index] != nullptr && arr[index] != key) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    return arr[index];
}

template <class T>
T *HashTable<T>::RemoveItem(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash((string)*key);
    while ((arr[index] != nullptr && arr[index] != key) || (deleted[index] == true))
    {
        index = (index + 1) % MAX_SIZE;
    }
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    T *temp = new T(*arr[index]);
    delete arr[index];
    deleted[index] = true;
    numItems--;
    return temp;
}

template <class T>
int HashTable<T>::GetLength()
{
    return (numItems);
}

template <class T>
bool HashTable<T>::isEmpty()
{
    if (numItems == 0)
    {
        return true;
    }
    return false;
}

// can use insert, remove, and find from LinkedList (and everything else)
// LL = LinkedList

/* class LinkedHashTable {
    LL *arr[MAX_SIZE];
    int numItems = 0;
    int Hash(int x);

void Inset (int inval) {
    int index = Hash(inval);
    if (arr[index] == nullptr) {
        arr[index] new LL;
    }
    arr[index]->Insert(inval);
    numItems++;
}

void Find (int key) {
    int index = Hash(key);
    if (arr[index] == nullptr) {
        throw ItemNotFoundException();
    }
    return arr[index]->Find(key);
}

// int Remove (int key) {
//     int index = Hash(key);
//     if (arr[index] == nullptr) {
//         throw ItemNotFoundException();
//     }
//     return arr[index]->Remove(key);
//     numItems--;
// } */
