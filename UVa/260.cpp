#include <iostream>
#include <map>
#include <utility>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

bool legal(int i, int j, int n) {
  return (i >= 0 && i < n) && (j >= 0 && j < n);
}

int main() {
  int n;
  vector<string> matrix;
  int caseNo = 1;
  while(cin >> n >> ws && n) {
    string line;
    matrix.clear();
    for(int i= 0; i < n ;i++) {
      getline(cin, line);
      matrix.push_back(line);
    }
    stack<pair<int, int> > s;
    bool visited[n][n];
    memset(visited, false, sizeof visited);
    for(int i= 0; i < n; i++) {
      if(matrix[i][0] == 'w') {
	s.push(make_pair(i, 0));
	visited[i][0] = true;
      }
    }
    bool white = false;
    while(!s.empty()) {
      pair<int, int> next = s.top();
      s.pop();
      int x = next.first;
      int y = next.second;
      // cout << "visiting " << x << ", " << y << endl;
      if(y == n-1) {
	white = true;
	break;
      }
      if(legal(x - 1, y - 1, n) && matrix[x-1][y-1] == 'w' && !visited[x-1][y-1]) {
	visited[x-1][y-1] = true;
	s.push(make_pair(x-1, y-1));
      }

      if(legal(x - 1, y, n) && matrix[x-1][y] == 'w' && !visited[x-1][y]) {
	visited[x-1][y] = true;
	s.push(make_pair(x-1, y));
      }

      if(legal(x, y - 1, n) && matrix[x][y-1] == 'w' && !visited[x][y-1]) {
	visited[x][y-1] = true;
	s.push(make_pair(x, y-1));
      }

      if(legal(x, y + 1, n) && matrix[x][y+1] == 'w' && !visited[x][y+1]) {
	visited[x][y+1] = true;
	s.push(make_pair(x, y+1));
      }

      if(legal(x + 1, y , n) && matrix[x+1][y] == 'w' && !visited[x+1][y]) {
	visited[x+1][y] = true;
	s.push(make_pair(x+1, y));
      }
 
      if(legal(x + 1, y + 1, n) && matrix[x+1][y+1] == 'w' && !visited[x+1][y+1]) {
	visited[x+1][y+1] = true;
	s.push(make_pair(x+1, y+1));
      }

    }
    cout << caseNo++ << " " << (white ? "W" : "B") << endl;
  }
  return 0;
}
