#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define P1_TURN true
#define P2_TURN false

typedef enum
{
    PVC, // Player versus Computer
    PVP, // Player versus Player
    ERROR
}GameMode;

void select_mode(int *mode)
{
    // This is what determines what game mode tictactoe is in
    do
    {
        printf("What game mode would you like to be in?\n");
        printf("Player versus computer is 1. Player versus player is 2. ");
        scanf(" %d", mode);
        while (getchar() != '\n');
    } while (*mode < 1 || *mode > 2);
}

int getRow(int position)
{
    // checking bounds
    if (position > 9 || position < 0)
        return -1;
    // This divides by the # of row to get row
    double getRows = (double)position / ROWS;
    // printf("%f", getRows);
    if (getRows > 2)
        return 2;
    if (getRows > 1 && getRows <= 2)
        return 1;
    if (getRows > 0 && getRows <= 1)
        return 0;

    return -1;
}

int getCol(int position)
{
    int col = position;
    if (col % 3 == 0)
    {
        col = 2;
        return col;
    }
    return (col % 3) - 1;
}

void player_one_turn(int *position, int *row, int *col)
{
    printf("What position would you like P1?");
    while (scanf("%d", position) != 1 || *position > 9 || *position < 0)
    {
        printf("What position would you like P1?");
        scanf("%d", position);
        while (getchar() != '\n');
    }
    *row = getRow(*position);
    *col = getCol(*position);
}

// temp fix
void player_two_turn(int *position, int *row, int *col)
{
    printf("What position would you like P2?");
    while (scanf("%d", position) != 1 || *position > 9 || *position < 0)
    {
        printf("What position would you like P2?");
        scanf("%d", position);
        while (getchar() != '\n');
    }
    *row = getRow(*position);
    *col = getCol(*position);
}

void computer_turn(int *randNum, int *compRow, int *compCol)
{
    *randNum = (rand() % 9) + 1;
    *compRow = getRow(*randNum);
    *compCol = getCol(*randNum);
}

void printBoard(int (*gameBoard)[COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("   %d", gameBoard[i][j]);
            if (j < 2)
            {
                printf("\t|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("_________________________");
        }
        printf("\n");
    }
}

void initializeBoardArray(int (*gameBoard)[COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
}

int updateBoardArray(int (*gameBoard)[COLS], int row, int col, int newVal, bool player_turn)
{
    if (gameBoard[row][col] == 1 || gameBoard[row][col] == 2)
        return 0;
    gameBoard[row][col] = newVal;
    return 1;
}

bool check_cross(int (*gameBoard)[COLS], int row, int col, bool player_turn)
{
    int player = player_turn ? 1 : 2;
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (gameBoard[i][col] == player) count++;
    }
    if (count == 3) return true;
    count = 0;
    for (int j = 0; j < COLS; j++)
    {
        if (gameBoard[row][j] == player) count++;
    }
    if (count == 3) return true;
    return false;
}

bool check_diags(int (*gameBoard)[COLS], int row, int col, bool player_turn)
{
    int player = player_turn ? 1 : 2;
    int count = 0;
    int currentCol = COLS - 1;
    for (int i = 0; i < ROWS; i++)
    {
        if (gameBoard[i][i] == player) count++;
    }
    if (count == 3) return true;
    count = 0;
    for (int j = 0; j < COLS; j++)
    {
        if (gameBoard[j][currentCol--] == player) count++;
    }
    if (count == 3) return true;
    return false;
}

void displayWinMessage(bool player_turn)
{
    if (player_turn)
    {
        printf("PLAYER 1 WON!!");
        return;
    }
    printf("PLAYER 2 WON!!");
}

void is_won(int (*gameBoard)[COLS], bool CHECK_WIN, bool player_turn)
{
    if (CHECK_WIN) 
    {
        printBoard(gameBoard, ROWS, COLS);
        displayWinMessage(player_turn);
        exit(EXIT_SUCCESS);
    }
}

void win_condition(int (*gameBoard)[COLS], int row, int col, bool player_turn)
{   
    bool CHECK_WIN = false;
    CHECK_WIN = check_cross(gameBoard, row, col, player_turn) || check_diags(gameBoard, row, col, player_turn);
    if (CHECK_WIN) is_won(gameBoard, CHECK_WIN, player_turn);
    return;
}