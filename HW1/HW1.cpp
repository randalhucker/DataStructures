#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

struct Book
{
    string Title;
    string firstName;
    string lastName;
    int WC;
    int LC;
    double totalChars;
    double letterFreq[26];
};

bool exists(const string &fileName)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

void print_book_data(const string &fileName, Book &b, char &printFrequency, bool &exists)
{
    ofstream destFile;

    if (!exists)
    {
        destFile.open(fileName, std::ios::out);
    }
    else
    {
        destFile.open(fileName, std::ios::app);
        destFile << endl;
    }
    destFile << "Title: " << b.Title << endl;
    destFile << "Full Author: " << b.firstName << " " << b.lastName << endl;
    destFile << "Author First Name: " << b.firstName << endl;
    destFile << "Author Last Name: " << b.lastName << endl;
    destFile << "Word Count: " << b.WC << endl;
    destFile << "Line Count: " << b.LC << endl;

    if (printFrequency == 'Y')
    {
        char c = 97;
        b.Title.erase(remove(b.Title.begin(), b.Title.end(), '\r'), b.Title.end());
        destFile << (b.Title + " letter frequency:");
        destFile << setprecision(3) << endl;
        for (int i = 0; i < 26; i++)
        {
            destFile << c << ": " << ((b.letterFreq[i] / b.totalChars) * 100) << "%" << endl;
            c++;
        }
    }
    destFile.close();
}

void body_function()
{
    string fileName;
    ifstream targetFile;
    cout << "Please Enter the File Name: ";
    cin >> fileName;
    //fileName = "PeterPan.txt";

    targetFile.open(fileName);

    while (!targetFile)
    {
        cout << "Error: File Name Provided Could Not Be Opened" << endl;
        cout << "Please try again: " << endl;
        cin >> fileName;
        targetFile.open(fileName);
    }

    Book b = {"", "", "", 0, 0, 0, {}};

    memset(b.letterFreq, 0, sizeof(b.letterFreq));

    getline(targetFile, b.Title);
    getline(targetFile, b.firstName, ' ');
    getline(targetFile, b.lastName, '\n');

    string contentsWatch = "";

    while (contentsWatch != "Contents:" && contentsWatch != "Contents: " && contentsWatch != "Contents:\r")
    {
        getline(targetFile, contentsWatch);
    }

    char c;
    int flag = 0;

    while (!targetFile.eof())
    {
        targetFile.get(c);
        // makes c lowercase if it isn't already
        if (c >= 65 && c <= 92)
        {
            c += 32;
        }
        if (targetFile.eof())
        {
            break;
        }

        if (flag == 1)
        {
            if (c >= 97 && c <= 122)
            {
                b.WC++;
                flag = 0;
            }
        }

        switch (c)
        {
        case 10:
            b.LC++;
            flag = 1;
            break;
        case 32:
            b.WC++;
            break;
        case 97:
            b.letterFreq[0]++;
            b.totalChars++;
            break;
        case 98:
            b.letterFreq[1]++;
            b.totalChars++;
            break;
        case 99:
            b.letterFreq[2]++;
            b.totalChars++;
            break;
        case 100:
            b.letterFreq[3]++;
            b.totalChars++;
            break;
        case 101:
            b.letterFreq[4]++;
            b.totalChars++;
            break;
        case 102:
            b.letterFreq[5]++;
            b.totalChars++;
            break;
        case 103:
            b.letterFreq[6]++;
            b.totalChars++;
            break;
        case 104:
            b.letterFreq[7]++;
            b.totalChars++;
            break;
        case 105:
            b.letterFreq[8]++;
            b.totalChars++;
            break;
        case 106:
            b.letterFreq[9]++;
            b.totalChars++;
            break;
        case 107:
            b.letterFreq[10]++;
            b.totalChars++;
            break;
        case 108:
            b.letterFreq[11]++;
            b.totalChars++;
            break;
        case 109:
            b.letterFreq[12]++;
            b.totalChars++;
            break;
        case 110:
            b.letterFreq[13]++;
            b.totalChars++;
            break;
        case 111:
            b.letterFreq[14]++;
            b.totalChars++;
            break;
        case 112:
            b.letterFreq[15]++;
            b.totalChars++;
            break;
        case 113:
            b.letterFreq[16]++;
            b.totalChars++;
            break;
        case 114:
            b.letterFreq[17]++;
            b.totalChars++;
            break;
        case 115:
            b.letterFreq[18]++;
            b.totalChars++;
            break;
        case 116:
            b.letterFreq[19]++;
            b.totalChars++;
            break;
        case 117:
            b.letterFreq[20]++;
            b.totalChars++;
            break;
        case 118:
            b.letterFreq[21]++;
            b.totalChars++;
            break;
        case 119:
            b.letterFreq[22]++;
            b.totalChars++;
            break;
        case 120:
            b.letterFreq[23]++;
            b.totalChars++;
            break;
        case 121:
            b.letterFreq[24]++;
            b.totalChars++;
            break;
        case 122:
            b.letterFreq[25]++;
            b.totalChars++;
            break;
        default:
            break;
        }
    }
    targetFile.close(); // Close File

    b.WC++; // Account for last word w/out a space.

    char frequencyBool;

    cout << "Would you like to see letter frequency?(Y/N)";
    cin >> frequencyBool;

    // frequencyBool = 'Y';

    while (frequencyBool != 'Y' && frequencyBool != 'N')
    {
        cout << "Please enter Y or N.";
        cin >> frequencyBool;
    }

    bool fileExists = exists("CardCatalog.txt");

    print_book_data("CardCatalog.txt", b, frequencyBool, fileExists);
}

int main()
{
    char anotherBook = 'Y';
    body_function();

    cout << "Do another book?(Y/N)";
    cin >> anotherBook;

    while (anotherBook == 'Y')
    {
        body_function();
        cout << "Do another book?(Y/N)";
        cin >> anotherBook;
        while (anotherBook != 'Y' && anotherBook != 'N')
        {
            cout << "Please enter Y or N.";
            cin >> anotherBook;
        }
    }

    return 0;
}