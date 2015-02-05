#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

bool adj[21][21];
int bfsIndex[21];

int bfs(int start, int end) {
  bfsIndex[start] = 0;
  queue<int> q;
  q.push(start);
  while(!q.empty() && bfsIndex[end] == -1) {
    int next = q.front();
    q.pop();
    for(int i= 1; i <= 20; i++) {
      if(adj[next][i] && bfsIndex[i] == -1) {
	bfsIndex[i] = bfsIndex[next] + 1;
	q.push(i);
      }
    }
  }
  return bfsIndex[end];
}

int main() {
  int tc = 1;
  while(cin >> ws && !cin.eof()) {
    memset(adj, false, sizeof adj);
    for(int i= 1; i <= 19; i++) {
      int edge;
      cin >> edge;
      for(int j= 0; j < edge; j++) {
	int end;
	cin >> end;
	adj[i][end] = true;
	adj[end][i] = true;
      }
    }
    int q;
    cin >> q;
    printf("Test Set #%d\n", tc++);
    for(int i = 0; i < q; i++) {
      int start, end;
      cin >> start >> end;
      memset(bfsIndex, -1, sizeof bfsIndex);
      int result = bfs(start, end);
      printf("%2d to %2d: %d\n", start, end, result);
    }
    cout << endl;
  }
  return 0;
}
