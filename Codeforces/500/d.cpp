#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 200000;
vector<int> adjMat[2][maxn+5];
int vis[2][maxn+5];
typedef pair<int, int> Node;

void bfs(int r, int c, int cnt) {
  queue<Node> q;
  q.push(make_pair(r, c));
  while(!q.empty()) {
    Node u = q.front();
    q.pop();
    vis[u.first][u.second] = cnt;
    for(int i = 0; i < adjMat[u.first][u.second].size(); i++) {
      int rr = u.first ^ 1;
      int cc = adjMat[u.first][u.second][i];
      if(vis[rr][cc]) {
	continue;
      }
      q.push(make_pair(rr, cc));
    }
  }
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  while(q--) {
    int r, c;
    scanf("%d%d", &r, &c);
    adjMat[0][r].push_back(c);
    adjMat[1][c].push_back(r);
  }
  memset(vis, 0, sizeof vis);
  int cnt = 1;
  for(int i = 0; i < 2; i++) {
    for(int j = 1; j <= (i ? m : n); j++) {
      if(vis[i][j]) {
	continue;
      }
      bfs(i, j, cnt);
      cnt++;
    }
  }
  printf("%d\n", cnt-2);
  return 0;
}
