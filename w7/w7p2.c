/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

struct BoardInfo
{
    char symbol;
    char board[MAX_LENGTH];
};

int main(void)
{
    struct PlayerInfo player = {};
    struct GameInfo game = {};
    struct BoardInfo board = {};
    int i, j, playerPosition;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    printf("Set the number of lives: ");
    scanf("%d", &player.lives);
    while (player.lives < 1 || player.lives > 10)
    {
        printf("     Must be between 1 and 10!\n");
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
    }

    for (i = 0; i < MAX_LENGTH; i++)
    {
        player.pastPositions[i] = 0;
    }
    printf("Player configuration set-up is complete\n\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &game.pathLength);
    while (game.pathLength > MAX_LENGTH || game.pathLength < 10 || game.pathLength % 5 != 0)
    {
        printf("     Must be a multiple of 5 and between 10-70!!!\n");
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
    }

    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.moves);
    while (game.moves < 3 || game.moves > game.pathLength * 0.75f)
    {
        printf("    Value must be between 3 and %.f\n", game.pathLength * 0.75f);
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
    }

    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (i = 0; i < game.pathLength / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.bombArr[i * 5 + j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
    for (i = 0; i < game.pathLength / 5; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);

        for (j = 0; j < 5; j++)
        {
            scanf("%d", &game.treasureArr[i * 5 + j]);
        }
    }
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombArr[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasureArr[i]);
    }
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    for (i = 1; i <= game.pathLength; i++)
    {
        printf("-");
        board[i] = '-';
        if (i == game.pathLength)
        {
            printf("\n");
        }
    }
    for (i = 1; i <= game.pathLength; i++)
    {
        i % 10 == 0 ? printf("%d", i / 10) : printf("|");
    }
    for (i = 1; i <= game.pathLength; i++)
    {
        i == 1 ? printf("\n") : printf("%d", i % 10);
    }
    printf("\n+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures, game.moves);
    printf("+---------------------------------------------------+\n");

    while (player.lives > 0 && game.moves > 0)
    {

        do
        {
            printf("Next Move [1-20]: ");
            scanf("%d", &playerPosition);
            if (playerPosition < 1 || playerPosition > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            else
            {
                if (player.pastPositions[playerPosition] != 1)
                {
                    player.pastPositions[playerPosition] = 1;
                    if (game.bombArr[playerPosition - 1] && game.treasureArr[playerPosition - 1])
                    {
                        player.lives--;
                        player.treasures++;
                        board.symbol = '&';
                        printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
                        printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                    }
                    else if (game.bombArr[playerPosition - 1])
                    {
                        player.lives--;
                        board.symbol = '!';
                        printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                    }
                    else if (game.treasureArr[playerPosition - 1])
                    {
                        player.treasures++;
                        board.symbol = '$';
                        printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    }
                    else
                    {
                        board.symbol = '.';
                        printf("\n===============> [.] ...Nothing found here... [.]\n");
                    }
                    printf("\n  ");
                    for (i = 1; i <= game.pathLength; i++)
                    {
                        playerPosition == i ? printf("%c", 'V') : printf(" ");
                        if (i == game.pathLength)
                        {
                            printf("\n");
                        }
                    }
                    printf("  ");
                    for (i = 1; i <= game.pathLength; i++)
                    {
                        if (playerPosition == i)
                        {
                            board[playerPosition] = board.symbol;
                            printf("%c", board.symbol);
                        }
                        if (i == game.pathLength)
                        {
                            printf("\n");
                        }
                    }
                    printf("  ");
                    for (i = 1; i <= game.pathLength; i++)
                    {
                        i % 10 == 0 ? printf("%d", i / 10) : printf("|");
                    }
                    for (i = 1; i <= game.pathLength; i++)
                    {
                        i == 1 ? printf("\n") : printf("%d", i % 10);
                    }
                    game.moves--;
                }
                else
                {
                    printf("  Dope! You've been here before!\n");
                }
                printf("\n+---------------------------------------------------+\n");
                printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasures, game.moves);
                printf("+---------------------------------------------------+\n");
            }
        } while (playerPosition < 0 || playerPosition > game.pathLength + 1);
    }
    printf("\n##################\n");
    printf("# Game over! #\n");
    printf("##################\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}