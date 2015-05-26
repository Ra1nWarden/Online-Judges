#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 16

using namespace std;

bool adjMat[MAXN][MAXN];
bool adjMat2[MAXN][MAXN];
bool visited[MAXN];
int n;
typedef pair<int, int> II;

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    memset(adjMat, false, sizeof adjMat);
    int a, b;
    while(scanf("%d %d", &a, &b) == 2 && (a != -1 && b != -1)) {
      adjMat[a][b] = adjMat[b][a] = true;
    }
    int ans = n;
    for(int bitmask = 0; bitmask < (1 << n); bitmask++) {
      memcpy(adjMat2, adjMat, sizeof adjMat);
      for(int i = 0; i < n; i++) {
	if(((1 << i) & bitmask) != 0) {
	  for(int j = 1; j <= n; j++) {
	    adjMat2[j][i+1] = adjMat2[i+1][j] = false;
	  }
	}
      }
      bool ok = true;
      for(int i = 1; i <= n; i++) {
	int degree = 0;
	for(int j = 1; j <= n; j++) {
	  if(adjMat2[i][j])
	    degree++;
	}
	if(degree > 2) {
	  ok = false;
	  break;
	}
      }
      if(ok) {
	int next_ans = 0;
	for(int i = 0; i < n; i++) {
	  if(((1 << i) & bitmask) != 0)
	    next_ans++;
	}
	int component = 0;
	memset(visited, false, sizeof visited);
	for(int i = 1; i <= n; i++) {
	  if((bitmask & (1 << (i - 1))) != 0)
	    continue;
	  if(!visited[i]) {
	    component++;
	    queue<II> q;
	    q.push(make_pair(i, 0));
	    visited[i] = true;
	    while(!q.empty()) {
	      II next = q.front();
	      q.pop();
	      for(int j = 1; j <= n; j++) {
		if(next.second == j)
		  continue;
		if(adjMat2[next.first][j]) {
		  if(visited[j]) {
		    ok = false;
		    break;
		  } else {
		    q.push(make_pair(j, next.first));
		    visited[j] = true;
		  }
		}
	      }
	      if(!ok)
		break;
	    }
	    if(!ok)
	      break;
	  }
	}
	if(ok) {
	  if(next_ans >= component - 1) {
	    ans = min(ans, next_ans);
	  }
	}
      }
    }
    printf("Set %d: Minimum links to open is %d\n", kase++, ans);
  }
  return 0;
}
