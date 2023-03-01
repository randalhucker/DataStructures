#include <string>
using namespace std;

template <class T>
class OrderedList
{
private:
    T **PointerArray;
    int Size;
    int numItems;

public:
    // Constructor (Takes an invalue of type 'T')
    OrderedList();

    void addItem(T inval);
    T removeItem(T n);
    int FindItem(T val); // helper function to remove item

    bool isEmpty();
    bool isFull();
    void MakeEmpty();
};