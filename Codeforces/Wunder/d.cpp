#include <cstdio>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 200000;
int n, x, y;
typedef pair<int, int> Edge;
Edge edges[maxn+1];
bool deleted[maxn+1];
map<int, vector<int> > adjList;
int degree[maxn+1];

int main() {
  scanf("%d%d%d", &n, &x, &y);
  memset(deleted, false, sizeof deleted);
  memset(degree, 0, sizeof degree);
  bool all = false;
  for(int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    edges[i] = make_pair(a, b);
    adjList[a].push_back(i);
    adjList[b].push_back(i);
    degree[a]++;
    degree[b]++;
    //printf("increasing %d %d\n", a, b);
    if(degree[a] == n - 1 || degree[b] == n - 1)
      all = true;
  }
  if(x < y) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      bool left = true;
      while(degree[i] > 2) {
	//printf("degree[%d]=%d\n", i, degree[i]);
	bool progress = false;
	for(int j = 0; j < adjList[i].size(); j++) {
	  int ei = adjList[i][j];
	  if(deleted[ei]) {
	    continue;
	  }
	  Edge& e = edges[ei];
	  int other = e.first == i ? e.second : e.first;
	  if(left) {
	    if(degree[other] > 2) {
	      //printf("deleting %d\n", ei);
	      deleted[ei] = true;
	      degree[other]--;
	      degree[i]--;
	      cnt++;
	      progress = true;
	    }
	  } else {
	    //printf("deleting %d\n", ei);
	    deleted[ei] = true;
	    degree[other]--;
	    degree[i]--;
	    cnt++;
	    progress = true;
	  }
	}
	if(!progress) {
	  left = false;
	}
      }
    }
    printf("%I64d\n", (n - 1) * 1LL * y - (y - x) * 1LL * cnt);
  } else {
    long long ans = (n - 1) * y;
    if(all)
      ans += x - y;
    printf("%I64d\n", ans);
  }
  return 0;
}
