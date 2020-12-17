#include <iostream>
using namespace std;

bool is_sudoku_solved = 0;

void display_board(char board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_valid_row(int row, int val, char board[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] - '0' == val)
            return 0;
    }
    return 1;
}

bool is_valid_column(int col, int val, char board[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] - '0' == val)
            return 0;
    }
    return 1;
}

bool is_valid_sub_matrix(int row, int col, int val, char board[9][9]) {
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] - '0' == val)
                return 0;
        }
    }

    return 1;
}

bool is_valid(int x, int y, int val, char board[9][9]) {
    return (is_valid_row(x, val, board) and is_valid_column(y, val, board) and is_valid_sub_matrix(x, y, val, board));
}


bool fill_sudoku(char board[9][9], int r, int c) {
    bool is_complete = 1;

    if (r ==8 and c > 8)
        return 1;
    
    if (c > 8)
        r++, c=0;

    if (board[r][c] == ' ') {
        is_complete = 0;
        for (int num = 1; num <= 9; num++) {
            if (is_valid(r, c, num, board)) {
                board[r][c] = (char) '0' + num;
                if (fill_sudoku(board, r, c+1))
                    return 1;
                board[r][c] = ' ';
            }
        }
    }
    else {
        return fill_sudoku(board, r, c+1);
    }

    return 0;
}

int main() {
    char board[9][9] = {
    {'5', '3', ' ', ' ', '7', ' ', ' ', ' ', ' '},
    {'6', ' ', ' ', '1', '9', '5', ' ', ' ', ' '},
    {' ', '9', '8', ' ', ' ', ' ', ' ', '6', ' '},
    {'8', ' ', ' ', ' ', '6', ' ', ' ', ' ', '3'},
    {'4', ' ', ' ', '8', ' ', '3', ' ', ' ', '1'},
    {'7', ' ', ' ', ' ', '2', ' ', ' ', ' ', '6'},
    {' ', '6', ' ', ' ', ' ', ' ', '2', '8', ' '},
    {' ', ' ', ' ', '4', '1', '9', ' ', ' ', '5'},
    {' ', ' ', ' ', ' ', '8', ' ', ' ', '7', '9'},
};
    fill_sudoku(board, 0, 0);
    display_board(board);
}
