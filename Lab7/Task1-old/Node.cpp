#include "Node.h"

using namespace std;

template <class T>
Node<T>::Node(T inval)
{
    data = inval;
    next = nullptr;
}

template <class T>
void Node<T>::setData(T inval)
{
    data = inval;
}

template <class T>
void Node<T>::setNext(T *n)
{
    next = n;
}

template <class T>
T Node<T>::getData()
{
    return (data);
}

template <class T>
T Node<T>::getNext()
{
    return (next);
}