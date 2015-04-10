#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#define MAXN 25

using namespace std;

// @begin_lib
// @end_lib

class BichromePainting {
public:
  string isThatPossible(vector <string> board, int k) {
    int n = board.size();
    while(true) {
      bool paint = false;
      for(int i = 0; i + k - 1 < board.size(); i++) {
	for(int j = 0; j + k - 1 < board.size(); j++) {
	  bool should_paint = false;
	  char ch = '?';
	  for(int ii = i; ii < i+k; ii++) {
	    for(int jj = j; jj < j+k; jj++) {
	      if(board[ii][jj] != '?') {
		if(ch == '?') {
		  should_paint = true;
		  ch = board[ii][jj];
		} else {
		  if(ch != board[ii][jj]) {
		    should_paint = false;
		  }
		}
	      }
	    }
	  }
	  if(should_paint) {
	    for(int ii = i; ii < i + k; ii++) {
	      for(int jj = j; jj < j + k; jj++) {
		board[ii][jj] = '?';
	      }
	    }
	    paint = true;
	    break;
	  }
	}
	if(paint)
	  break;
      }
      if(!paint)
	break;
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	if(board[i][j] == 'B')
	  return "Impossible";
      }
    }
    
    return "Possible";
  }
};

// @begin_tests
void _run_test(vector< string > board, int k, string res_expected, int test_no) {
string tc_res = (new BichromePainting)->isThatPossible(board, k);
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
int k;
string res_expected;
{string tmpa[] = {"BBBW", "BWWW", "BWWW", "WWWW"};
board.assign(tmpa, tmpa + 4);}
k = 3;
res_expected = "Possible";
_run_test(board, k, res_expected, 0);
{string tmpa[] = {"BW", "WB"};
board.assign(tmpa, tmpa + 2);}
k = 2;
res_expected = "Impossible";
_run_test(board, k, res_expected, 1);
{string tmpa[] = {"BWBWBB", "WBWBBB", "BWBWBB", "WBWBBB", "BBBBBB", "BBBBBB"};
board.assign(tmpa, tmpa + 6);}
k = 2;
res_expected = "Possible";
_run_test(board, k, res_expected, 2);
{string tmpa[] = {"BWBWBB", "WBWBWB", "BWBWBB", "WBWBWB", "BWBWBB", "BBBBBB"};
board.assign(tmpa, tmpa + 6);}
k = 2;
res_expected = "Impossible";
_run_test(board, k, res_expected, 3);
{string tmpa[] = {"BWBWBB", "WBWBWB", "BWBWBB", "WBWBWB", "BWBWBB", "BBBBBB"};
board.assign(tmpa, tmpa + 6);}
k = 1;
res_expected = "Possible";
_run_test(board, k, res_expected, 4);
{string tmpa[] = {"BB", "BB"};
board.assign(tmpa, tmpa + 2);}
k = 2;
res_expected = "Possible";
_run_test(board, k, res_expected, 5);
}
// @end_tests

// Born in Emacs
