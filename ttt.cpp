#include <iostream>
#include <string>
#include <vector>
#include "functions.hpp"

int main() {
  welcome();

  char turn = 'R'; // Red or Blue 

  std::vector<std::string> board = make_board();

  while(not win(board)) {
    print_board(board, turn);
    board = make_move(board, turn);
    turn = switch_turn(turn);
  }
  
  if (turn == 'R') {
    std::cout << "The Blue wins!\n";
  } else {
    std::cout << "The Red wins!\n";
  }
}