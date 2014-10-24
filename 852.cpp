#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

char board[9][9];
bool visited[9][9];

bool legal(int i, int j) {
  return i >= 0 && i < 9 && j >= 0 && j < 9;
}

int main() {
  int tc;
  cin >> tc >> ws;
  while(tc--) {
    string line;
    int black = 0;
    int white = 0;
    for(int i= 0; i < 9; i++) {
      getline(cin, line);
      for(int j= 0; j < 9; j++) {
	board[i][j] = line[j];
	if(line[j] == 'O')
	  white++;
	else if(line[j] == 'X')
	  black++;
      }
    }
    memset(visited, false, sizeof visited);
    for(int i= 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
	if(board[i][j] == '.' && !visited[i][j]) {
	  int count = 0;
	  char color = '.';
	  visited[i][j] = true;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    count++;
	    int x = next.first;
	    int y = next.second;
	    if(legal(x, y-1) && !visited[x][y-1]) {
	      if(board[x][y-1] == '.') {
		visited[x][y-1] = true;
		s.push(make_pair(x, y-1));
	      } else {
		if(color == '.')
		  color = board[x][y-1];
		else if (color != -1) {
		  color = board[x][y-1] == color ? color : -1;
		}
	      }
	    }
	    if(legal(x, y+1) && !visited[x][y+1]) {
	      if(board[x][y+1] == '.') {
		visited[x][y+1] = true;
		s.push(make_pair(x, y+1));
	      } else {
		if(color == '.')
		  color = board[x][y+1];
		else if (color != -1) {
		  color = board[x][y+1] == color ? color : -1;
		}
	      }
	    }
	    if(legal(x-1, y) && !visited[x-1][y]) {
	      if(board[x-1][y] == '.') {
		visited[x-1][y] = true;
		s.push(make_pair(x-1, y));
	      } else {
		if(color == '.')
		  color = board[x-1][y];
		else if (color != -1) {
		  color = board[x-1][y] == color ? color : -1;
		}
	      }
	    }
	    if(legal(x+1, y) && !visited[x+1][y]) {
	      if(board[x+1][y] == '.') {
		visited[x+1][y] = true;
		s.push(make_pair(x+1, y));
	      } else {
		if(color == '.')
		  color = board[x+1][y];
		else if (color != -1) {
		  color = board[x+1][y] == color ? color : -1;
		}
	      }
	    }
	  }
	  if(color == 'O')
	    white += count;
	  else if (color == 'X')
	    black += count;
	}
      }
    }
    printf("Black %d White %d\n", black, white);
  }
}
