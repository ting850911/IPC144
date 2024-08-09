/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int isLight(char coffeeType);
int isMedium(char coffeeType);
int isRich(char coffeeType);
const double GRAMS_IN_LBS = 453.5924;
double convertToLbs(int bagWeight);
int isWithCream(char cream);
void getCustPref(char *customerStrength, char *customerCream, int *customerServings);
int compareType(char coffeeType, char customerStrength);
int compareWeight(int coffeeWight, int customerServings);
int compareCream(char cream, char customerCream);

int main(void)
{
    char coffeeType1, coffeeType2, coffeeType3, cream1, cream2, cream3, customerStrength, customerCream;
    int bagWeight1, bagWeight2, bagWeight3, customerServings;

    printf("Take a Break - Coffee Shop\n==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", isLight(coffeeType1), isMedium(coffeeType1), isRich(coffeeType1), bagWeight1, convertToLbs(bagWeight1), isWithCream(cream1));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", isLight(coffeeType2), isMedium(coffeeType2), isRich(coffeeType2), bagWeight2, convertToLbs(bagWeight2), isWithCream(cream2));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", isLight(coffeeType3), isMedium(coffeeType3), isRich(coffeeType3), bagWeight3, convertToLbs(bagWeight3), isWithCream(cream3));

    getCustPref(&customerStrength, &customerCream, &customerServings);

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", compareType(coffeeType1, customerStrength), compareWeight(bagWeight1, customerServings), compareCream(cream1, customerCream));
    printf(" 2|       %d         |      %d      |   %d   |\n", compareType(coffeeType2, customerStrength), compareWeight(bagWeight2, customerServings), compareCream(cream2, customerCream));
    printf(" 3|       %d         |      %d      |   %d   |\n", compareType(coffeeType3, customerStrength), compareWeight(bagWeight3, customerServings), compareCream(cream3, customerCream));

    getCustPref(&customerStrength, &customerCream, &customerServings);

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", compareType(coffeeType1, customerStrength), compareWeight(bagWeight1, customerServings), compareCream(cream1, customerCream));
    printf(" 2|       %d         |      %d      |   %d   |\n", compareType(coffeeType2, customerStrength), compareWeight(bagWeight2, customerServings), compareCream(cream2, customerCream));
    printf(" 3|       %d         |      %d      |   %d   |\n", compareType(coffeeType3, customerStrength), compareWeight(bagWeight3, customerServings), compareCream(cream3, customerCream));
    printf("\nHope you found a product that suits your likes!\n");

    return 0;
}

int isLight(char coffeeType)
{
    return coffeeType == 'l' || coffeeType == 'L';
}
int isMedium(char coffeeType)
{
    return coffeeType == 'm' || coffeeType == 'M';
}
int isRich(char coffeeType)
{
    return coffeeType == 'r' || coffeeType == 'R';
}
double convertToLbs(int bagWeight)
{
    return bagWeight / GRAMS_IN_LBS;
}
int isWithCream(char cream)
{
    int withCream = 0;
    if (cream == 'y' || cream == 'Y')
    {
        withCream = 1;
    }
    return withCream;
}
void getCustPref(char *customerStrength, char *customerCream, int *customerServings)
{
    printf("\nEnter how you like your coffee...\n");
    printf("\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", customerStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", customerCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", customerServings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
}
int compareType(char coffeeType, char customerStrength)
{
    return (isLight(coffeeType) && isLight(customerStrength)) ||
           (isMedium(coffeeType) && isMedium(customerStrength)) ||
           (isRich(coffeeType) && isRich(customerStrength));
}
int compareWeight(int coffeeWight, int customerServings)
{
    return (coffeeWight == 250 && (1 <= customerServings && customerServings < 5)) ||
           (coffeeWight == 500 && (5 <= customerServings && customerServings < 10)) ||
           (coffeeWight == 1000 && customerServings >= 10);
}
int compareCream(char cream, char customerCream)
{
    return isWithCream(cream) == isWithCream(customerCream);
}