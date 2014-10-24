#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

bool legal(int x, int y, int r, int c) {
  return x >= 0 && x < r && y >= 0 && y < c;
}

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

int main() {
  int cases;
  cin >> cases;
  int caseNo = 1;
  while(cases--) {
    int r, c;
    cin >> r >> c >> ws;
    string line;
    vector<string> matrix;
    for(int i= 0; i < r; i++) {
      getline(cin, line);
      matrix.push_back(line);
    }
    bool visited[r][c];
    memset(visited, false, sizeof visited);
    map<char, int> mapCount;
    for(int i= 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
	if(!visited[i][j]) {
	  int match = matrix[i][j];
	  visited[i][j] = true;
	  stack<pair<int, int> > s;
	  s.push(make_pair(i, j));
	  while(!s.empty()) {
	    pair<int, int> next = s.top();
	    s.pop();
	    int x = next.first;
	    int y = next.second;
	    if(legal(x-1, y, r, c) && matrix[x-1][y] == match && !visited[x-1][y]) {
	      visited[x-1][y] =true;
	      s.push(make_pair(x-1, y));
	    }
	    if(legal(x, y-1,r , c) && matrix[x][y-1] == match && !visited[x][y-1]) {
	      visited[x][y-1] =true;
	      s.push(make_pair(x, y-1));
	    }
	    if(legal(x, y+1, r, c) && matrix[x][y+1] == match && !visited[x][y+1]) {
	      visited[x][y+1] =true;
	      s.push(make_pair(x, y+1));
	    }
	    if(legal(x+1, y,r ,c ) && matrix[x+1][y] == match && !visited[x+1][y]) {
	      visited[x+1][y] =true;
	      s.push(make_pair(x+1, y));
	    }
	  }
	  if(mapCount.count(match) == 0)
	    mapCount[match] = 1;
	  else
	    mapCount[match] = mapCount[match]+1;
	}
      }
    }
    vector<Node> sorted;
    for(map<char, int>::iterator itr = mapCount.begin(); itr != mapCount.end(); itr++) {
      Node each(itr->second, itr->first);
      sorted.push_back(each);
    }
    sort(sorted.begin(), sorted.end());
    cout << "World #" << caseNo++ << endl;
    for(int i= 0; i < sorted.size(); i++) {
      cout << sorted[i].c << ": " << sorted[i].n << endl;
    }
  }
  return 0;
}
