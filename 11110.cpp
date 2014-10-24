#include <iostream>
#include <cstring>
#include <stack>
#include <utility>
#include <sstream>

using namespace std;

bool DEBUG = false;

bool legal(int x, int y, int n) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
  int n;
  while(cin >> n && n) {
    string line;
    getline(cin, line);
    if(DEBUG)
      cout << "read n is " << n << endl;
    int m[n][n];
    memset(m, 0, sizeof m);
    for(int i = 1; i <= n-1; i++) {
      getline(cin, line);
      if(DEBUG)
	cout << "read line " << line << endl;
      istringstream iss(line.c_str());
      int x, y;
      while(iss >> x >> y)
	m[x-1][y-1] = i;
    }
    bool valid = true;
    int visited[n][n];
    if(DEBUG) {
      for(int i= 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  cout << m[i][j];
	}
	cout << endl;
      }
    }
    memset(visited, false, sizeof visited);
    for(int i= 0; i < n; i++) {
      for(int j= 0; j < n; j++) {
	if(!visited[i][j]) {
	  int number = m[i][j];
	  int count = 1;
	  visited[i][j] =true;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1,y,n) && !visited[x-1][y] && m[x-1][y] == number) {
	      count++;
	      visited[x-1][y] =true;
	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x,y-1,n) && !visited[x][y-1] && m[x][y-1] == number) {
	      count++;
	      visited[x][y-1] =true;
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x,y+1,n) && !visited[x][y+1] && m[x][y+1] == number) {
	      count++;
	      visited[x][y+1] =true;
	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1,y,n) && !visited[x+1][y] && m[x+1][y] == number) {
	      count++;
	      visited[x+1][y] =true;
	      s.push(make_pair(x+1, y));
	    }
	  }
	  if(count != n) {
	    valid = false;
	    break;
	  }
	}
      }
      if(!valid)
	break;
    }
    cout << (valid ? "good" : "wrong") << endl;
  }
}
