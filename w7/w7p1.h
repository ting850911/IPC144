#include <stdio.h>
#define MAX_LENGTH 70

struct PlayerInfo
{
    int lives;
    char symbol;
    int treasures;
    int pastPositions[MAX_LENGTH];
};

struct GameInfo
{
    int moves;
    int pathLength;
    int bombArr[MAX_LENGTH];
    int treasureArr[MAX_LENGTH];
};

void setBoard(struct GameInfo *game, int isBomb);
void getBoard(int pathLength, int arr[]);

void setBoard(struct GameInfo *game, int isBomb)
{
    int i, j;
    for (i = 0; i < (*game).pathLength / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        for (j = 0; j < 5; j++)
        {
            isBomb ? scanf("%d", &(*game).bombArr[i * 5 + j]) : scanf("%d", &(*game).treasureArr[i * 5 + j]);
        }
    }
};

void getBoard(int pathLength, int arr[])
{
    int i;
    for (i = 0; i < pathLength; i++)
    {
        printf("%d", arr[i]);
    }
};