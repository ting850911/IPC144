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
  int num;
  char newLine = '0';
  do
  {
    scanf("%d%c", &num, &newLine);
    if (newLine != '\n')
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
  } while (newLine != '\n');
  return num;
}

int inputIntPositive(void)
{
  int num;
  char newLine = '0';
  do
  {
    scanf("%d%c", &num, &newLine);
    if (newLine != '\n')
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
    else if (num <= 0)
    {
      printf("ERROR! Value must be > 0: ");
    }
  } while (newLine != '\n' || num <= 0);
  return num;
}

int inputIntRange(int lower, int upper)
{
  int num;
  char newLine = '0';

  do
  {
    scanf("%d%c", &num, &newLine);
    if (newLine != '\n')
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
    else if (num < lower || num > upper)
    {
      printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
    }
  } while (newLine != '\n' || num < lower || num > upper);
  return num;
}

char inputCharOption(const char matches[])
{
  char input;
  int isValid = 0, i;

  do
  {
    scanf("%c", &input);

    for (i = 0; matches[i] != '\0'; i++)
    {
      if (input == matches[i])
      {
        isValid = 1;
      }
    }

    if (!isValid)
    {
      clearInputBuffer();
      printf("ERROR: Character must be one of [%s]: ", matches);
    }

  } while (!isValid);

  return input;
}

void inputCString(char *str, int minSize, int maxSize)
{
  int size;

  do
  {
    scanf(" %[^\n]", str);
    clearInputBuffer();

    size = 0;
    while (str[size] != '\0')
    {
      size++;
    }

    if (size < minSize || size > maxSize)
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
  } while (size < minSize || size > maxSize);
}

void displayFormattedPhone(const char *phoneStr)
{
  const int PHONE_LENGTH = 10;
  int i, length = 0, isValid = 1;

  if (phoneStr == NULL)
  {
    printf("(___)___-____");
  }
  else
  {
    for (i = 0; phoneStr[i] != '\0'; i++)
    {
      if (i >= PHONE_LENGTH || phoneStr[i] < '0' || phoneStr[i] > '9')
      {
        isValid = 0;
      }
      length++;
    }

    if (length != PHONE_LENGTH)
    {
      isValid = 0;
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
}
