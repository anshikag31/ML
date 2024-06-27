#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3];
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

void playerMove(char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = player;
            break;
        } else {
            cout << "This move is not valid. Try again.\n";
        }
    }
}

void computerMove() {
    int row, col;
    srand(time(0));
    while (true) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == EMPTY) {
            board[row][col] = PLAYER_O;
            break;
        }
    }
}

void playGame(bool againstComputer) {
    char currentPlayer = PLAYER_X;
    initializeBoard();
    printBoard();
    while (true) {
        if (currentPlayer == PLAYER_X) {
            playerMove(currentPlayer);
        } else if (againstComputer) {
            computerMove();
        } else {
            playerMove(currentPlayer);
        }
        printBoard();
        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isBoardFull()) {
            cout << "The game is a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}

int main() {
    int choice;
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "1. Play against another player\n";
    cout << "2. Play against the computer\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        playGame(false);
    } else if (choice == 2) {
        playGame(true);
    } else {
        cout << "Invalid choice. Exiting.\n";
    }
    return 0;
}
