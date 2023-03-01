#include <string>
#include "ListExceptions.h"
#include "Node.h"

template <class T>
class LinkedList
{
private:
    Node<T> *head = nullptr;
    int length = 0;
    Node<T> *pnext;

public:
    LinkedList(T h);
    ~LinkedList();
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
