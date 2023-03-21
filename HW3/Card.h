#include <string>
using namespace std;

class Card
{
public:
    int data;   // value of card
    Card *next; // pointer to next card in the deck

    // Constructor (Takes an invalue of type 'int')
    Card(int inval);

    void setData(int inval);
    void setNext(Card *n);

    int getData();
    Card *getNext();
};