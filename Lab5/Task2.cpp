#pragma once
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "MovieShelf.h"

using namespace std;

void showMenu()
{
    cout << endl;
    cout << "Enter 1 to add a movie to the shelf." << endl;
    cout << "Enter 2 remove a movie from the shelf." << endl;
    cout << "Enter 3 see how many movies are currently on the shelf." << endl;
    cout << "Enter 4 to quit." << endl;
}

int main()
{
    MovieShelf *Shelf = new MovieShelf();
    int ans = 1;
    while (ans == 1)
    {
        int MenuAns;
        showMenu(); // gives choices
        cin >> MenuAns;
        cout << endl;
        if (MenuAns == 1) // add movie
        {
            // user input
            cin.ignore();
            string Title;
            string Description;
            cout << "Please enter the Movie's Title: ";
            getline(cin, Title);
            cout << "Please enter the Movie's Description: ";
            getline(cin, Description);
            cout << endl;

            // dynamically create instance
            Shelf->addMovie(new Movie(Title, Description));
        }
        else if (MenuAns == 2) // remove movie
        {
            // TODO ADD EMPTY SHELF EXCEPTION
            Movie *RemovedMovie = Shelf->removeMovie();
            cout << "You're now holding: " << endl;
            RemovedMovie->Details();
        }
        else if (MenuAns == 3) // show movie count
        {
            cout << "There are " << Shelf->getMovieCount() << " movie(s) on the shelf." << endl;
        }
        else // quit
        {
            ans = 0;
        }
    }

    return 0;
}