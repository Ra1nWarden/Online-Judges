#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#define INF 2e8

using namespace std;

int n, s;
bool am[101][101];
int dist[101];
bool dfsVisit[101];
stack<int> toposorted;

void toposort(int x) {
  dfsVisit[x] = true;
  for(int i = 1; i <= n; i++) {
    if(am[x][i] && !dfsVisit[i]) {
      toposort(i);
    }
  }
  toposorted.push(x);
}

int main() {
  int tc= 1;
  bool debug = false;
  while(cin >> n && n) {
    cin >> s;
    if(debug)
      cout << "source is " << s << endl;
    memset(am, false, sizeof am);
    int x, y;
    while(cin >> x >> y && (x || y)) {
      if(debug) {
	cout << "edge is " << x << "->" << y << endl;
      }
      am[x][y] = true;
    }
    memset(dfsVisit, false, sizeof dfsVisit);
    toposort(s);
    for(int i =1; i <= n; i++)
      dist[i] = INF;
    dist[s] = 0;
    int minDist = INF;
    int minIndex = INF;
    while(!toposorted.empty()) {
      int a = toposorted.top();
      toposorted.pop();
      if(debug) {
	cout << a << endl;
      }
      for(int j = 1; j <= n; j++) {
	if(am[a][j]) {
	  dist[j] = min(dist[j], dist[a] - 1);
	  if(dist[j] < minDist) {
	    minDist = dist[j];
	    minIndex = j;
	  }
	  else if (dist[j] == minDist) {
	    minIndex = min(minIndex, j);
	  }
	}
      }
    }
    printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", tc++, s, -minDist == -INF ? 0 : -minDist , minIndex == INF ? s : minIndex);
  }
  return 0;
}
