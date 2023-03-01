#include <string>
using namespace std;

template <class T>
class Node
{
private:
    T data;     // Array of pointers to data
    Node *next; // holds index of the next available space

public:
    // Constructor (Takes an invalue of type 'T')
    Node(T inval);

    void setData(T inval);
    void setNext(T *n);

    T getData();
    T getNext();
};