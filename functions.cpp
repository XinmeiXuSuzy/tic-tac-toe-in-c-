#include <iostream>
#include <vector>
#include <string>

void welcome() {
  std::cout << "Welcome to Tic-Tac-Toe!\n"
            << "Game start:\n";
}

std::vector<std::string> make_board() {
    std::string vert = " | | ";
    std::string hori = "- - - ";
    std::vector<std::string> board;
    board.push_back(vert);
    board.push_back(hori);
    board.push_back(vert);
    board.push_back(hori);
    board.push_back(vert);
    return board;
}

void print_board(std::vector<std::string> board, char turn) {
    for (int i = 0; i < board.size(); i++) {
        std::cout << board[i] << "\n";
    }
    if (turn == 'R') {
        std::cout << "It is Red's turn!\n";
    } else {
        std::cout << "It is Blue's turn!\n";
    }
}

bool win(std::vector<std::string> board) {
    //check horizontally by line 
    for (int i = 0; i < 3; i++) {
        std::string line = board[i * 2];
        char first = line[0];
        char second = line[2];
        char third = line[4];
        if (first != ' ' && first == second && second == third) {
            return true; 
        }
    }
    //check vertically by line 
    for (int i = 0; i < 3; i++) {
        std::string line = std::string(1,board[0][i * 2]) + board[2][i * 2] + board[4][i * 2];
        if (line[0] != ' ' && line[0] == line[1] && line[1] == line[2]) {
            return true;
        }
    }
    //first diagonal 
    if (board[0][0] != ' ' && board[0][0] == board[2][2] && board[2][2] == board[4][4]) {
        return true;
    }
    //second diagonal 
    if (board[0][4] != ' ' && board[0][4] == board[2][2] && board[2][2] == board[4][0]) {
        return true;
    }
    return false;
}

std::vector<std::string> make_move(std::vector<std::string> board, char turn) {
    std::cout << "Please choose a move by inputting row and col position: \n";
    int row, col;
    std::cout << "Row position: ";
    std::cin >> row;
    std::cout << "Column position: ";
    std::cin >> col;
    row = (row-1) * 2;
    col = (col-1) * 2;
    switch (turn) {
        case 'R': 
            board[row][col] = 'o';
            break;
        case 'B':
            board[row][col] = 'x';
            break;
        default:
            break;
    }
    return board; 
}

char switch_turn(char turn) {
    if (turn == 'R') {
        return 'B';
    } else {
        return 'R';
    }
}