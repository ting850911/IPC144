/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month;
    double morningRating, eveningRating, morningSum, eveningSum, overallSum, morningAvg, eveningAvg;

    printf("General Well-being Log\n======================\n");

    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
    } while ((year < MIN_YEAR || year > MAX_YEAR) || (month < JAN || month > DEC));

    printf("\n*** Log date set! ***\n");

    int i;
    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("\n%d-", year);
        switch (month)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        default:
            break;
        }
        printf("-0%d\n", i + 1);

        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);

            if (morningRating < 0.0 || morningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                morningSum += morningRating;
            }
        } while (morningRating < 0.0 || morningRating > 5.0);

        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);

            if (eveningRating < 0.0 || eveningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else
            {
                eveningSum += eveningRating;
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);
    }

    printf("\nSummary\n=======\n");
    printf("Morning total rating: %6.3lf\n", morningSum);
    printf("Evening total rating: %6.3lf\n", eveningSum);
    printf("----------------------------\n");
    overallSum = morningSum + eveningSum;
    printf("Overall total rating: %6.3lf\n\n", overallSum);
    morningAvg = morningSum / LOG_DAYS;
    printf("Average morning rating: %4.1lf\n", morningAvg);
    eveningAvg = eveningSum / LOG_DAYS;
    printf("Average evening rating: %4.1lf\n", eveningAvg);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningAvg + eveningAvg) / 2);

    return 0;
}