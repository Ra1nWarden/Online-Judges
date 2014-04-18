#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkWin(vector<vector<int> >& board, int test) {
  // test: 1 = X         -1 = O
  bool found = false;
  for(int i = 0; i < 3; i++) {
    if (board[i][0] == test && board[i][1] == test && board[i][2] == test) {
      found = true;
      break;
    }
  }
  if (found)
    return true;
  for(int i = 0; i < 3; i++) {
    if (board[0][i] == test && board[1][i] == test && board[2][i] == test) {
      found = true;
      break;
    }
  }
  if (found)
    return true;
  if (board[0][0] == test && board[1][1] == test && board[2][2] == test)
    return true;
  if (board[0][2] == test && board[1][1] == test && board[2][0] == test)
    return true;
  return found;
}

bool validCheck(vector<vector<int> >& board) {
  int xCount = 0;
  int oCount = 0;
  for(int i = 0 ;i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(board[i][j] == 1)
	xCount++;
      else if (board[i][j] == -1)
	oCount++;
    }
  }
  if (xCount - oCount == 1 || xCount - oCount == 0) {
    bool xWin = checkWin(board, 1);
    bool oWin = checkWin(board, -1);
    if (xWin && oWin)
      return false;
    else if (xWin)
      return (xCount != oCount);
    else if (oWin)
      return (xCount - oCount != 1);
    else
      return true;
  }
  else
    return false;
}

int main() {
  int cases;
  cin >> cases >> ws;
  for(int i = 0; i < cases; i++) {
    string line;
    if(i != 0)
      getline(cin, line);
    vector<vector<int> > board;
    for(int j = 0; j < 3; j++) {
      getline(cin, line);
      vector<int> row;
      for(int k = 0; k < 3; k++) {
	if(line[k] == 'X')
	  row.push_back(1);
	else if (line[k] == '.')
	  row.push_back(0);
	else if (line[k] == 'O')
	  row.push_back(-1);
      }
      board.push_back(row);
    }
    if(validCheck(board))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
