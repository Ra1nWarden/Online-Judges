#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    int m[n+1][n+1];
    memset(m, 0, sizeof m);
    for(int i= 1; i <= n; i++) {
      int edgen;
      cin >> edgen;
      for(int j= 0; j < edgen; j++) {
	int source;
	cin >> source;
	m[source][i] = 1;
      }
    }
    int v[n+1];
    memset(v, 0, sizeof v);
    for(int i= 1; i <= n; i++) {
      stack<int> s;
      s.push(i);
      while(!s.empty()) {
	int next = s.top();
	s.pop();
	for(int j = 1; j <= n; j++) {
	  if(m[next][j]) {
	    v[j]++;
	    s.push(j);
	  }
	}
      }
    }
    int max = -1;
    int maxindex = -1;
    for(int i = 1; i<= n; i++) {
      if(v[i] > max) {
	max = v[i];
	maxindex = i;
      }
    }
    cout << maxindex << endl;
  }
  return 0;
}
