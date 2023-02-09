
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
    cout << "Press 4 for an instance of a Movie declared as a Show." << endl;
    cout << "Press 5 for an instance of a TV Show declared as a Show." << endl;
    cout << endl;
}

void TheMegaPrint(Show *s)
{
    cout << "Details: " << endl;
    s->Details();
    cout << endl
         << "Play: " << endl;
    s->Play();
}

template <typename T>
void TheMegaPrintOther(T s)
{
    cout << "Details: " << endl;
    s->Details();
    cout << endl
         << "Play: " << endl;
    s->Play();
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
            cin.ignore();
            string Title;
            string Description;
            cout << "Please enter the Show's Title: ";
            getline(cin, Title);
            cout << "Please enter the Show's Description: ";
            getline(cin, Description);
            cout << endl;

            Show *instance = new Show(Title, Description);
            TheMegaPrint(instance);
        }
        else if (MenuAns == 2)
        {
            cin.ignore();
            string Title;
            string Description;
            string Credits;
            cout << "Please enter the Movie's Title: ";
            getline(cin, Title);
            cout << "Please enter the Movie's Description: ";
            getline(cin, Description);
            cout << "Please enter the Movie's Credits: ";
            cin >> Credits;
            cout << endl;

            Movie *instance = new Movie(Title, Description, Credits);
            TheMegaPrintOther(instance);
        }
        else if (MenuAns == 3)
        {
            cin.ignore();
            string Title;
            string Description;
            int Seasons;
            int Episodes;
            cout << "Please enter the TvShow's Title: ";
            getline(cin, Title);
            cout << "Please enter the TvShow's Description: ";
            getline(cin, Description);
            cout << "Please enter the number of Seaons: ";
            cin >> Seasons;
            cout << "Please enter the number of Episodes in each season: ";
            cin >> Episodes;
            cout << endl;

            TvShow *instance = new TvShow(Title, Description, Seasons, Episodes);
            TheMegaPrintOther(instance);
        }
        else if (MenuAns == 4)
        {
            cin.ignore();
            string Title;
            string Description;
            string Credits;
            cout << "Please enter the Movie's Title: ";
            getline(cin, Title);
            cout << "Please enter the Movie's Description: ";
            getline(cin, Description);
            cout << "Please enter the Movie's Credits: ";
            cin >> Credits;
            cout << endl;

            Show *instance = new Movie(Title, Description, Credits);
            TheMegaPrint(instance);
        }
        else if (MenuAns == 5)
        {
            cin.ignore();
            string Title;
            string Description;
            int Seasons;
            int Episodes;
            cout << "Please enter the TvShow's Title: ";
            getline(cin, Title);
            cout << "Please enter the TvShow's Description: ";
            getline(cin, Description);
            cout << "Please enter the number of Seasons: ";
            cin >> Seasons;
            cout << "Please enter the number of Episodes in each season: ";
            cin >> Episodes;
            cout << endl;

            Show *instance = new TvShow(Title, Description, Seasons, Episodes);
            TheMegaPrint(instance);
        }
        cout << endl;
        cout << "Would you like to continue testing? Enter '1' for yes, anything else for no: ";
        cin >> ans;
        cout << endl;
    }

    return 0;
}