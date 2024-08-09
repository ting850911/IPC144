/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Nina Wang
Student ID#: 148817232
Email      : ytwang4@myseneca.ca
Section    : NAA

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double getSubTotal(float shortPrice, int shortNum);
void formatCurrency(float value);
double addTax(float shortPrice, int shortNum);
double getTotal(float shortPrice, int shortNum);
const double TAX = 0.13;

int main(void)
{
  const char patSize = 'S';
  const char tomSize = 'L';
  const char salSize = 'M';
  float smallShirtPrice, midShirtPrice, largeShirtPrice, allSubTotal, allTax, allTotal;
  int pNumShirts, tNumShirts, sNumShirts, totalShirts;

  printf("Set Shirt Prices\n================\n");
  printf("Enter the price for a SMALL shirt: $");
  scanf("%f", &smallShirtPrice);
  printf("Enter the price for a MEDIUM shirt: $");
  scanf("%f", &midShirtPrice);
  printf("Enter the price for a LARGE shirt: $");
  scanf("%f", &largeShirtPrice);

  printf("\nShirt Store Price List\n======================\n");
  printf("SMALL  : $%.2f\n", smallShirtPrice);
  printf("MEDIUM : $%.2f\n", midShirtPrice);
  printf("LARGE  : $%.2f\n\n", largeShirtPrice);

  printf("Patty's shirt size is '%c'\n", patSize);
  printf("Number of shirts Patty is buying: ");
  scanf("%d", &pNumShirts);

  printf("\nTommy's shirt size is '%c'\n", tomSize);
  printf("Number of shirts Tommy is buying: ");
  scanf("%d", &tNumShirts);

  printf("\nSally's shirt size is '%c'\n", salSize);
  printf("Number of shirts Sally is buying: ");
  scanf("%d", &sNumShirts);

  totalShirts = pNumShirts + tNumShirts + sNumShirts;
  printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
  printf("-------- ---- ----- --- --------- --------- ---------\n");

  printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirtPrice, pNumShirts, getSubTotal(smallShirtPrice, pNumShirts), addTax(smallShirtPrice, pNumShirts), getTotal(smallShirtPrice, pNumShirts));
  printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, midShirtPrice, sNumShirts, getSubTotal(midShirtPrice, sNumShirts), addTax(midShirtPrice, sNumShirts), getTotal(midShirtPrice, sNumShirts));
  printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirtPrice, tNumShirts, getSubTotal(largeShirtPrice, tNumShirts), addTax(largeShirtPrice, tNumShirts), getTotal(largeShirtPrice, tNumShirts));

  printf("-------- ---- ----- --- --------- --------- ---------\n");
  allSubTotal = getSubTotal(smallShirtPrice, pNumShirts) + getSubTotal(midShirtPrice, sNumShirts) + getSubTotal(largeShirtPrice, tNumShirts);
  allTax = addTax(smallShirtPrice, pNumShirts) + addTax(midShirtPrice, sNumShirts) + addTax(largeShirtPrice, tNumShirts);
  allTotal = getTotal(smallShirtPrice, pNumShirts) + getTotal(midShirtPrice, sNumShirts) + getTotal(largeShirtPrice, tNumShirts);
  printf("%33.4lf %9.4lf %9.4lf\n\n", allSubTotal, allTax, allTotal);

  printf("Daily retail sales represented by coins\n");
  printf("=======================================\n\n");

  printf("Sales EXCLUDING tax\n");
  printf("Coin     Qty   Balance\n");
  printf("-------- --- ---------\n");
  printf("%22.4lf\n", allSubTotal);
  formatCurrency(allSubTotal);

  printf("\nAverage cost/shirt: $%.4lf\n", allSubTotal / totalShirts);

  printf("\nSales INCLUDING tax\n");
  printf("Coin     Qty   Balance\n");
  printf("-------- --- ---------\n");
  printf("%22.4lf\n", allTotal);
  formatCurrency(allTotal);
  printf("\nAverage cost/shirt: $%.4lf\n", allTotal / totalShirts);

  return 0;
}

double getSubTotal(float shortPrice, int shortNum)
{
  double subTotal;
  subTotal = (int)((shortPrice * shortNum) * 100 + 0.5);
  return subTotal / 100;
};
double addTax(float shortPrice, int shortNum)
{
  double addTax;
  addTax = (int)(((getSubTotal(shortPrice, shortNum) * TAX) + 0.005) * 100);
  return addTax / 100;
};
double getTotal(float shortPrice, int shortNum)
{
  double total;
  total = ((getSubTotal(shortPrice, shortNum) + addTax(shortPrice, shortNum)));
  return total;
};

void formatCurrency(float value)
{
  int toonies, loonies, quarters, dimes, nickels, pennies;
  float rest;

  // Calculate the number of toonies and the remaining value
  toonies = (int)(value / 2);
  rest = value - toonies * 2;
  printf("Toonies  %3d %9.4lf\n", toonies, rest);

  // Calculate the number of loonies and the remaining value
  loonies = (int)(rest / 1);
  rest = rest - loonies * 1;
  printf("Loonies  %3d %9.4lf\n", loonies, rest);

  // Calculate the number of quarters and the remaining value
  quarters = (int)(rest / 0.25);
  rest = rest - quarters * 0.25;
  printf("Quarters  %2d %9.4lf\n", quarters, rest);

  // Calculate the number of dimes and the remaining value
  dimes = (int)(rest / 0.10);
  rest = rest - dimes * 0.10;
  printf("Dimes  %5d %9.4lf\n", dimes, rest);

  // Calculate the number of nickels and the remaining value
  nickels = (int)(rest / 0.05);
  rest = rest - nickels * 0.05;
  printf("Nickels  %3d %9.4lf\n", nickels, rest);

  // Calculate the number of pennies and the remaining value
  pennies = (int)(rest / 0.01);
  rest = rest - pennies * 0.01;
  printf("Pennies  %3d %9.4lf\n", pennies, rest);
}

// Daily retail sales represented by coins
// ========================================
//
// Sales EXCLUDING tax
// Coin Qty Balance
// -------- --- ---------
//               323.5100
// Toonies 161 1.5100
// Loonies    1 0.5100
// Quarters   2 0.0100
// Dimes      0 0.0100
// Nickels     0 0.0100
// Pennies    1 0.0000

// Average cost/shirt: $24.8854

// Sales INCLUDING tax
// Coin Qty Balance
// -------- --- ---------
//               365.5700
// Toonies 182 1.5700
// Loonies     1 0.5700
// Quarters    2 0.0700
// Dimes       0 0.0700
// Nickels      1 0.0200
// Pennies     2 0.0000

// Average cost/shirt: $28.1208