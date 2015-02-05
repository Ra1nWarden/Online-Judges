#include <iostream>
#include <cstring>

using namespace std;

int v[1001][1001];
int directed[1001][1001];
int dfsnum[1001];
int dfslow[1001];
int parent[1001];
int root = 0;
int dfsiter = 0;
int n;

void findArticulationBridge(int u) {
  // cout << "calling " << u << endl;
  dfsnum[u] = dfslow[u] = dfsiter++;
  for(int i = 0; i < n ;i++) {
    if(v[u][i]) {
      // cout << "checking " << i << endl;
      if(dfsnum[i] == -1) {
	// not visited
	// cout << "not visited"<< endl;
	parent[i] = u;
	directed[u][i] = 1;
	findArticulationBridge(i);
	if(dfslow[i] > dfsnum[u]) {
	  directed[i][u] = 1;
	}
	dfslow[u] = min(dfslow[u], dfslow[i]);
      } else if (i != parent[u]){ 
	// visited
	if(!(directed[u][i] || directed[i][u]))
	  // it is not possible to set directed[i][u] as there must be a path from i to u.
	  // if directed[u][i] is set, we dont set directed[i][u] as it will lead to bidrectional and hence a bridge
	  // bridges should be able to detect in the previous if branch
	  directed[u][i] = 1;
	dfslow[u] = min(dfslow[u], dfsnum[i]);
      }
    }
  }
}

int main() {
  int edges;
  int caseNo =1;
  while(cin >> n >> edges && (n || edges)) {
    memset(v, 0, sizeof v);
    memset(directed, 0, sizeof v);
    memset(dfsnum, -1, sizeof dfsnum);
    memset(dfslow, -1, sizeof dfslow);
    for(int i= 0; i < edges; i++) {
      int x ,y;
      cin >> x >> y;
      v[x-1][y-1] = 1;
      v[y-1][x-1] = 1;
    }
    findArticulationBridge(0);
    cout << caseNo++ << endl;
    cout << endl;
    for(int i= 0;i < n; i++) {
      for(int j=0; j < n; j++) {
	if(directed[i][j])
	  cout << i+1 << " " << j+1 << endl;
      }
    }
    cout << "#" << endl;
  }
  return 0;
}
