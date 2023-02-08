#pragma once
#include "TvShow.h"
#include <string>
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

// Default constructor
TvShow::TvShow()
{
    Title = "";
    Description = "";
    InitializeArray();
}

// Fill constructor
TvShow::TvShow(string T, string D, int s, int e)
{
    Title = T;
    Description = D;
    InitializeArray();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < e; j++)
        {
            Episodes[i][j] = "Season: " + to_string(i) + " Episode: " + to_string(j);
        }
    }
}

TvShow::~TvShow()
{

}

// new Getter
string TvShow::getEpisode(int s, int e)
{
    return Episodes[s - 1][e - 1];
}

// new Setter (passes in nuumber of seasons, and number of episodes (came number of episodes in all seasons))
void TvShow::setEpisodes(int s, int e)
{
    InitializeArray();
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < e; j++)
        {
            Episodes[i][j] = "Season: " + to_string(i+1) + " Episode: " + to_string(j+1);
        }
    }
}

void TvShow::Play()
{
    int s, e;
    cout << "Please enter the Season you'd like to play: ";
    cin >> s;
    cout << endl;
    cout << "Please enter the Episode you'd like to play: ";
    cin >> e;
    cout << endl;
    cout << "Now Playing: " + Episodes[s-1][e-1] << " of " + Title << endl;
}

void TvShow::Details() //How can overide?
{
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Description: " << getDescription() << endl;
    int counter = 0;
    for (int i = 0; i < sizeof(Episodes); i++)
    {
        if (Episodes[i] == 0)
        {
            break;
        }
        counter++;
    }
    cout << "Number of Seasons: " << counter << endl;
    cout << endl;
}

void TvShow::InitializeArray()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            Episodes[i][j] = "0";
        }
    }
}