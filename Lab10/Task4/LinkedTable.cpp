#pragma once
#include "LinkedTable.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

template <class T>
LinkedTable<T>::LinkedTable()
{
    MAX_SIZE = 100;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i]->head = nullptr;
    }
}

template <class T>
LinkedTable<T>::LinkedTable(int s)
{
    MAX_SIZE = s;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        arr[i] = nullptr;
    }
}

template <class T>
LinkedTable<T>::~LinkedTable()
{
}

// The sum of all the ASCII values for the passed in string and modulus by the maximum size of the table
template <class T>
int LinkedTable<T>::Hash(string s)
{
    int HashValue = 0;
    for (int i = 0; i < s.length(); i++)
    {
        HashValue += (int)s[i];
    }
    return (HashValue % MAX_SIZE);
}

template <class T>
void LinkedTable<T>::AddItem(T *inval)
{
    int index = Hash(*inval);
    if (arr[index] == nullptr)
    {
        arr[index] = new LinkedList<T>();
    }
    else
    {
        arr[index]->AddItem(inval);
    }
    numItems++;
}

template <class T>
T *LinkedTable<T>::GetItem(T *key)
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash(*key);
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }

    return arr[index]->GetItem(key);
}

template <class T>
T *LinkedTable<T>::RemoveItem(T *key) // changes
{
    if (isEmpty())
    {
        throw EmptyTableException();
    }
    int index = Hash(*key);
    if (arr[index] == nullptr)
    {
        throw ItemNotFoundException();
    }
    return arr[index]->Remove(key);
    numItems--;
}

template <class T>
int LinkedTable<T>::GetLength()
{
    return (numItems);
}

template <class T>
bool LinkedTable<T>::isEmpty()
{
    if (numItems == 0)
    {
        return true;
    }
    return false;
}