#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char currentPlayer;

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void switchPlayer()
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}

void playerTurn()
{
    int row, col;
    printf("Your turn! Enter your move (row and column): ");
    scanf("%d %d", &row, &col);

    if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ')
    {
        board[row - 1][col - 1] = currentPlayer;
    }
    else
    {
        printf("Invalid move. Try again.\n");
        playerTurn();
    }
}

void botTurn()
{
    int row, col;
    printf("Bot's turn...\n");
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = currentPlayer;
    printf("Bot placed at %d %d\n", row + 1, col + 1);
}

int main()
{
    srand(time(0));
    initializeBoard();
    printf("Welcome to Tic Tac Toe! You are 'X'. Bot is 'O'.\n");

    while (1)
    {
        printBoard();

        if (currentPlayer == 'X')
        {
            playerTurn();
        }
        else
        {
            botTurn();
        }

        if (checkWin())
        {
            printBoard();
            if (currentPlayer == 'X')
                printf("Congratulations! You win!\n");
            else
                printf("Bot wins! Better luck next time.\n");
            break;
        }
        if (isDraw())
        {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        switchPlayer();
    }
    return 0;
}
