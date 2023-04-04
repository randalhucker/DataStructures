#include <iostream>
#include <iomanip>
#include <string>
#include "HashTable.cpp"
#include "Part.h"
#include <vector>

using namespace std;

vector<Part *> vect;

void showMenu()
{
    cout << endl;
    cout << "0: Exit Testing" << endl;
    cout << "1: AddItem(Part*)" << endl;
    cout << "2: RemoveItem(Part*)" << endl;
    cout << "3: GetItem(Part*)" << endl;
    cout << "4: GetLength()" << endl;
    cout << "5: IsEmpty()" << endl;
}

Part *createPart()
{
    int S;
    int P;
    int Q;
    int L;
    string D;
    string U;
    cin.ignore();
    cout << "Please Add Info to Create a Part:" << endl;
    cout << "SKU > ";
    cin >> S;
    cout << endl;
    cout << "Price > ";
    cin >> P;
    cout << endl;
    cout << "Quanity on Hand (optional, enter 0 to skip) > ";
    cin >> Q;
    cout << endl;
    cout << "Lead Time (days to order) > ";
    cin >> L;
    cout << endl;
    cout << "Description > ";
    cin >> D;
    cout << endl;
    cout << "Unit of measure (ft, lb, per, etc...) > ";
    cin >> U;
    cout << endl;
    if (Q == 0)
    {
        return (new Part(D, U, S, P, L));
    }
    return (new Part(D, U, S, P, L, Q));
}

Part *FindPart()
{
    int sku = 0;
    cout << "Enter the SKU number of the part you'd like to retrieve / locate. This must be a part you have already created." << endl;
    cout << "> ";
    cin >> sku;
    cout << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect.at(i)->GetSKU() == sku)
        {
            return (vect.at(i));
        }
    }
    return (nullptr);
}

int main()
{
    int ans = 1;
    int MenuAns = 0;

    HashTable<Part> *Table = new HashTable<Part>();

    showMenu(); // gives choices
    cout << "> ";
    cin >> MenuAns;

    Part *p = nullptr;
    bool e = true;
    int l = 0;

    while (ans != 0)
    {
        cout << endl;
        switch (MenuAns)
        {
        case 1: // add
            p = createPart();
            vect.push_back(p);
            Table->AddItem(p);
            break;
        case 2: // remove
            p = FindPart();
            if (p == nullptr)
            {
                cout << "This part could not be found in your list." << endl;
            }
            else
            {
                Part *RetPart = Table->RemoveItem(p);
                cout << RetPart->GetPartInfo() << endl;
            }
            break;
        case 3: // get item
            p = FindPart();
            if (p == nullptr)
            {
                cout << "The SKU number does not match a part that you have created." << endl;
            }
            else
            {
                Part *RetPart = Table->GetItem(p);
                cout << RetPart->GetPartInfo() << endl;
            }
            break;
        case 4: // size
            cout << "Your List has " << Table->GetLength() << " parts in it." << endl;
            break;
        case 5: // is empty
            e = Table->isEmpty();
            if (e)
            {
                cout << "Your list is empty." << endl;
            }
            else
            {
                cout << "Your list isn't empty." << endl;
            }
            break;
        default:
            ans = 0;
            break;
        }

        if (ans != 0)
        {
            showMenu(); // gives choices
            cout << "> ";
            cin >> MenuAns;
        }
    }

    delete p;

    return 0;
}
