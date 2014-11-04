#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
#define INF 2e8

using namespace std;

map<int, int> p;
int adj[101][101];
int n, f, s, t;
map<int, set<int> > adjList;

void insertOrInit(int parent, int child) {
  if(adjList.count(parent) == 0) {
    set<int> singleton;
    singleton.insert(child);
    adjList[parent] = singleton;
  }
  else {
    adjList[parent].insert(child);
  }
}

void augmentPath(int v, int minEdge) {
  if(v == s) {
    f = minEdge;
    return;
  }
  else if (p.count(v)) {
    augmentPath(p[v], min(minEdge, adj[p[v]][v]));
    adj[p[v]][v] -= f;
    adj[v][p[v]] += f;
  }
}

int main() {
  int tc = 1;
  while(cin >> n && n) {
    adjList.clear();
    p.clear();
    int edge;
    cin >> s >> t >> edge;
    memset(adj, -1, sizeof adj);
    for(int i= 0; i < edge; i++) {
      int start, end, weight;
      cin >> start >> end >> weight;
      if(adj[start][end] == -1) {
	adj[start][end] = weight;
	adj[end][start] = weight;
      }
      else {
	adj[start][end] += weight;
	adj[end][start] += weight;
      }
      insertOrInit(start, end);
      insertOrInit(end, start);
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
	set<int> neighbor = adjList[u];
	for(set<int>::iterator itr = neighbor.begin(); itr != neighbor.end(); itr++) {
	  if(adj[u][*itr] > 0 && !dist.count(*itr)) {
	    dist[*itr] = dist[u] + 1;
	    q.push(*itr);
	    p[*itr] = u;
	  }
	}
      }
      augmentPath(t, INF);
      if(f == 0)
	break;
      max_flow += f;
    }
    printf("Network %d\n", tc++);
    printf("The bandwidth is %d.\n\n", max_flow);
  }
  return 0;
}
