#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<string>& board)  {
  for(int i = 0; i < board.size(); i++)
    cout << board[i] << endl;
}

class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool square[9][9];
    bool solve(vector<string>& board) {
      cout << "row[2][6] is " << row[2][6] << endl;
      cout << "col[7][6] is " << col[7][6] << endl;
      cout << "square[2][6] is " << square[2][6] << endl;
      cout << "solving step: " << endl;
      printBoard(board);
      cout << endl;
        int nexti = -1;
        int nextj = -1;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    nexti = i;
                    nextj = j;
                    break;
                }
            }
            if(nexti != -1 && nextj != -1)
                break;
        }
        if(nexti == -1 && nextj == -1)
            return true;
        int sn = nexti / 3 * 3 + nextj / 3;
        for(int i = 8; i >= 0; i--) {
            if(!(row[nexti][i] || col[nextj][i] || square[sn][i])) {
	      cout << "trying " << (char) ('1' + i) << " at " << nexti << ", " << nextj << endl;
	      row[nexti][i] = true;
	      col[nextj][i] = true;
	      square[sn][i] = true;
		char copy = board[nexti][nextj];
                board[nexti][nextj] = '1' + i;
                if(solve(board)) {
                    return true;
                } else {
		  row[nexti][i] = false;
		  col[nextj][i] = false;
		  square[sn][i] = false;
		  cout << "resetting " << nexti << ", " << nextj << " to " << copy << endl;
		    board[nexti][nextj] = copy;
		    printBoard(board);
		    cout << "i is " << i << endl;
                }
            } else {
	      if(row[nexti][i])
		cout << i << " at " << nexti << endl;
	      if(col[nextj][i])
		cout << i << " at " << nextj << endl;
	      if(square[sn][i])
		cout << i << " at square " << sn << endl;
	    }
        }
	cout << "returning false for " << nexti << " and " << nextj << endl;
	printBoard(board);
        return false;
    }
public:
    void solveSudoku(vector<string> &board) {
        memset(row, false, sizeof row);
        memset(col, false, sizeof col);
        memset(square, false, sizeof square);
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
	      if(board[i][j] == '.')
		continue;
                int num = board[i][j] - '1';
                int sn = i / 3 * 3 + j / 3;
                row[i][num] = true;
                col[j][num] = true;
                square[sn][num] = true;
            }
        }
        solve(board);
	cout << "here at solveSudoku" << endl;
    }
};

int main() {
  vector<string> board;
  board.push_back("..9748...");
  board.push_back("7........");
  board.push_back(".2.1.9...");
  board.push_back("..7...24.");
  board.push_back(".64.1.59.");
  board.push_back(".98...3..");
  board.push_back("...8.3.2.");
  board.push_back("........6");
  board.push_back("...2759..");
  Solution sol;
  sol.solveSudoku(board);
  printBoard(board);
  return 0;
}
