#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n, m, l;
    cin >> n >> m >> l;
    int v[n][n];
    for(int i= 0; i < n; i++) 
      for(int j= 0; j <n; j++)
	v[i][j] = 0;
    for(int i= 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      v[x-1][y-1] = 1;
    }
    bool visited[n];
    for(int i= 0; i < n; i++)
      visited[i] = false;
    for(int i= 0; i < l; i++) {
      int q;
      cin >> q;
      if(!visited[q-1]) {
	visited[q-1] = true;
	stack<int> s;
	s.push(q-1);
	while(!s.empty()) {
	  int next = s.top();
	  s.pop();
	  for(int j = 0; j < n; j++) {
	    if(v[next][j] && !visited[j]) {
	      visited[j] = true;
	      s.push(j);
	    }
	  }
	}
      }
    }
    int result = 0;
    for(int i= 0; i < n; i++) {
      if(visited[i])
	result++;
    }
    cout << result << endl;
  }
  return 0;
}
