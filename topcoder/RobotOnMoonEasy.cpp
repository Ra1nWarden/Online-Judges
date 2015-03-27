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

typedef pair<int, int> ii;

class RobotOnMoonEasy {
public:
  string isSafeCommand(vector <string> board, string S) {
    ii pos;
    bool found = false;
    for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[i].length(); j++) {
	if(board[i][j] == 'S') {
	  pos.first = i;
	  pos.second = j;
	  found = true;
	  break;
	}
      }
      if(found)
	break;
    }
    bool dead = false;
    for(int i = 0; i < S.length(); i++) {
      if(S[i] == 'U') {
	if(pos.first - 1 < 0) {
	  dead = true;
	  break;
	}
	else if(board[pos.first-1][pos.second] == '.') {
	  pos.first = pos.first - 1;
	}
      }
      if(S[i] == 'D') {
	if(pos.first + 1 >= board.size()) {
	  dead = true;
	  break;
	}
	else if(board[pos.first+1][pos.second] == '.') {
	  pos.first = pos.first + 1;
	}
      }
      if(S[i] == 'L') {
	if(pos.second - 1 < 0) {
	  dead = true;
	  break;
	}
	else if(board[pos.first][pos.second-1] == '.') {
	  pos.second = pos.second - 1;
	}
      }
      if(S[i] == 'R') {
	if(pos.second + 1 >= board[pos.first].length()) {
	  dead = true;
	  break;
	}
	else if(board[pos.first][pos.second+1] == '.') {
	  pos.second = pos.second + 1;
	}
      }
    }
    return dead ? "Dead" : "Alive";
  }
};

// @begin_tests
void _run_test(vector< string > board, string S, string res_expected, int test_no) {
string tc_res = (new RobotOnMoonEasy)->isSafeCommand(board, S);
if (tc_res == res_expected)
cout << "--- test " << test_no << ": ok ---" << endl;
else {
cout << "--- test " << test_no << ": failed ---" << endl;
cout << "expected: ";
cout << '"' << res_expected << '"';
cout << endl << "got: ";
cout << '"' << tc_res << '"';
cout << endl;
}
}
int main() {
vector< string > board;
string S;
string res_expected;
{string tmpa[] = {".....", ".###.", "..S#.", "...#."};
board.assign(tmpa, tmpa + 4);}
S = "URURURURUR";
res_expected = "Alive";
_run_test(board, S, res_expected, 0);
{string tmpa[] = {".....", ".###.", "..S..", "...#."};
board.assign(tmpa, tmpa + 4);}
S = "URURURURUR";
res_expected = "Dead";
_run_test(board, S, res_expected, 1);
{string tmpa[] = {".....", ".###.", "..S..", "...#."};
board.assign(tmpa, tmpa + 4);}
S = "URURU";
res_expected = "Alive";
_run_test(board, S, res_expected, 2);
{string tmpa[] = {"#####", "#...#", "#.S.#", "#...#", "#####"};
board.assign(tmpa, tmpa + 5);}
S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
res_expected = "Alive";
_run_test(board, S, res_expected, 3);
{string tmpa[] = {"#####", "#...#", "#.S.#", "#...#", "#.###"};
board.assign(tmpa, tmpa + 5);}
S = "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD";
res_expected = "Dead";
_run_test(board, S, res_expected, 4);
{string tmpa[] = {"S"};
board.assign(tmpa, tmpa + 1);}
S = "R";
res_expected = "Dead";
_run_test(board, S, res_expected, 5);
}
// @end_tests

// Born in Emacs
