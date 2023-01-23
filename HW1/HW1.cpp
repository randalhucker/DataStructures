#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
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
        destFile << "Moby Dick letter frequency:" << endl;
        destFile << setprecision(2) << endl;
        for (int i = 0; i < 27; i++)
        {
            double percentage = (b.letterFreq[i] / b.totalChars);
            destFile << (c + i) << ": " << percentage << "%" << endl;
        }
    }
}

int main()
{
    string fileName;
    ifstream targetFile;
    // cout << "Please Enter the File Name: ";
    fileName = "MobyDick.txt";
    // cin >> fileName;

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
    getline(targetFile, b.lastName, '\r');

    string contentsWatch;

    while (contentsWatch != "Contents:\r")
    {
        getline(targetFile, contentsWatch);
    }

    char c;

    while (!targetFile.eof())
    {
        targetFile.get(c);
        // makes c lowercase if it isn't already
        if (c >= 65 && c <= 92)
        {
            c += 32;
        }

        switch (c)
        {
        case 10:
            b.LC += 1;
            break;
        case 32:
            b.WC += 1;
            break;
        case 97:
            b.letterFreq[0] += 1;
            b.totalChars += 1;
            break;
        case 98:
            b.letterFreq[1] += 1;
            b.totalChars += 1;
            break;
        case 99:
            b.letterFreq[2] += 1;
            b.totalChars += 1;
            break;
        case 100:
            b.letterFreq[3] += 1;
            b.totalChars += 1;
            break;
        case 101:
            b.letterFreq[4] += 1;
            b.totalChars += 1;
            break;
        case 102:
            b.letterFreq[5] += 1;
            b.totalChars += 1;
            break;
        case 103:
            b.letterFreq[6] += 1;
            b.totalChars += 1;
            break;
        case 104:
            b.letterFreq[7] += 1;
            b.totalChars += 1;
            break;
        case 105:
            b.letterFreq[8] += 1;
            b.totalChars += 1;
            break;
        case 106:
            b.letterFreq[9] += 1;
            b.totalChars += 1;
            break;
        case 107:
            b.letterFreq[10] += 1;
            b.totalChars += 1;
            break;
        case 108:
            b.letterFreq[11] += 1;
            b.totalChars += 1;
            break;
        case 109:
            b.letterFreq[12] += 1;
            b.totalChars += 1;
            break;
        case 110:
            b.letterFreq[13] += 1;
            b.totalChars += 1;
            break;
        case 111:
            b.letterFreq[14] += 1;
            b.totalChars += 1;
            break;
        case 112:
            b.letterFreq[15] += 1;
            b.totalChars += 1;
            break;
        case 113:
            b.letterFreq[16] += 1;
            b.totalChars += 1;
            break;
        case 114:
            b.letterFreq[17] += 1;
            b.totalChars += 1;
            break;
        case 115:
            b.letterFreq[18] += 1;
            b.totalChars += 1;
            break;
        case 116:
            b.letterFreq[19] += 1;
            b.totalChars += 1;
            break;
        case 117:
            b.letterFreq[20] += 1;
            b.totalChars += 1;
            break;
        case 118:
            b.letterFreq[21] += 1;
            b.totalChars += 1;
            break;
        case 119:
            b.letterFreq[22] += 1;
            b.totalChars += 1;
            break;
        case 120:
            b.letterFreq[23] += 1;
            b.totalChars += 1;
            break;
        case 121:
            b.letterFreq[24] += 1;
            b.totalChars += 1;
            break;
        case 122:
            b.letterFreq[25] += 1;
            b.totalChars += 1;
            break;
        default:
            break;
        }
    }
    targetFile.close(); // Close File

    b.WC += 1; // Account for last word w/out a space.

    char frequencyBool;

    // cout << "Would you like to see letter frequency?(Y/N)";
    // cin >> frequencyBool;

    frequencyBool = 'Y';

    while (frequencyBool != 'Y' && frequencyBool != 'N')
    {
        cout << "Please enter Y or N.";
        cin >> frequencyBool;
    }

    bool fileExists = exists("CardCatalog.txt");

    print_book_data("CardCatalog.txt", b, frequencyBool, fileExists);

    return 0;
}