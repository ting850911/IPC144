/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Nina Wang
Student ID#: 148817232
Email      : ytwang4@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int checkRange(int num);
char *toLowerCase(char *string);
char *strcat(char *destination, const char *source);

int main(void)
{
    int apples, oranges, pears, tomatoes, cabbages, portion, i, shopping;
    char fruits[5][8] = {"APPLE", "ORANGE", "PEAR", "TOMATO", "CABBAGE"};
    do
    {
        printf("Grocery Shopping\n================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
        } while (checkRange(apples));
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);

        } while (checkRange(oranges));
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
        } while (checkRange(pears));
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes);
        } while (checkRange(tomatoes));
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
        } while (checkRange(cabbages));
        printf("\n");

        printf("--------------------------\nTime to pick the products!\n--------------------------\n\n");

        for (i = 0; i < 5; i++)
        {

            while (apples > 0 && i == 0)
            {
                do
                {
                    printf("Pick some %sS... how many did you pick? : ", fruits[i]);
                    scanf("%d", &portion);
                    if (portion < 1)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else if (portion > apples)
                    {
                        printf("You picked too many... only %d more %s(S) are needed.\n", apples, fruits[i]);
                    }
                    else
                    {
                        apples -= portion;
                        if (apples == 0)
                        {
                            printf("Great, that's the %ss done!\n\n", toLowerCase(fruits[i]));
                            i++;
                            break;
                        }
                        else
                        {
                            printf("Looks like we still need some %sS...\n", fruits[i]);
                        }
                    }
                } while (1);
            }

            while (oranges > 0 && i == 1)
            {
                do
                {
                    printf("Pick some %sS... how many did you pick? : ", fruits[i]);
                    scanf("%d", &portion);
                    if (portion < 1)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else if (portion > oranges)
                    {
                        printf("You picked too many... only %d more %s(S) are needed.\n", oranges, fruits[i]);
                    }
                    else
                    {
                        oranges -= portion;
                        if (oranges == 0)
                        {
                            printf("Great, that's the %ss done!\n\n", toLowerCase(fruits[i]));
                            i++;
                            break;
                        }
                        else
                        {
                            printf("Looks like we still need some %sS...\n", fruits[i]);
                        }
                    }
                } while (1);
            }

            while (pears > 0 && i == 2)
            {
                do
                {
                    printf("Pick some %sS... how many did you pick? : ", fruits[i]);
                    scanf("%d", &portion);
                    if (portion < 1)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else if (portion > pears)
                    {
                        printf("You picked too many... only %d more %s(S) are needed.\n", pears, fruits[i]);
                    }
                    else
                    {
                        pears -= portion;
                        if (pears == 0)
                        {
                            printf("Great, that's the %ss done!\n\n", toLowerCase(fruits[i]));
                            i++;
                            break;
                        }
                        else
                        {
                            printf("Looks like we still need some %sS...\n", fruits[i]);
                        }
                    }
                } while (1);
            }

            while (tomatoes > 0 && i == 3)
            {
                do
                {
                    printf("Pick some %sES... how many did you pick? : ", fruits[i]);
                    scanf("%d", &portion);
                    if (portion < 1)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else if (portion > tomatoes)
                    {
                        printf("You picked too many... only %d more %s(ES) are needed.\n", tomatoes, fruits[i]);
                    }
                    else
                    {
                        tomatoes -= portion;
                        if (tomatoes == 0)
                        {
                            printf("Great, that's the %ses done!\n\n", toLowerCase(fruits[i]));
                            i++;
                            break;
                        }
                        else
                        {
                            printf("Looks like we still need some %sES...\n", fruits[i]);
                        }
                    }
                } while (1);
            }

            while (cabbages > 0 && i == 4)
            {
                do
                {
                    printf("Pick some %sS... how many did you pick? : ", fruits[i]);
                    scanf("%d", &portion);

                    if (portion < 1)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else if (portion > cabbages)
                    {
                        printf("You picked too many... only %d more %s(S) are needed.\n", cabbages, fruits[i]);
                    }
                    else
                    {
                        cabbages -= portion;
                        if (cabbages == 0)
                        {
                            printf("Great, that's the %ss done!\n\n", toLowerCase(fruits[i]));
                            i++;
                            break;
                        }
                        else
                        {
                            printf("Looks like we still need some %sS...\n", fruits[i]);
                        }
                    }
                } while (1);
            }
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopping);
        printf("\n");

    } while (shopping == 1);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}

int checkRange(int num)
{
    if (num < 0)
    {
        printf("ERROR: Value must be 0 or more.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}
char *toLowerCase(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
    }
    return string;
}