#include "TicTacToe.h"

// 0 is uninitialized, 1 is X's and 2 is O's
int main(void)
{
    printf("Hello World!\n\n");
    GameMode currentMode = PVC;
    int mode = 0;
    select_mode(&mode);
    switch(mode)
    {
        case 1:
            printf("Player versus computer mode!\n");
            currentMode = PVC;
            break;
        case 2:
            printf("Player versus player mode!\n");
            currentMode = PVP;
            break;
        default:
            printf("ERROR!");
            break;
    }
    srand(time(NULL));
    int randNum = 0; // might change back
    int compRow, compCol = 0;
    int row, col = 0;
    int gameBoard[ROWS][COLS];
    bool gameState = P1_TURN;
    int rounds = 0;

    // first we want to initialize the board
    initializeBoardArray(gameBoard, ROWS, COLS);
    // prints an empty gameboard
    printBoard(gameBoard, ROWS, COLS);

    // ensures that position is an invalid spot from the beginning
    int position = -1;

    // create a turn based system to switch between player one and two
    // make it so that when a player/computer chooses a position it updates the empty array with an x/o
    while (1)
    {
        if (gameState == P1_TURN)
        {
            player_one_turn(&position, &row, &col);
            while (!updateBoardArray(gameBoard, row, col, 1, gameState))
            {
                printf("Invalid spot!");
                player_one_turn(&position, &row, &col);
            }
            rounds++;
            win_condition(gameBoard, row, col, gameState);
            gameState = P2_TURN;
        } else if (gameState == P2_TURN && currentMode == PVC)
        {
            computer_turn(&randNum, &compRow, &compCol);
            while (!updateBoardArray(gameBoard, compRow, compCol, 2, gameState))
            {
                computer_turn(&randNum, &compRow, &compCol);
            }
            rounds++;
            win_condition(gameBoard, compRow, compCol, gameState);
            gameState = P1_TURN;
        } else if (gameState == P2_TURN && currentMode == PVP)
        {
            player_two_turn(&position, &row, &col);
            while (!updateBoardArray(gameBoard, row, col, 2, gameState))
            {
                printf("Invalid spot!");
                player_two_turn(&position, &row, &col);
            }
            rounds++;
            win_condition(gameBoard, row, col, gameState);
            gameState = P1_TURN;
        } else if (currentMode == ERROR)
        {
            exit(EXIT_SUCCESS);
        }
        // after updating the array, update the game board to reflect the array
        printBoard(gameBoard, ROWS, COLS);
        printf("%d\n", rounds);
    }
    return 0;
}
