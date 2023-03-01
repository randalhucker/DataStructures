#include "LinkedList.h"
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList(T h)
{
    head = new Node<T>(h);
}

template <class T>
LinkedList<T>::~LinkedList()
{
}

template <class T>
void LinkedList<T>::InsertHead(T inVal)
{
    if (length == 0)
    {
        head = new Node(inVal);
    }
    else
    {
        Node *h = new Node(inval);
        h->next = head;
        head = h;
    }
    length++;
}

template <class T>
void LinkedList<T>::InsertTail(T InVal)
{
    Node *temp = head;
    if (length == 0)
    {
        InsertHead(InVal);
    }
    else
    {
        while (temp->next != null)
        {
            temp = temp->next;
        }
        temp->next = new Node(inVal);
        length++;
    }
}

template <class T>
void LinkedList<T>::InsertOrdered(T InVal)
{
    if (head == null)
    {
        head = new Node(InVal);
        length++;
    }
    else if (InVal < head->data)
    { // insert head case
        InsertHead(InVal);
    }
    else
    { // insert middle and tail cases
        Node *temp = head;
        while ((temp->next != null) && (temp->next->data < InVal))
        {
            temp = temp->next;
        }
        Node newNode = new Node(inVal);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }
}

template <class T>
T LinkedList<T>::RemoveFront()
{
    if (isEmpty())
    {
        throw EmptyListException();
    }
    Node *temp = head;
    head = head->next;
    int retval = temp->data;
    delete temp;
    length--;
    return retval
}

template <class T>
T LinkedList<T>::RemoveEnd()
{
    if (isEmpty())
    {
        throw EmptyListException()
    }
    if (length == 1)
    {
        int retval = head->data;
        delete head;
        head = null;
        length--;
        return retval;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    int retval = temp->next->data;
    delete temp->next;
    length--;
    return retval;
}

template <class T>
T LinkedList<T>::Remove(T key)
{
    if (isEmpty())
    {
        throw EmptyListException()
    }
    Node *temp = head;
    if (head->data == key)
    {
        return (RemoveFront());
    }
    while (temp->next != null && temp->next->data != key)
    {
        temp = temp->next;
    }
    if (temp->next == null)
    {
        throw ItemNotFoundException();
    }
    Node *retptr = temp->next;
    temp->next = temp->next->next;
    int retval = retptr->data;
    delete retptr;
    length--;
    return retval;
}

template <class T>
void LinkedList<T>::PrintList()
{
    Node *temp = head;
    for (int i = 0; i < length; i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

template <class T>
T LinkedList<T>::Find(T key)
{
    if (isEmpty())
    {
        throw EmptyListException()
    }
    Node *temp = head;
    while (temp != null)
    {
        if (temp->data == key)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    throw ItemNotFoundException();
}

template <class T>
T LinkedList<T>::GetNext()
{ // goes through list and throws exception when reaches the end of
    // the list, next time it is called it starts at the head
    if (pnext == null)
    {
        pnext = head;
        throw EndOfListException();
    }
    else
    {
        pnext = pnext->next;
        return (pnext->data);
    }
}