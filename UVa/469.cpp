#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <sstream>
#include <cstring>

using namespace std;

bool DEBUG = false;

bool legal(int i, int j, int r, int c) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
  int cases;
  cin >> cases >> ws;
  while(cases--) {
    string line;
    vector<string> matrix;
    while(true) {
      getline(cin, line);
      if(line[0] != 'L' && line[0] != 'W')
	break;
      matrix.push_back(line);
    }
    int r = matrix.size();
    int c = matrix[0].length();
    int color[r][c];
    memset(color, -1, sizeof color);
    int colorCount[r*c];
    memset(colorCount, 0, sizeof colorCount);
    int nextColor = 0;
    for(int i= 0; i < r; i++) {
      for(int j= 0; j < c; j++) {
	if(matrix[i][j] == 'W' && color[i][j] == -1) {
	  color[i][j] = nextColor;
	  colorCount[nextColor]++;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1, y-1, r, c) && color[x-1][y-1] == -1 && matrix[x-1][y-1] == 'W') {
	      color[x-1][y-1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x-1, y-1));
	    }
	    if(legal(x-1, y, r, c) && color[x-1][y] == -1 && matrix[x-1][y] == 'W') {
	      color[x-1][y] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x-1, y+1, r, c) && color[x-1][y+1] == -1 && matrix[x-1][y+1] == 'W') {
	      color[x-1][y+1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x-1, y+1));
	    }
	    if(legal(x, y-1, r, c) && color[x][y-1] == -1 && matrix[x][y-1] == 'W') {
	      color[x][y-1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && color[x][y+1] == -1 && matrix[x][y+1] == 'W') {
	      color[x][y+1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y-1, r, c) && color[x+1][y-1] == -1 && matrix[x+1][y-1] == 'W') {
	      color[x+1][y-1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x+1, y-1));
	    }
	    if(legal(x+1, y, r, c) && color[x+1][y] == -1 && matrix[x+1][y] == 'W') {
	      color[x+1][y] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x+1, y));
	    }
	    if(legal(x+1, y+1, r, c) && color[x+1][y+1] == -1 && matrix[x+1][y+1] == 'W') {
	      color[x+1][y+1] = nextColor;
	      colorCount[nextColor]++;
	      s.push(make_pair(x+1, y+1));
	    }
	  }
	  nextColor++;
	}
      }
    }
    if(DEBUG) {
      cout << "printing matrix" << endl;
      for(int i= 0; i < matrix.size(); i++)
	cout << matrix[i] << endl;
      cout << endl;
      cout << "printing colored matrix: " << endl;
      for(int i= 0; i < r; i++) {
	for(int j = 0; j < c; j++) {
	  cout << color[i][j] << " ";
	}
	cout << endl;
      }
    }

    while(true) {
      istringstream iss(line.c_str());
      int qx, qy;
      iss >> qx >> qy;
      if(legal(qx-1, qy-1, r, c) && matrix[qx-1][qy-1] == 'W')
	cout << colorCount[color[qx-1][qy-1]] << endl;
      else
	cout << 0 << endl;
      if(!getline(cin, line) || line.empty())
	break;
    }
    if(cases)
      cout << endl;
  }
  return 0;
}
