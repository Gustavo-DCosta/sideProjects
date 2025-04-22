#include <stdio.h>

int main() {
    int x; // Declare variable for result
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }; // Initialize the board

    // Example move
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';

    // Check if the first row is the same
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') {
        x = 1; // Set x to 1 if there's a win in the first row
    } else {
        x = 0; // Otherwise, set x to 0
    }

    // Print the result
    printf("Result: %d\n", x);

    return 0;
}
