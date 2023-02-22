#include "Stack.cpp"
#include "Queue.cpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void run_main()
{
}

int main()
{
    int numWords = 0;
    const int maxChars = 50;
    int InputChoice = 0;
    string textline;
    string FileName;

    cout << "Enter 0 for File / Enter 1 for Terminal: " << endl;
    cout << "> ";
    cin >> InputChoice;
    cout << endl;

    while (InputChoice == 0 || InputChoice == 1)
    {
        if (InputChoice == 0)
        {
            char c;
            string word;
            string line;
            std::stringstream lineStream;
            cout << "Please enter the file name: " << endl;
            cout << "> ";
            cin >> FileName;

            ifstream targetFile;
            targetFile.open(FileName);

            while (!targetFile)
            {
                cin.ignore();
                cout << "Error: File Name Provided Could Not Be Opened" << endl;
                cout << "Please try again: " << endl;
                cout << "> ";
                cin >> FileName;
                cout << endl;
                targetFile.open(FileName);
            }

            while (getline(targetFile, line))
            {
                stringstream lineStream(line);
                while (getline(lineStream, line, ' '))
                {
                    ++numWords;
                }
                ++numWords;
            }

            targetFile.close();
        }
        else
        {
            cin.ignore();
            cout << "Please enter your line of text: " << endl;
            cout << "> ";
            getline(std::cin, textline);
            cout << endl;
            for (int i = 0; i < textline.size(); i++)
            {
                // check if current character is a space
                if (textline[i] == ' ')
                {
                    // if it is a space, increment word count
                    numWords++;
                }
            }
            if (textline.size())
            {
                numWords++;
            }
        }
        // figure out num words
        Queue<string> WordQueue = Queue<string>(numWords);
        // now put words into queue

        if (InputChoice == 0)
        {
            string word = "";
            string line;
            ifstream targetFile;
            targetFile.open(FileName);
            while (!targetFile.eof())
            {
                targetFile >> word;
                WordQueue.Enqueue(new string(word));
            }
        }
        else
        {
            string word;
            char c;
            for (int i = 0; i < textline.size(); i++)
            {
                // check if current character is a space
                c = textline[i];

                if (c == ' ')
                {
                    // if it is a space, add word to queue
                    WordQueue.Enqueue(new string(word));
                    word = "";
                }
                else
                {
                    word = word + c;
                }
            }
            WordQueue.Enqueue(new string(word)); // add final word
        }

        // try
        // {
        //     WordQueue.Enqueue(new string("this"));
        //     WordQueue.Enqueue(new string("is"));
        //     WordQueue.Enqueue(new string("a"));
        //     WordQueue.Enqueue(new string("test"));
        // }
        // catch (QueueOverflowException e)
        // {
        //     cout << e.what();
        // }
        // Begin letter reversal section
        Stack<char> LetterStack = Stack<char>(50); // stack size of 50 is long enough to hold longest word in english language
        string AnswerString = "";
        string *CurrentWord;
        while (WordQueue.Length() > 0)
        {
            CurrentWord = WordQueue.Dequeue();
            for (int i = 0; i < (*CurrentWord).length(); i++)
            {
                LetterStack.Push(new char((*CurrentWord).at(i)));
            }
            for (int j = 0; j < (*CurrentWord).length(); j++)
            {
                AnswerString.append((LetterStack.Pop()));
            }
            AnswerString.append(" ");
        }
        cout << "Reversed String: " << endl
             << AnswerString << endl
             << endl;
        cout << "Would you like to continue?" << endl;
        cout << "Enter 0 for File / Enter 1 for Terminal (Anything else to quit): " << endl;
        cout << "> ";
        cin >> InputChoice;
        cout << endl;
    }
}