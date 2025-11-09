#include <iostream>
using namespace std;

int N;
bool solutionFound = false;

bool isSafe(int board[20][20], int row, int col) {
    int i, j;

    // Check column
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

void printBoard(int board[20][20]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] == 1 ? 'Q' : '.') << " ";
        cout << endl;
    }
    cout << endl;
}

void solveNQueen(int board[20][20], int row) {
    if (row >= N) {
        printBoard(board);
        solutionFound = true;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueen(board, row + 1);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board : ";
    cin >> n;
    N = n;

    int board[20][20] = {0};
    int r, c;
    cout << "\nRow and Col for 1st queen : ";
    cin >> r >> c;

    board[r][c] = 1;
    solveNQueen(board, r + 1);

    if (!solutionFound)
        cout << "No solution exists for this placement." << endl;

    return 0;
}
