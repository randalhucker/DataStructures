#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <iostream>
using namespace std;

class Show
{
protected:
    string Title;
    string Description;

public:
    // Constructors / destructor
    Show();                   // Default Constructor
    Show(string T, string D); // Fill constructor for imperial units
    ~Show();                  // Destructor

    // Getters
    string getTitle();
    string getDescription();

    // Setters
    void setTitle(string T);
    void setDescription(string D);

    // Virtual Play Function
    virtual void Play();

    // Detail Function
    void Details();
};

#endif