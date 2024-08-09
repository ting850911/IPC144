/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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
#include <string.h>
#include "core.h"

void clearInputBuffer(void)
{
  // Discard all remaining char's from the standard input buffer:
  while (getchar() != '\n')
  {
    ; // do nothing!
  }
}

void suspend(void)
{
  printf("<ENTER> to continue...");
  clearInputBuffer();
  putchar('\n');
}

int inputInt(void)
{
  int num, isValid = 0;
  char newLine = '0';
  do
  {
    scanf("%d%c", &num, &newLine);
    if (newLine == '\n')
    {
      isValid = 1;
    }
    else
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
  } while (!isValid);
  return num;
}

int inputIntPositive(void)
{
  int num, isValid = 0;
  char newLine = '0';
  do
  {
    scanf("%d%c", &num, &newLine);
    if (newLine == '\n')
    {
      if (num > 0)
      {
        isValid = 1;
      }
      else
      {
        printf("ERROR! Value must be > 0: ");
      }
    }
    else
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
  } while (!isValid);
  return num;
}

int inputIntRange(int lowerBound, int upperBound)
{
  int value, isValid = 0;

  do
  {
    value = inputInt();
    if (value < lowerBound || value > upperBound)
    {
      printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
    }
    else
    {
      isValid = 1;
    }
  } while (!isValid);
  return value;
}

char inputCharOption(const char matches[])
{
  char input;
  int isValid = 0;

  do
  {
    scanf("%c", &input);
    clearInputBuffer();

    if (strchr(matches, input) != NULL)
    {
      isValid = 1;
    }

    if (!isValid)
    {
      printf("ERROR: Character must be one of [%s]: ", matches);
    }

  } while (!isValid);

  return input;
}

void inputCString(char *str, int minSize, int maxSize)
{
  int size, isValid = 0;

  do
  {
    scanf(" %[^\n]", str);
    clearInputBuffer();

    size = strlen(str);

    if (size >= minSize && size <= maxSize)
    {
      isValid = 1;
    }
    else
    {
      if (minSize == maxSize)
      {
        printf("ERROR: String length must be exactly %d chars: ", minSize);
      }
      else if (size > maxSize)
      {
        printf("ERROR: String length must be no more than %d chars: ", maxSize);
      }
      else
      {
        printf("ERROR: String length must be between %d and %d chars: ", minSize, maxSize);
      }
    }
  } while (!isValid);
}

void displayFormattedPhone(const char *phoneStr)
{
  const int PHONE_LENGTH = 10;
  int isValid = 1, i;

  if (phoneStr == NULL)
  {
    isValid = 0;
  }
  else if (strlen(phoneStr) != PHONE_LENGTH)
  {
    isValid = 0;
  }
  else
  {
    for (i = 0; i < PHONE_LENGTH && isValid; i++)
    {
        if (phoneStr[i] < '0' || phoneStr[i] > '9')
        {
            isValid = 0;
        }
    }
  }

  if (isValid)
  {
    printf("(%c%c%c)%c%c%c-%c%c%c%c",
           phoneStr[0], phoneStr[1], phoneStr[2],
           phoneStr[3], phoneStr[4], phoneStr[5],
           phoneStr[6], phoneStr[7], phoneStr[8], phoneStr[9]);
  }
  else
  {
    printf("(___)___-____");
  }
}
