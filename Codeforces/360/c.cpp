#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100000;
typedef pair<int, int> Edge;
Edge edges[maxn+5];
vector<int> adjMat[maxn+5];
int n, m;
int color[maxn+5];

void print(int num) {
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(color[i] == num)
      ans++;
  }
  printf("%d\n", ans);
  bool start = true;
  for(int i = 1; i <= n; i++) {
    if(color[i] == num) {
      if(!start)
	printf(" ");
      printf("%d", i);
      start = false;
    }
  }
  printf("\n");
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &edges[i].first, &edges[i].second);
    adjMat[edges[i].first].push_back(i);
    adjMat[edges[i].second].push_back(i);
  }
  memset(color, 0, sizeof color);
  bool ok = true;
  for(int i = 1; i <= n; i++) {
    if(adjMat[i].empty()) {
      continue;
    }
    if(color[i] != 0) {
      continue;
    }
    queue<int> q;
    color[i] = -1;
    q.push(i);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(int ii = 0; ii < adjMat[u].size(); ii++) {
	Edge& e = edges[adjMat[u][ii]];
	int j = e.first == u ? e.second : e.first;
	if(color[j] != 0 && color[j] + color[u] != 0) {
	  ok = false;
	  break;
	} else if(color[j] == 0) {
	  color[j] = -color[u];
	  q.push(j);
	}
      }
      if(!ok)
	break;
    }
    if(!ok)
      break;
  }
  if(!ok)
    printf("-1\n");
  else {
    print(-1);
    print(1);
  }
  return 0;
}
