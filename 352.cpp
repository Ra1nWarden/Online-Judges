#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

bool legal(int x, int y, int n, vector<string>& v,vector<vector<int> > cm) {
  return x >= 0 && x < n && y >= 0 && y < n && v[x][y] == '1' && cm[x][y] == -1;
}

int main() {
  int n;
  int tc = 1;
  while(cin >> n >> ws) {
    vector<string> v;
    for(int i= 0; i < n; i++) {
      string line;
      getline(cin ,line);
      v.push_back(line);
    }
    stack<pair<int, int> > s;
    vector<vector<int> > color(n);
    for(int i= 0; i < n; i++) {
      vector<int> row(n, -1);
      color[i] = row;
    }
    int c = 0;
    for(int i= 0; i < n; i++) {
      for(int j= 0; j < n; j++) {
	if(v[i][j] == '1' && color[i][j] == -1) {
	  s.push(make_pair(i, j));
	  color[i][j] = c;
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;

	    if(legal(x-1, y-1, n, v, color)) {
	      color[x-1][y-1] = c;
	      s.push(make_pair(x-1, y-1));
	    }

	    if(legal(x-1, y, n, v, color)) {
	      color[x-1][y] = c;
	      s.push(make_pair(x-1, y));
	    }

	    if(legal(x-1, y+1, n, v, color)) {
	      color[x-1][y+1] = c;
	      s.push(make_pair(x-1, y+1));
	    }

	    if(legal(x, y-1, n, v, color)) {
	      color[x][y-1] = c;
	      s.push(make_pair(x, y-1));
	    }

	    if(legal(x, y+1, n, v, color)) {
	      color[x][y+1] = c;
	      s.push(make_pair(x, y+1));
	    }

	    if(legal(x+1, y-1, n, v, color)) {
	      color[x+1][y-1] = c;
	      s.push(make_pair(x+1, y-1));
	    }

	    if(legal(x+1, y, n, v, color)) {
	      color[x+1][y] = c;
	      s.push(make_pair(x+1, y));
	    }

	    if(legal(x+1, y+1, n, v, color)) {
	      color[x+1][y+1] = c;
	      s.push(make_pair(x+1, y+1));
	    }
	  }
	  c++;
	}
      }
    }
    printf("Image number %d contains %d war eagles.\n", tc++, c);
  }

  return 0;
}
