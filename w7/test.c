#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
  int userMoves;
  do
  {
    printf("Next Move [1-20]: ");
    scanf("%d", &userMoves);
    if (userMoves < 0 || userMoves > 21)
    {
      printf("  Out of Range!!!\n");
    }
  } while (userMoves < 0 || userMoves > 21);

  return 0;
}
