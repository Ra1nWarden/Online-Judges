#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#define INF 2e8

using namespace std;

int s = 1;
int t = 2;
int f, n;
int adjMat[51][51];
bool reachable[51];
int dist[51];

map<int, int> p;
map<int, vector<int> > adjList;

void insertOrInit(int a, int b) {
  if(adjList.count(a) == 0) {
    vector<int> singleton;
    singleton.push_back(b);
    adjList[a] = singleton;
  }
  else {
    adjList[a].push_back(b);
  }
}

void augmentPath(int v, int minEdge) {
  if(v == s) {
    f = minEdge;
    return;
  }
  else if (p.count(v)) {
    augmentPath(p[v], min(minEdge, adjMat[p[v]][v]));
    adjMat[p[v]][v] -= f;
    adjMat[v][p[v]] += f;
  }
}

int main() {
  int edge;
  while(cin >> n >> edge && (n || edge)) {
    int x, y, weight;
    memset(adjMat, -1, sizeof adjMat);
    memset(dist, -1, sizeof dist);
    adjList.clear();
    for(int i = 0; i < edge; i++) {
      cin >> x >> y >> weight;
      adjMat[x][y] = weight;
      adjMat[y][x] = weight;
      insertOrInit(x, y);
      insertOrInit(y, x);
    }
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
	if(u == t)
	  break;
	vector<int> adj = adjList[u];
	for(int i= 0; i < adj.size(); i++) {
	  if(adjMat[u][adj[i]] > 0  && !dist.count(adj[i])) {
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

    memset(reachable, false, sizeof reachable);
    reachable[1] = true;
    stack<int> s;
    s.push(1);
    while(!s.empty()) {
      int next = s.top();
      s.pop();
      for(int i= 1; i <= n; i++) {
	if(adjMat[next][i] > 0 && !reachable[i]) {
	  reachable[i] = true;
	  s.push(i);
	}
      }
    }

    // for(int i = 1; i <= n ;i++) {
    //   cout << i << " is " << (reachable[i] ? "reachable" : "not reachable") << endl; 
    // }

    for(int i= 1; i <= n; i++) {
      for(int j= 1; j <= n; j++) {
	if(reachable[i] && !reachable[j] && adjMat[i][j] > -1)
	  cout << i << " " << j << endl;
      }
    }
    
    cout << endl;
  }
  return 0;
}
