#pragma once
#include "Show.h"
#include <string>
#include <iostream>
using namespace std;

class TvShow : public Show
{
private:
    string Episodes[100][100];

public:
    TvShow();                                 // Default Constructor
    TvShow(string T, string D, int s, int e); // Fill constructor for imperial units
    ~TvShow();

    // new Getter
    string getEpisode(int s, int e);

    // new Setter
    void setEpisodes(int s, int e);

    void Play();
    void Details();
    void InitializeArray(); // initializes episode array to "0"
};