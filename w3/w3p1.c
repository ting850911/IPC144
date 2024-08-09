/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (Pro1)
Full Name  : Nina Wang
Student ID#: 148817232
Email      : ytwang4@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    const double testValue = 330.99;
    int pro1Id, pro2Id, pro3Id;
    float pro1Price, pro2Price, pro3Price;
    char pro1Taxed, pro2Taxed, pro3Taxed;

    printf("Product Information\n===================\n");
    printf("Product-1 (ID:%d)\n", pro1Id = 111);
    printf("  Taxed: %c\n", pro1Taxed = 'Y');
    printf("  Price: $%.4f\n\n", pro1Price = 111.49);

    printf("Product-2 (ID:%d)\n", pro2Id = 222);
    printf("  Taxed: %c\n", pro2Taxed = 'N');
    printf("  Price: $%.4f\n\n", pro2Price = 222.99);

    printf("Product-3 (ID:%d)\n", pro3Id = 111);
    printf("  Taxed: %c\n", pro3Taxed = 'N');
    printf("  Price: $%.4f\n\n", pro3Price = 334.49);

    printf("The average of all prices is: $%.4f\n", (pro1Price + pro2Price + pro3Price) / 3);

    printf("\nAbout Relational and Logical Expressions!\n========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", pro1Taxed == 'Y');

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", pro2Taxed == 'N' && pro3Taxed == 'N');

    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n\n", testValue, pro3Price < testValue);

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", pro3Price > pro1Price + pro2Price);

    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n", pro1Price >= pro3Price - pro2Price, pro3Price - pro2Price);

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", pro2Price >= (pro1Price + pro2Price + pro3Price) / 3);

    printf("7. Based on product ID, product 1 is unique -> %d\n\n", pro1Id != pro2Id && pro1Id != pro3Id);

    printf("8. Based on product ID, product 2 is unique -> %d\n\n", pro2Id != pro1Id && pro2Id != pro3Id);

    printf("9. Based on product ID, product 3 is unique -> %d\n\n", pro3Id != pro1Id && pro3Id != pro2Id);

    return 0;
}