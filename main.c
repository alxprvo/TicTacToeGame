#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define NUM_OF_POSITION 9

void DrawBoard(const char* boardPosition);
int GetAndValidateNumber(const char* boardPosition, bool player1Turn);
bool CheckForWin(const char* boardPosition);
bool CheckForDraw(const char* boardPosition);


int main() {

    bool player1Turn = true; //true = player 1 turn, false = player 2 turn.

    char boardPosition[NUM_OF_POSITION] = {
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'

    };

    // Always true, if there is a winner or a draw we break out of the loop and the game end.
    while(true) {
        int chosenSquare;
        DrawBoard(boardPosition);

        chosenSquare = GetAndValidateNumber(boardPosition, player1Turn);

        if(player1Turn) {
            boardPosition[chosenSquare] = 'X';
        } else {
            boardPosition[chosenSquare] = 'O';
        }

        if (CheckForWin(boardPosition)) {
            DrawBoard(boardPosition);
            printf("\n\nPLAYER %i WON!!\n\n", player1Turn ? 1 : 2);
            break; // Game ends with a winner.
        } else if (CheckForDraw(boardPosition)) {
            DrawBoard(boardPosition);
            printf("\n\nIT'S A DRAW!\n\n");
            break; // Game ends with a draw
        }

        //Change player turn
        player1Turn = !player1Turn;

    }

    system("pause");
    return 0;
}

/*********************************
 * Clear the screen and draw the board with the right values.
*********************************/
void DrawBoard(const char* boardPosition){
    system("cls");

    printf("\n\n\tTic Tac Toe");
    printf("\n\nPlayer 1 (X)  -  Player 2 (O)");
    printf("\n\n\n     |     |     ");
    printf("\n  %c  |  %c  |  %c  ", boardPosition[0], boardPosition[1], boardPosition[2]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n  %c  |  %c  |  %c  ", boardPosition[3], boardPosition[4], boardPosition[5]);
    printf("\n_____|_____|_____");
    printf("\n     |     |     ");
    printf("\n  %c  |  %c  |  %c  ", boardPosition[6], boardPosition[7], boardPosition[8]);
    printf("\n     |     |     ");

}

/*********************************
 * Ask the player to enter de desired square.
 * Check if the square is valid.
 * Ask for a new square if the choice is invalid
 * Returns the square chosen if it is valid.
*********************************/
int GetAndValidateNumber(const char* boardPosition, bool player1Turn) {
    int chosenSquare;
    bool numberIsValid = false;

    do {
        printf("\n\nPlayer %i, enter a number: ", player1Turn ? 1 : 2);
        chosenSquare = getch() - '0' - 1;

        if (chosenSquare >= 0 && chosenSquare < 9 && boardPosition[chosenSquare] != 'X' && boardPosition[chosenSquare] != 'O') {
            numberIsValid = true;
        } else {
            printf("\nInvalid Choice. Square %i is either not between 1 and 9 or already taken.", chosenSquare + 1);
        }
    } while (!numberIsValid);

    return chosenSquare;
}

/*********************************
 * Check for a Win.
 * Returns true if there are 3 X or O in line.
 * Return false otherwise.
*********************************/
bool CheckForWin(const char* boardPosition) {
    //Checking rows
    if ((boardPosition[0] == boardPosition[1] && boardPosition[1] == boardPosition[2]) ||
        (boardPosition[3] == boardPosition[4] && boardPosition[4] == boardPosition[5]) ||
        (boardPosition[6] == boardPosition[7] && boardPosition[7] == boardPosition[8])) {

        return true;
    }

    // Checking Columns
    if ((boardPosition[0] == boardPosition[3] && boardPosition[3] == boardPosition[6]) ||
        (boardPosition[1] == boardPosition[4] && boardPosition[4] == boardPosition[7]) ||
        (boardPosition[2] == boardPosition[5] && boardPosition[5] == boardPosition[8])) {

        return true;
    }

    //Checking diagonals
    if ((boardPosition[0] == boardPosition[4] && boardPosition[4] == boardPosition[8]) ||
        (boardPosition[2] == boardPosition[4] && boardPosition[4] == boardPosition[6])) {

        return true;
    }

    return false;
}

/*********************************
 * Check if every square have an X or a O.
 * Return true if yes.
 * Return false if not.
*********************************/
bool CheckForDraw(const char* boardPosition) {
    int i;
    int numberOfPositionPlayed = 0;
    for (i = 0; i < NUM_OF_POSITION; i++) {
        if (boardPosition[i] == 'X' || boardPosition[i] == 'O') {
            numberOfPositionPlayed++;
        }
    }

    if (numberOfPositionPlayed >= NUM_OF_POSITION) {
        return true;
    } else {
        return false;
    }
}
