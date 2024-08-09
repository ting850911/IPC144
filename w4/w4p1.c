/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int checkRange(int num);
void printChar(char loopType, int num);

int main(void)
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    int num;
    char loopType;
    do
    {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &num);

        switch (loopType)
        {
        case 'D':
            if (checkRange(num))
            {

                printf("DO-WHILE: ");
                printChar(loopType, num);
            }
            break;
        case 'W':
            if (checkRange(num))
            {
                printf("WHILE   : ");
                printChar(loopType, num);
            }

            break;
        case 'F':
            if (checkRange(num))
            {
                printf("FOR     : ");
                printChar(loopType, num);
            }
            break;
        case 'Q':
            if (num != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            else
            {
                printf("\n+--------------------+");
                printf("\nLoop application ENDED");
                printf("\n+--------------------+\n");
                return 0;
            }
            break;
        default:
            printf("ERROR: Invalid entered value(s)!\n");
            break;
        }

    } while (1);

    return 0;
}

int checkRange(int num)
{
    if (num < 3 || num > 20)
    {
        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void printChar(char loopType, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%c", loopType);
    }
    printf("\n");
}