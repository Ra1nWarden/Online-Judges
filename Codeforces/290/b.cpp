#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

typedef pair<pair<int, int>, int> xyp;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int rev[] = {1, 0, 3, 2};

int main() {
  int n, m;
  string line;
  cin >> n >> m;
  getline(cin, line);
  vector<string> v(n);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    v[i] = line;
  }
  bool visited[n][m];
  memset(visited, false, sizeof visited);
  bool cycle = false;
  for(int i= 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!visited[i][j]) {
	char color = v[i][j];
	visited[i][j] =  true;
	stack<xyp> s;
	s.push(make_pair(make_pair(i, j), -1));
	while(!s.empty()) {
	  xyp next = s.top();
	  s.pop();
	  int nextx = next.first.first;
	  int nexty = next.first.second;
	  for(int k = 0; k < 4; k++) {
	    if(k == next.second)
	      continue;
	    int newx = nextx + dx[k];
	    int newy = nexty + dy[k];
	    if(newx > -1 && newx < n && newy > -1 && newy < m && v[newx][newy] == color) {
	      if(visited[newx][newy]) {
		//cout << "k is " << k << endl;
		//cout << "found " << newx << " " << newy << " char is " << v[newx][newy] << " next is " << nextx << " " << nexty << endl; 
		cycle = true;
		break;
	      } else {
		visited[newx][newy] = true;
		s.push(make_pair(make_pair(newx, newy), rev[k]));
	      }
	    }
	  }
	  if(cycle)
	    break;
	}
      }
      if(cycle)
	break;
    }
    if(cycle)
      break;
  }
  cout << (cycle ? "Yes" : "No") << endl; 
  return 0;
}
