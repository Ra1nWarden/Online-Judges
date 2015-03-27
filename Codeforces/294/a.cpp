#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int v[100];

int main() {
  memset(v, 0, sizeof v);
  v['q' - 'a'] = 9;
  v['r' - 'a'] = 5;
  v['b' - 'a'] = 3;
  v['n' - 'a'] = 3;
  v['p' - 'a'] = 1;
  string line;
  vector<string> board;
  while(getline(cin, line))
    board.push_back(line);
  int white = 0;
  int black = 0;
  for(int i = 0; i < board.size(); i++) {
    for(int j= 0; j < board[i].length(); j++) {
      if(board[i][j] != '.') {
	if(board[i][j] >= 'a' && board[i][j] <= 'z') {
	  black += v[board[i][j] - 'a'];
	}
	if(board[i][j] >= 'A' && board[i][j] <= 'Z') {
	  white += v[board[i][j] - 'A'];
	}
      }
    }
  }
  if(black > white)
    cout << "Black" << endl;
  else if(black < white)
    cout << "White" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
