#include "Player.h"
#include <algorithm>
#include <array>
#include <random>
#include <iostream>

using namespace std;

Deck *GenerateDeck() // This funtion creates a complete deck of cards, shuffles it, and then returns the shuffled deck
{
    array<Card, 52> InitialDeck; // create a card array to allow for use of standard shuffling algorithm
    for (int i = 0; i < 13; i++)
    {
        InitialDeck[i] = Card(i + 1, "Hearts");
        InitialDeck[i + 13] = Card(i + 1, "Spades");
        InitialDeck[i + 26] = Card(i + 1, "Diamonds");
        InitialDeck[i + 39] = Card(i + 1, "Clubs");
    }

    // Shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(InitialDeck.begin(), InitialDeck.end(), default_random_engine(seed));

    // Declare deck
    Deck *D;

    // Enqueue shuffled cards into deck
    for (int i = 0; i < 52; i++)
    {
        D->Enqueue(new Card(InitialDeck[i]));
    }

    // Return Shuffled Deck
    return D;
}

void Deal(Deck *d) // deals the cards to the player
{
    for (int i = 0; i < 26; i++)
    {
        p->getDeck()->Enqueue(d->Dequeue());
        cpu->getDeck()->Enqueue(d->Dequeue());
    }
}

Player *p;
Player *cpu = new Player("CPU");

void PlayRound(){
    string peekans;
    cout << "Would you like to peek at your card? (Yes = 1, No = 0)" << endl;
    cin >> peekans;

    if (peekans == "1"){
        cout << "Your card is " << to_string(p->getDeck()->Peek()->getData()) << " of " << p->getDeck()->Peek()->getSuit() << endl;
        cout << "What would you like to do next? " << endl 
             << "Play your card alone (1)" << endl 
             << "Place your card on your side deck (2)" << endl 
             << "Play your card with the top card from your side deck (3)?" << endl;
    }
    else // play round 
    {
        
    }
}

int main()
{
    string name;
    cout << "Please Enter your name: " << endl;
    cout << "> ";
    cin >> name;
    cout << endl;

    p = new Player(name);

    Deal(GenerateDeck()); // generates a shuffled deck of cards and deals them to the players

    PlayRound();    
}