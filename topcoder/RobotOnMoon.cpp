#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// @begin_lib
// @end_lib

class RobotOnMoon {
public:
  int longestSafeCommand(vector <string> board) {
    int x = -1;
    int y = -1;
    for(int i = 0; i < board.size(); i++) {
      for(int j= 0; j < board[i].length(); j++) {
	if(board[i][j] == 'S') {
	  x = i;
	  y = j;
	  break;
	}
      }
      if(x != -1 && y != -1)
	break;
    }

    for(int i = x + 1; i < board.size(); i++)
      if(board[i][y] == '#')
	return -1;
    
    for(int i = x - 1; i > -1; i--)
      if(board[i][y] == '#')
	return -1;

    for(int j = y + 1; j < board[0].length(); j++)
      if(board[x][j] == '#')
	return -1;
    
    for(int j = y - 1; j > -1; j--)
      if(board[x][j] == '#')
	return -1;
    
    return board.size() - 1 +  board[0].length() - 1;
  }
};

// @begin_tests
void _run_test(vector< string > board, int res_expected, int test_no) {
int tc_res = (new RobotOnMoon)->longestSafeCommand(board);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << res_expected;
cout << endl << "got: ";
cout << tc_res;
cout << endl;
}
}
int main() {
vector< string > board;
int res_expected;
{string tmpa[] = {"#####", "#...#", "#.S.#", "#...#", "#####"};
board.assign(tmpa, tmpa + 5);}
res_expected = -1;
_run_test(board, res_expected, 0);
{string tmpa[] = {"S......"};
board.assign(tmpa, tmpa + 1);}
res_expected = 6;
_run_test(board, res_expected, 1);
{string tmpa[] = {"#.######", "#.#..S.#", "#.#.##.#", "#......#", "########"};
board.assign(tmpa, tmpa + 5);}
res_expected = -1;
_run_test(board, res_expected, 2);
{string tmpa[] = {"S"};
board.assign(tmpa, tmpa + 1);}
res_expected = 0;
_run_test(board, res_expected, 3);
}
// @end_tests

// Born in Emacs
