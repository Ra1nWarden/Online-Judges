#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <utility>

using namespace std;

bool legal(int i, int j, int r, int c) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

bool boundary(int i, int j, int r, int c) {
  return i == 0 || i == r-1 || j == 0 || j == c-1;
}

void paint(int x, int y, char letter, vector<string>& matrix) {
  if(letter != -1)
    matrix[x][y] = letter;
}

bool separator(string& line) {
  if(line.length() == 0)
    return false;
  for(int i= 0; i < line.length(); i++) {
    if(line[i] != '_')
      return false;
  }
  return true;
}

int main() {
  int cases;
  cin >> cases;
  string line;
  getline(cin, line);
  while(cases--) {
    vector<string> matrix;
    int maxlength = 0;
    while(true) {
      getline(cin, line);
      if(!separator(line)) {
	matrix.push_back(line);
	maxlength = max(maxlength, (int) line.length() + 1);
      }
      else
	break;
    }
    for(int i= 0; i < matrix.size(); i++) {
      string each = matrix[i];
      while(each.size() != maxlength)
	each += " ";
      matrix[i] = each;
    }
    int r = matrix.size();
    int c = maxlength;
    int color[r][c];
    memset(color, -1, sizeof color);
    for(int i= 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
	if(matrix[i][j] != ' ' && matrix[i][j] != 'X') {
	  char printchar = matrix[i][j];
	  color[i][j] = 0;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  vector<pair<int, int> > v;
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    v.push_back(next);
	    int x = next.first;
	    int y = next.second;
	    // if(legal(x-1, y-1, r, c) && color[x-1][y-1] == -1 && matrix[x-1][y-1] == ' ') {
	    //   color[x-1][y-1] = 0;
	    //   paint(x-1, y-1, r, c, matrix);
	    //   s.push(make_pair(x-1, y-1));
	    // }
	    if(legal(x-1, y, r, c) && color[x-1][y] == -1 && matrix[x-1][y] != 'X') {
	      color[x-1][y] = 0;
	      if(boundary(x-1, y, r, c))
		printchar = matrix[x-1][y] == printchar ? printchar : -1;
	      s.push(make_pair(x-1, y));
	    }
	    // if(legal(x-1, y+1, r, c) && color[x-1][y+1] == -1 && matrix[x-1][y+1] == ' ') {
	    //   color[x-1][y+1] = 0;
	    //   paint(x-1, y+1, r, c, matrix);
	    //   s.push(make_pair(x-1, y+1));
	    // }
	    if(legal(x, y-1, r, c) && color[x][y-1] == -1 && matrix[x][y-1] != 'X') {
	      color[x][y-1] = 0;
	      if(boundary(x, y-1, r, c))
		printchar = matrix[x][y-1] == printchar ? printchar : -1;
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && color[x][y+1] == -1 && matrix[x][y+1] != 'X') {
	      color[x][y+1] = 0;
	      if(boundary(x, y+1, r, c))
		printchar = matrix[x][y+1] == printchar ? printchar : -1;
	      s.push(make_pair(x, y+1));
	    }
	    // if(legal(x+1, y-1, r, c) && color[x+1][y-1] == -1 && matrix[x+1][y-1] == ' ') {
	    //   color[x+1][y-1] = 0;
	    //   paint(x+1, y-1, r, c, matrix);
	    //   s.push(make_pair(x+1, y-1));
	    // }
	    if(legal(x+1, y, r, c) && color[x+1][y] == -1 && matrix[x+1][y] != 'X') {
	      color[x+1][y] = 0;
	      if(boundary(x+1, y, r, c))
		printchar = matrix[x+1][y] == printchar ? printchar : -1;
	      s.push(make_pair(x+1, y));
	    }
	    // if(legal(x+1, y+1, r, c) && color[x+1][y+1] == -1 && matrix[x+1][y+1] == ' ') {
	    //   color[x+1][y+1] = 0;
	    //   paint(x+1, y+1, r, c, matrix);
	    //   s.push(make_pair(x+1, y+1));
	    // }
	  }
	  if(printchar != -1) {
	    for(vector<pair<int, int> >::iterator itr = v.begin(); itr != v.end(); itr++) {
	      paint(itr->first, itr->second, printchar, matrix);
	    }
	  }
	}
      }
    }
    for(int i= 0; i < matrix.size(); i++){
      bool printed = false;
      for(int j = c; j > 0; j--) {
	if(matrix[i][j-1] != ' ') {
	  cout << matrix[i].substr(0, j) << endl;
	  printed = true;
	  break;
	}
      }
      if(!printed)
	cout << endl;
    }
    cout << line << endl;
  }
  return 0;
}
