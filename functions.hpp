void welcome();
std::vector<std::string> make_board();
std::vector<std::string> print_board(std::vector<std::string> board, char turn);
bool win(std::vector<std::string> board);
std::vector<std::string> make_move(std::vector<std::string> board, char turn);
char switch_turn(char turn);