// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void calcSales(struct productStruct[], int);
void showOrder(struct productStruct[], int);
void dualSort(struct productStruct[], int);
void showTotals(struct productStruct[], int);

// NUM_PRODS is the number of products produced.
const int NUM_PRODS = 9;

struct productStruct {
    int id;
    int units;
    double prices;
    double sales;
};

productStruct productArray[NUM_PRODS];

int main()
{   
   // Array with product ID numbers
   int id[NUM_PRODS] = {914, 915, 916, 917, 918, 919, 920,
                        921, 922};

   //// Array with number of units sold for each product
   int units[NUM_PRODS] = {842, 416, 127, 514, 437, 269, 97,
                           492, 212};

   //// Array with product prices
   double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95,
                               31.95, 14.95, 14.95, 16.95};

   //// Array to hold the computed sales amounts
   double sales[NUM_PRODS] = {};

   for (int i = 0; i < NUM_PRODS; i++) {
       productArray[i].id = id[i];
       productArray[i].units = units[i];
       productArray[i].prices = prices[i];
   }

   // Calculate each product's sales.
   calcSales(productArray, NUM_PRODS);

   // Sort the elements in the sales array in descending
   // order and shuffle the ID numbers in the id array to
   // keep them in parallel.
   dualSort(productArray, NUM_PRODS);

   // Set the numeric output formatting.
   cout << setprecision(2) << fixed << showpoint;

   // Display the products and sales amounts.
   showOrder(productArray, NUM_PRODS);

   // Display total units sold and total sales.
   showTotals(productArray, NUM_PRODS);
   return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num parameter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(productStruct productArray[], int num)
{
   for (int i = 0; i < num; i++)
       productArray[i].sales = productArray[i].units * productArray[i].prices;
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(productStruct productArray[], int size)
{
   int startScan, maxIndex, tempid;
   double maxValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      maxIndex = startScan;
      maxValue = productArray[startScan].sales;
      tempid = productArray[startScan].id;
      for(int index = startScan + 1; index < size; index++)
      {
         if (productArray[index].sales > maxValue)
         {
            maxValue = productArray[index].sales;
            tempid = productArray[index].id;
            maxIndex = index;
         }
      }
      productArray[maxIndex].sales = productArray[startScan].sales;
      productArray[maxIndex].id = productArray[startScan].id;
      productArray[startScan].sales = maxValue;
      productArray[startScan].id = tempid;
   }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(productStruct productArray[], int num)
{
   cout << "Product Number\tSales\n";
   cout << "----------------------------------\n";
   for (int index = 0; index < num; index++)
   {
      cout << productArray[index].id << "\t\t$";
      cout << setw(8) << productArray[index].sales << endl;
   }
   cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(productStruct productArray[], int num)
{
   int totalUnits = 0;
   double totalSales = 0.0;

   for (int index = 0; index < num; index++)
   {
      totalUnits += productArray[index].units;
      totalSales += productArray[index].sales;
   }
   cout << "Total units Sold:  " << totalUnits << endl;
   cout << "Total sales:      $" << totalSales << endl;
}