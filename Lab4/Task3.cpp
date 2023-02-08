#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Show.h"
#include "Movie.h"
#include "TvShow.h"

using namespace std;

void showOperatorMenu()
{
    cout << "Press 1 for an instance of Show." << endl;
    cout << "Press 2 for an instance of Movie." << endl;
    cout << "Press 3 for an instance of TV Show." << endl;
    cout << "Press 4 for an instance of a MOVIE declared as a Show." << endl;
    cout << "Press 5 for an instance of a TV Show declared as a Show." << endl;
}

void TheMegaPrint(Show s)
{
    cout << "Details: " << endl;
    s.Details();
    cout << "Play: " << endl;
    s.Play();
}

int main()
{
    int ans = 1;
    while (ans == 1)
    {
        int MenuAns = 0;
        showOperatorMenu();
        cin >> MenuAns;
        cout << endl;
        if (MenuAns == 1)
        {
            string Title;
            string Description;
            cout << "Please enter the Show's Title: ";
            cin >> Title;
            cout << endl;
            cout << "Please enter the Show's Description: ";
            cin >> Description;
            cout << endl;

            Show instance = Show(Title, Description);
        }
        else if (MenuAns == 2)
        {
            string Title;
            string Description;
            string Credits;
            cout << "Please enter the Movie's Title: ";
            cin >> Title;
            cout << endl;
            cout << "Please enter the Movie's Description: ";
            cin >> Description;
            cout << endl;
            cout << "Please enter the Movie's Credits: ";
            cin >> Credits;
            cout << endl;

            Movie instance = Movie(Title, Description, Credits);
        }
        else if (MenuAns == 3)
        {
            string Title;
            string Description;
            int Seasons;
            int Episodes;
            cout << "Please enter the TvShow's Title: ";
            cin >> Title;
            cout << endl;
            cout << "Please enter the TvShow's Description: ";
            cin >> Description;
            cout << endl;
            cout << "Please enter the number of Seasons: ";
            cin >> Seasons;
            cout << "Please enter the number of Episodes in each season: ";
            cin >> Episodes;
            cout << endl;

            TvShow instance = TvShow(Title, Description, Seasons, Episodes);
        }
        else if (MenuAns == 4)
        {
            string Title;
            string Description;
            string Credits;
            cout << "Please enter the Movie's Title: ";
            cin >> Title;
            cout << endl;
            cout << "Please enter the Movie's Description: ";
            cin >> Description;
            cout << endl;
            cout << "Please enter the Movie's Credits: ";
            cin >> Credits;
            cout << endl;

            Show *instance = new Movie(Title, Description, Credits);
        }
        else if (MenuAns == 5)
        {
            string Title;
            string Description;
            int Seasons;
            int Episodes;
            cout << "Please enter the TvShow's Title: ";
            cin >> Title;
            cout << endl;
            cout << "Please enter the TvShow's Description: ";
            cin >> Description;
            cout << endl;
            cout << "Please enter the number of Seasons: ";
            cin >> Seasons;
            cout << "Please enter the number of Episodes in each season: ";
            cin >> Episodes;
            cout << endl;

            Show *instance = new TvShow(Title, Description, Seasons, Episodes);
        }

        cout << "Would you like to continue testing? Enter '1' for yes, anything else for no";
        cin >> ans;
    }

    return 0;
}