#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

char board[5][12] = {
    "- -|- -|- -",
    "---|---|---",
    "- -|- -|- -",
    "---|---|---",
    "- -|- -|- -",
};
int rows = sizeof(board) / sizeof(board[0]);
int columns = sizeof(board[0]) / sizeof(board[0][0]);
void resetBoard()
{
    char initialBoard[5][12] = {
        "- -|- -|- -",
        "---|---|---",
        "- -|- -|- -",
        "---|---|---",
        "- -|- -|- -",
    };
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = initialBoard[i][j];
        }
    }
}
typedef struct
{
    char input;
    int row, column;

} Player;

Player User, Computer;

void tictactoe(int row, int column, char symbol)
{
    board[row][column] = symbol; // replace the row and column position with the certain symbol when u use the function
}

// print the board
void printboard()
{
    for (int i = 0; i < rows; i++)
    {
        printf("%s\n", board[i]);
    }
}

int FreeSpaces()
{
    int freeSpaces = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (board[i][j] == ' ') // check empty spaces
            {
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

bool checkWin(char symbol)

{
    // Check rows
    for (int i = 0; i < rows; i++) // check rows r0, r2, r4
    {
        if (board[i][1] == symbol && board[i][5] == symbol && board[i][9] == symbol)
        {
            return true;
        }
    }

    // Check columns
    for (int i = 1; i < columns; i++) // check columns c1, c5, c9
    {
        if (board[0][i] == symbol && board[2][i] == symbol && board[4][i] == symbol)
        {
            return true;
        }
    }

    // Check diagonals
    // Left to right diagonal: r0 c1, r2 c5, r4 c9
    if (board[0][1] == symbol && board[2][5] == symbol && board[4][9] == symbol)
    {
        return true;
    }

    // Right to left diagonal: r0 c9, r2 c5, r4 c1
    if (board[0][9] == symbol && board[2][5] == symbol && board[4][1] == symbol)
    {
        return true;
    }

    // No winner found
    return false;
}

void ComputerTurn()
{
    srand(time(0));
    if (FreeSpaces() > 0)
    {
        // list of possible rows and columns values
        int rowValues[3] = {0, 2, 4};
        int ColumnValues[3] = {1, 5, 9};

        // the loop will continue until an empty space found
        do
        {
            int randRowIndex = rand() % 3;    // get a random index for row
            int randColumnIndex = rand() % 3; // get a random index for column

            Computer.row = rowValues[randRowIndex];
            Computer.column = ColumnValues[randColumnIndex];

        } while (board[Computer.row][Computer.column] != ' ');
    }
    tictactoe(Computer.row, Computer.column, Computer.input);
}

void UserTurn()
{

    // adjust to be a right row
    if (User.row == 1)
        User.row = 0;

    if (User.row == 3)
        User.row = 4;

    // adjust to be a right column
    if (User.column == 2)
        User.column = 5;

    if (User.column == 3)
        User.column = 9;

    tictactoe(User.row, User.column, User.input);
}

void TheMainFunction()
{

    Computer.input = 'O';
    User.input = 'X';

    printboard(); // print the empty board
    bool gameover = false;

    while (!gameover)
    {
        if (FreeSpaces() == 0)
        {
            gameover = true;
            break;
        }

        printf("Enter the row: ");
        scanf("%d", &User.row); // input the row between 1 and 3

        if (User.row < 1 || User.row > 3)
        {
            printf("Wrong! argument");
            break;
        } // exit if there is a wrong argument

        printf("Enter the Column: ");
        scanf("%d", &User.column); // input the column between 1 and 3

        if (User.column < 1 || User.column > 3)
        {
            printf("Wrong! argument");
            break;
        } // exit if there is a wrong argument

        UserTurn();
        if (!checkWin(User.input))
            ComputerTurn();

        printboard();

        if (checkWin(User.input))
        {
            printf("Player wins!\n");
            gameover = true;
            break;
        }
        if (checkWin(Computer.input))
        {
            printf("Computer wins!\n");
            gameover = true;
            break;
        }
        if (!checkWin(User.input) && !checkWin(Computer.input) && FreeSpaces() == 0)
        {
            printf("Draw!\n");
            gameover = true;
            break;
        }
    }
}

void clearScreen()
{
    system("cls"); // clear the terminal
}
int main()
{
    printf("Wellcome to X O game\n");
    printf("---------------------------------\n");
    char userInfo = 'Y';

    while (userInfo == 'Y')
    {
        clearScreen();
        resetBoard();
        TheMainFunction();
        printf("Continue? N/Y: ");
        scanf(" %c", &userInfo);

        // Convert to uppercase
        userInfo = toupper(userInfo);
    }
    printf("Bye Bye");
    return 0;
}

// 4 hours in this project :skull emoji:
// good train i guess i learned alot from this project
// you may have some problems if your not in windows