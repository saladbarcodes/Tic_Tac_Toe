#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define P1_TURN true
#define P2_TURN false

int getRow(int position)
{
    if (position > 9 || position < 0)
        return -1;
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
    scanf("%d", position);
    while (*position > 9 || *position < 0)
    {
        printf("What position would you like P1?");
        scanf("%d", position);
    }
    // printf("%d", position); // debug
    *row = getRow(*position);
    // printf("row %d", row); // debug
    *col = getCol(*position);
    // printf("col %d", col); // debug
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

int updateBoardArray(int (*gameBoard)[COLS], int row, int col, int newVal)
{
    if (gameBoard[row][col] == 1 || gameBoard[row][col] == 2)
        return 0;
    gameBoard[row][col] = newVal;
    // win_condition(gameBoard, row, col);
    return 1;
}

bool win_condition(int (*gameBoard)[COLS], int row, int col)
{   
    if (row == 2 || col == 2) // if the row or col is 2 dont bother checking diagonals
    {
        
    }
    return true;
}

// 0 is uninitialized, 1 is X's and 2 is O's
int main(void)
{
    printf("Hello World!\n\n");
    srand(time(NULL));
    int randNum = (rand() % 9) + 1;
    int compRow = 0;
    int compCol = 0;
    int row, col = 0;
    int gameBoard[ROWS][COLS];
    bool gameState = P1_TURN;
    int rounds = 0;
    // first we want to initialize the board
    initializeBoardArray(gameBoard, ROWS, COLS);
    
    printBoard(gameBoard, ROWS, COLS);

    // create an empty array to hold the possible positions of the game board
    int position = -1;

    // create a turn based system to switch between player one and two
    // make it so that when a player/computer chooses a position it updates the empty array with an x/o
    while (1)
    {
        if (gameState == P1_TURN)
        {
            player_one_turn(&position, &row, &col);
            while (!updateBoardArray(gameBoard, row, col, 1))
            {
                printf("Invalid spot!");
                player_one_turn(&position, &row, &col);
            }
            gameState = P2_TURN;
            rounds++;
        } else if (gameState == P2_TURN)
        {
            randNum = rand() % 9;
            compRow = getRow(randNum);
            compCol = getCol(randNum);
            updateBoardArray(gameBoard, compRow, compCol, 2);
            gameState = P1_TURN;
            rounds++;
        }
        // after updating the array, update the game board to reflect the array
        printBoard(gameBoard, ROWS, COLS);
    }

    // 123
    // 456
    // 789
    return 0;
}
