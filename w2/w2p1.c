/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    float smallShirt, midShirt, largeShirt, subTotal, taxes, total;
    int numShirts;

    printf("Set Shirt Prices\n================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &midShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &largeShirt);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2f\n", smallShirt);
    printf("MEDIUM : $%.2f\n", midShirt);
    printf("LARGE  : $%.2f\n\n", largeShirt);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirts);

    subTotal = (smallShirt * numShirts) * 100;
    taxes = (int)((subTotal * TAX) + 0.5);
    total = (subTotal + taxes);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numShirts);
    printf("Sub-total: $%8.4lf\n", subTotal / 100);
    printf("Taxes    : $%8.4lf\n", taxes / 100);
    printf("Total    : $%8.4lf\n", total / 100);

    return 0;
}
