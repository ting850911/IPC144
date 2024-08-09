/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MAX_ITEMS 10
int isFinancingOption(char financed);

#include <stdio.h>

int main(void)
{
    int i, priority[MAX_ITEMS], count, selection, filter;
    const double minIncome = 500, maxIncome = 400000, minCost = 100;
    char financed[MAX_ITEMS];
    double income, sum, cost[MAX_ITEMS];

    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);

        if (income < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", minIncome);
        }
        else if (income > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", maxIncome);
        }
    } while (income < minIncome || income > maxIncome);

    do
    {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &count);

        if (count < 1 || count > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
        }
    } while (count < 1 || count > MAX_ITEMS);

    for (i = 0; i < count; i++)
    {
        printf("\nItem-%d Details:\n", i + 1);

        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < minCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
            }
        } while (cost[i] < minCost);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financed[i]);

            if (financed[i] != 'y' && financed[i] != 'n')
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (financed[i] != 'y' && financed[i] != 'n');
    }

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < count; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", sum);

    do
    {
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 0:
            break;
        case 1:
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", sum);
            printf("Forecast: %d years, %d months\n", (int)(sum / income) / 12, (int)(sum / income) % 12 + 1);
            printf("NOTE: Financing options are available on some items.\n"
                   "      You can likely reduce the estimated months.\n");
            printf("====================================================\n");
            break;
        case 2:
            do
            {
                printf("\nWhat priority do you want to filter by? [1-3]: ");
                scanf("%d", &filter);

                if (filter < 1 || filter > 3)
                {
                    printf("ERROR: Value must be between 1 and 3\n");
                }
            } while (filter < 1 || filter > 3);

            sum = 0;
            for (i = 0; i < count; i++)
            {
                if (priority[i] == filter)
                {
                    sum += cost[i];
                }
            }

            printf("\n====================================================\n");
            printf("Filter:   by priority (%d)\n", filter);
            printf("Amount:   $%1.2lf\n", sum);
            printf("Forecast: %d years, %d months\n", (int)(sum / income) / 12, (int)(sum / income) % 12 + 1);
            if (isFinancingOption(financed[filter - 1]))
            {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
            break;

        default:
            printf("\nERROR: Invalid menu selection.\n");
            break;
        }

    } while (selection > 0);

    printf("\nBest of luck in all your future endeavours!\n");

    return 0;
}

int isFinancingOption(char financed)
{
    return financed == 'n' ? 1 : 0;
}