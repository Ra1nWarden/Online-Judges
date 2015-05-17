#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 25
#define MAXM 105
#define INF 2000000000

using namespace std;

int n, m;
int cost[MAXM];
char before[MAXM][MAXN];
char after[MAXM][MAXN];
bool visited[(1 << 20) + 5];
int dist[(1 << 20) + 5];
typedef pair<int, int> HeapNode; // distance, vertex

int main() {
  int kase = 1;
  while(scanf("%d %d\n", &n, &m) != EOF && (n || m)) {
    for(int i = 0; i < m; i++) {
      scanf("%d %s %s\n", &cost[i], before[i], after[i]);
    }
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode> > pq;
    memset(visited, false, sizeof visited);
    for(int i = 0; i < (1 << n); i++)
      dist[i] = INF;
    dist[(1 << n) - 1] = 0;
    pq.push(make_pair(0, (1 << n) - 1));
    int ans = -1;
    while(!pq.empty()) {
      HeapNode next = pq.top();
      pq.pop();
      int u = next.second;
      int cst = next.first;
      visited[u] = true;
      if(u == 0) {
	ans = cst;
	break;
      }
      for(int i = 0; i < m; i++) {
	bool compatible = true;
	for(int j = 0; j < n; j++) {
	  if((before[i][j] == '-' && ((1 << j) & u) != 0) || (before[i][j] == '+' && ((1 << j) & u) == 0)) {
	    compatible = false;
	    break;
	  }
	}
	if(compatible) {
	  int new_dist = cst + cost[i];
	  int v = u;
	  for(int j = 0; j < n; j++) {
	    if(after[i][j] == '+') {
	      v = (v | (1 << j));
	    } else if(after[i][j] == '-') {
	      if(((1 << j) & u) != 0) {
		v = (v ^ (1 << j));
	      }
	    }
	  }
	  if(!visited[v] && dist[v] > new_dist) {
	    pq.push(make_pair(new_dist, v));
	  }
	}
      }
    }
    printf("Product %d\n", kase++);
    if(ans == -1) {
      printf("Bugs cannot be fixed.\n");
    } else {
      printf("Fastest sequence takes %d seconds.\n", ans);
    }
    printf("\n");
  }
  return 0;
}
