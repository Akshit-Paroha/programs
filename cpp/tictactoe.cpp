#include <iostream>
using namespace std;

// Function to display the board
void displayBoard(char board[3][3])
{
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player)
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        { // Columns
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    { // Diagonal
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false; // There's still an empty space
            }
        }
    }
    return true; // No empty spaces left
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;

    while (true)
    {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check for valid input
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
        {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win or draw
        if (checkWin(board, currentPlayer))
        {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
