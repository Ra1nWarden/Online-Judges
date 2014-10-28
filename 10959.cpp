#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
bool v[1001][1001];
int bfsIndex[1001];

void bfs() {
  bfsIndex[0] =0;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int next = q.front();
    q.pop();
    for(int i = 0; i < n ;i++) {
      if(v[next][i] && bfsIndex[i] == -1) {
	bfsIndex[i] = bfsIndex[next] + 1;
	q.push(i);
      }
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t++) {
    if(t != 0)
      cout << endl;
    cin >> n;
    int dances;
    cin >> dances;
    memset(v, false, sizeof v);
    memset(bfsIndex, -1, sizeof bfsIndex);
    for(int i = 0; i < dances; i++) {
      int x, y;
      cin >> x >> y;
      v[x][y] = true;
      v[y][x] = true;
    }
    bfs();
    for(int i = 1; i < n; i++)
      cout << bfsIndex[i] << endl;
  }
  return 0;
}
