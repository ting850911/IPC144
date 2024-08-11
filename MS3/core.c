/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <ctype.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
  // Discard all remaining char's from the standard input buffer:
  while (getchar() != '\n')
  {
    ; // do nothing!
  }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
  printf("<ENTER> to continue...");
  clearInputBuffer();
  putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

int inputInt(void)
{
  int value, isValid = 0;
  char newLine = 'x';
  do
  {
    scanf("%d%c", &value, &newLine);
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
  return value;
}

int inputIntPositive(void)
{
  int num, isValid = 0;
  do
  {
    num = inputInt();
    if (num > 0)
    {
      isValid = 1;
    }
    else
    {
      printf("ERROR! Value must be > 0: ");
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

char inputCharOption(const char validChar[])
{
  char input[3];
  int valid = 0;

  do
  {
    scanf(" %2[^\n]", input);
    clearInputBuffer();

    if (strlen(input) == 1 && strchr(validChar, input[0]) != NULL)
    {
      valid = 1;
    }
    else
    {
      printf("ERROR: Character must be one of [%s]: ", validChar);
    }
  } while (!valid);

  return input[0];
}

void inputCString(char *str, int minSize, int maxSize)
{
  int isValid = 0;
  char input[maxSize + 1]; // Create a local variable array with maxSize + 1 size

  do
  {
    scanf(" %[^\n]", input);
    clearInputBuffer();

    int size = strlen(input);

    if (size >= minSize && size <= maxSize)
    {
      isValid = 1;
      strncpy(str, input, maxSize);
      str[maxSize] = '\0';
    }
    else
    {
      if (minSize == maxSize)
      {
        printf("Invalid %d-digit number! Number: ", minSize);
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

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

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
      if (!isdigit(phoneStr[i]))
      {
        isValid = 0;
      }
    }
  }

  if (isValid)
  {
    printf("(%.*s)%.*s-%.*s",
           3, phoneStr,
           3, phoneStr + 3,
           4, phoneStr + 6);
  }
  else
  {
    printf("(___)___-____");
  }
}