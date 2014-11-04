#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define INF 2e8

using namespace std;

int n, m;

// source set to 1 and sink set to 2n
int adjMat[102][102];
map<int, vector<int> > adjList;
map<int, int> p;

int s, t, f;

void insertOrInit(int x, int y) {
  if(adjList.count(x) == 0) {
    vector<int> singleton;
    singleton.push_back(y);
    adjList[x] = singleton;
  }
  else {
    adjList[x].push_back(y);
  }
}

void augmentPath(int v, int minEdge) {
  if(v == s) {
    f = minEdge;
    return;
  }
  else if(p.count(v)) {
    augmentPath(p[v], min(minEdge, adjMat[p[v]][v]));
    adjMat[p[v]][v] -= f;
    adjMat[v][p[v]] += f;
  }
}

int main() {
  while(cin >> n >> m && (n || m)) {
    adjList.clear();
    memset(adjMat, -1, sizeof adjMat);
    p.clear();
    for(int i = 0; i < n-2; i++) {
      int machine, cost;
      cin >> machine >> cost;
      adjMat[machine * 2][machine * 2 + 1] = cost;
      insertOrInit(machine * 2, machine * 2 + 1);

      adjMat[machine * 2 + 1][machine * 2] = 0;
      insertOrInit(machine * 2 + 1, machine * 2);
    }

    adjMat[2][3] = INF;
    adjMat[3][2] = 0;
    insertOrInit(2, 3);
    insertOrInit(3, 2);
    adjMat[n * 2][n * 2 + 1] = INF;
    adjMat[n*2 + 1][n*2] = 0;
    insertOrInit(n*2+1, n*2);
    insertOrInit(n*2, n*2+1);
    
    s = 2;
    t = 2 * n + 1;

    for(int i = 0; i < m; i++) {
      int start, end, cost;
      cin >> start >> end >> cost;
      //cout << "read " << start << " to " << end << " with cost " << cost << endl;
      adjMat[start * 2 + 1][end * 2] = cost;
      adjMat[end* 2][start *2 + 1] = 0;
      adjMat[end * 2 + 1][start * 2] = cost;
      adjMat[start * 2][end * 2 + 1] = 0;
      insertOrInit(start * 2 + 1, end * 2);
      insertOrInit(end * 2, start * 2 + 1);
      insertOrInit(end * 2 + 1, start * 2);
      insertOrInit(start * 2 , end *2 + 1);
    }

    // cout << "printing adjacency matrix:" << endl;
    // for(int i= 2; i <= 2*n +1; i++) {
    //   for(int j= 2; j <= 2* n + 1; j ++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    
    int max_flow = 0;
    while(true) {
      f = 0;
      queue<int> q;
      map<int, int> dist;
      q.push(s);
      dist[s] = 0;
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	if (u == t)
	  break;
	vector<int> adj = adjList[u];
	for(int i =0; i < adj.size(); i++) {
	  if(adjMat[u][adj[i]] > 0 && !dist.count(adj[i])) {
	    dist[adj[i]] = dist[u] + 1;
	    q.push(adj[i]);
	    p[adj[i]] = u;
	  }
	}
      }
      augmentPath(t, INF);
      if(f == 0)
	break;
      max_flow += f;
    }
    cout << max_flow << endl;
  }
  return 0;
}
