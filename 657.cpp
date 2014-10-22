#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstdio>

using namespace std;

bool DEBUG = false;

bool legal(int i, int j, int r, int c) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
  int r,c; 
  int tc = 1;
  while(cin >> c >> r >>ws && r && c) {
    vector<string> matrix;
    string line;
    for(int i= 0;i < r; i++) {
      getline(cin, line);
      matrix.push_back(line);
    }
    int color[r][c];
    int nextColor = 0;
    memset(color, -1, sizeof color);
    for(int i= 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
	if(color[i][j] == -1 && matrix[i][j] != '.') {
	  stack<pair<int, int> > s;
	  color[i][j] = nextColor;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1, y, r, c) && color[x-1][y] == -1 && matrix[x-1][y] != '.') {
	      color[x-1][y] = nextColor;

	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x, y-1, r, c) && color[x][y-1] == -1 && matrix[x][y-1] != '.') {
	      color[x][y-1] = nextColor;
	  
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && color[x][y+1] == -1 && matrix[x][y+1] != '.') {
	      color[x][y+1] = nextColor;

	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y, r, c) && color[x+1][y] == -1 && matrix[x+1][y] != '.') {
	      color[x+1][y] = nextColor;

	      s.push(make_pair(x+1, y));
	    }
	  }
	  nextColor++;
	}
      }
    }
    int number[nextColor];
    memset(number, 0, sizeof number);
    int numberMat[r][c];
    memset(numberMat, -1, sizeof numberMat);
    for(int i= 0; i < r; i++) {
      for(int j= 0; j < c; j++) {
	if(numberMat[i][j] == -1 && matrix[i][j] == 'X') {
	  numberMat[i][j] = 0;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1, y, r, c) && numberMat[x-1][y] == -1 && matrix[x-1][y] == 'X') {
	      numberMat[x-1][y] = 0;

	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x, y-1, r, c) && numberMat[x][y-1] == -1 && matrix[x][y-1] == 'X') {
	      numberMat[x][y-1] = 0;

	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && numberMat[x][y+1] == -1 && matrix[x][y+1] == 'X') {
	      numberMat[x][y+1] = 0;

	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y, r, c) && numberMat[x+1][y] == -1 && matrix[x+1][y] == 'X') {
	      numberMat[x+1][y] = 0;

	      s.push(make_pair(x+1, y));
	    }
	  }
	  number[color[i][j]]++;
	}
      }
    }
    if(DEBUG) {
      cout << "printing color: " << endl; 
      for(int i= 0; i < r; i++) {
	for(int j= 0; j < c; j++) {
	  cout << color[i][j];
	}
	cout << endl;
      }
      cout << "printing numberMat: " << endl;
      for(int i= 0; i < r; i++) {
	for(int j= 0; j < c; j++) {
	  cout << numberMat[i][j];
	}
	cout << endl;
      }
    }
    vector<int> sorted(number, number + nextColor);
    sort(sorted.begin(), sorted.end());
    printf("Throw %d\n", tc++);
    for(int i = 0; i < sorted.size(); i++) {
      if(i != sorted.size() - 1) {
	cout << sorted[i] << " ";
      }
      else {
	cout << sorted[i] << endl;
      }
    }
    cout << endl;
  }
  return 0;
}
