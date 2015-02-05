#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

struct Node {
  Node(int a, char b) : n(a), c(b) {};
  char c;
  int n;
  bool operator<(const Node& another) const {
    if(n == another.n) {
      return c < another.c;
    } else {
      return another.n < n;
    }
  };
};

bool legal(int x, int y, int r, int c) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

int main() {
  int r, c;
  int caseNo = 1;
  while(cin >> r >> c >> ws && (r || c)) {
    vector<string> matrix;
    for(int i= 0; i < r; i++) {
      string line;
      getline(cin, line);
      matrix.push_back(line);
    }
    bool visited[r][c];
    memset(visited, false, sizeof visited);
    vector<Node> nodes;
    for(int i= 0; i < r; i++) {
      for(int j= 0; j < c; j++) {
	if(matrix[i][j] != '.' && !visited[i][j]) {
	  int match = matrix[i][j];
	  stack<pair<int, int> > s;
	  visited[i][j] = true;
	  s.push(make_pair(i, j));
	  int size = 1;
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1, y, r, c) && !visited[x-1][y] && matrix[x-1][y] == match) {
	      visited[x-1][y] = true;
	      size++;
	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x, y-1, r, c) && !visited[x][y-1] && matrix[x][y-1] == match) {
	      visited[x][y-1] = true;
	      size++;
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && !visited[x][y+1] && matrix[x][y+1] == match) {
	      visited[x][y+1] = true;
	      size++;
	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y, r, c) && !visited[x+1][y] && matrix[x+1][y] == match) {
	      visited[x+1][y] = true;
	      size++;
	      s.push(make_pair(x+1, y));
	    }
	  }
	  Node each(size, match);
	  nodes.push_back(each);
	}
      }
    }
    sort(nodes.begin(), nodes.end());
    cout << "Problem " << caseNo++ << ":" << endl;
    for(int i= 0; i < nodes.size(); i++) {
      cout << nodes[i].c << " " << nodes[i].n << endl;
    }
  }
  return 0;
}
