#include <iostream>
#include <stack>
#include <utility>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

bool legal(int i, int j, int r, int c) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
  int r, c;
  while(cin >> r >> c >> ws && r && c) {
    vector<string> matrix;
    for(int i= 0; i < r; i++) {
      string line;
      getline(cin, line);
      matrix.push_back(line);
    }
    int nextColor = 0;
    int color[r][c];
    memset(color, -1, sizeof color);
    for(int i= 0; i < r; i++) {
      for(int j= 0; j < c; j++) {
	if(matrix[i][j] == '@' && color[i][j] == -1) {
	  color[i][j] = nextColor;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	     if(legal(x-1, y-1, r, c) && color[x-1][y-1] == -1 && matrix[x-1][y-1] == '@') {
	      color[x-1][y-1] = nextColor;
        
	      s.push(make_pair(x-1, y-1));
	    }
	    if(legal(x-1, y, r, c) && color[x-1][y] == -1 && matrix[x-1][y] == '@') {
	      color[x-1][y] = nextColor;

	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x-1, y+1, r, c) && color[x-1][y+1] == -1 && matrix[x-1][y+1] == '@') {
	      color[x-1][y+1] = nextColor;

	      s.push(make_pair(x-1, y+1));
	    }
	    if(legal(x, y-1, r, c) && color[x][y-1] == -1 && matrix[x][y-1] == '@') {
	      color[x][y-1] = nextColor;
	  
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && color[x][y+1] == -1 && matrix[x][y+1] == '@') {
	      color[x][y+1] = nextColor;

	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y-1, r, c) && color[x+1][y-1] == -1 && matrix[x+1][y-1] == '@') {
	      color[x+1][y-1] = nextColor;
	 
	      s.push(make_pair(x+1, y-1));
	    }
	    if(legal(x+1, y, r, c) && color[x+1][y] == -1 && matrix[x+1][y] == '@') {
	      color[x+1][y] = nextColor;

	      s.push(make_pair(x+1, y));
	    }
	    if(legal(x+1, y+1, r, c) && color[x+1][y+1] == -1 && matrix[x+1][y+1] == '@') {
	      color[x+1][y+1] = nextColor;

	      s.push(make_pair(x+1, y+1));
	    }
	  }
	  nextColor++;
	}
      }
    }
    cout << nextColor << endl;
  }
  return 0;
}
