// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Product.h"

using namespace std;

// Function prototypes
void calcSales(Product[], int);
void showOrder(Product[], int);
void dualSort(Product[], int);
void showTotals(Product[], int);

int main()
{

    string Filename; // Name of the file
    ifstream ProductFile;
    string line;
    int TotalProducts;
    int count = 0;

    cout << "Enter Product Filename: ";
    cin >> Filename;

    ProductFile.open(Filename);

    while (!ProductFile.eof())
    {
        getline(ProductFile, line);
        count++;
    }

    TotalProducts = ((count + 1) / 6);

    ProductFile.seekg(0, ios::beg);

    Product ProductArray[TotalProducts];

    // Input ProductArray from file provided
    for (int i = 0; i < TotalProducts; i++)
    {
        string temp;
        getline(ProductFile, temp, ' ');
        getline(ProductFile, temp);
        ProductArray[i].setID(stoi(temp));

        getline(ProductFile, temp, ' ');
        getline(ProductFile, temp);
        ProductArray[i].setUnits(stoi(temp));

        getline(ProductFile, temp, ' ');
        getline(ProductFile, temp);
        ProductArray[i].setPrice(stod(temp));

        getline(ProductFile, temp, ' ');
        getline(ProductFile, temp);
        ProductArray[i].setDescription(temp);

        getline(ProductFile, temp, ' ');
        getline(ProductFile, temp);
        if (temp == "False")
        {
            ProductArray[i].setTaxExempt(false);
        }
        else
        {
            ProductArray[i].setTaxExempt(true);
        }
    }

    // Calculate each product's sales.
    calcSales(ProductArray, TotalProducts);

    // Sort the elements in the sales array in descending
    // order and shuffle the ID numbers in the id array to
    // keep them in parallel.
    dualSort(ProductArray, TotalProducts);

    // Set the numeric output formatting.
    cout << setprecision(2) << fixed << showpoint;

    // Display the products and sales amounts.
    showOrder(ProductArray, TotalProducts);

    // Display total units sold and total sales.
    showTotals(ProductArray, TotalProducts);
    return 0;
}

//****************************************************************
// Definition of calcSales. Accepts array of products to access  *
// units, prices, and sales. The size of these arrays is passed  *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************
void calcSales(Product p[], int num)
{
    for (int index = 0; index < num; index++)
    {
        p[index].setSales();
    }
}

//***************************************************************
// Definition of function dualSort. Accepts array of products   *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the product array are       *
// exchanged identically as the sales. size is the number       *
// of elements in each array.                                   *
//***************************************************************

void dualSort(Product p[], int size)
{
    int startScan, maxIndex;
    Product temp;
    double maxValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;
        temp = p[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (p[index].getSales() > temp.getSales())
            {
                temp = p[index];
                maxIndex = index;
            }
        }
        p[maxIndex] = p[startScan];
        p[startScan] = temp;
    }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(Product p[], int num)
{
    cout << "Product Number\tSales\n";
    cout << "----------------------------------\n";
    for (int index = 0; index < num; index++)
    {
        cout << p[index].getID() << "\t\t$";
        cout << setw(8) << p[index].getSales() << endl;
    }
    cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts product array       *
// as argument. The size of these arrays is passed into num.      *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(Product p[], int num)
{
    int totalUnits = 0;
    double totalSales = 0.0;

    for (int index = 0; index < num; index++)
    {
        totalUnits += p[index].getUnits();
        totalSales += p[index].getSales();
    }
    cout << "Total units Sold:  " << totalUnits << endl;
    cout << "Total sales:      $" << totalSales << endl;
}
