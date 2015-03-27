#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#define INF 2e8
using namespace std;

int s, t, f;
map<int, int> p;
int adjMat[203][203];
map<int, vector<int> > adjList;

void insertOrAdd(int u, int v) {
  if(adjList.count(u) == 0) {
    vector<int> singleton;
    singleton.push_back(v);
    adjList[u] = singleton;
  } else
    adjList[u].push_back(v);
}

void augmentPath(int u, int minEdge) {
  if(u == s) {
    f= minEdge;
    return;
  } else if (p.count(u)) {
    augmentPath(p[u], min(minEdge, adjMat[p[u]][u]));
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> set1;
  for(int i= 0; i < n; i++) {
    int x;
    cin >> x;
    set1.push_back(x);
  }
  int m; 
  cin >> m;
  vector<int> set2;
  for(int i = 0; i < m; i++) {
    int x;
    cin >> x;
    set2.push_back(x);
  }
  s = 0;
  t = n+m+1;
  for(int i = 0; i < n; i++) {
    for(int j= 0; j < m; j++) {
      //cout << set1[i] << " vs " << set2[j] << endl;
      if(abs(set1[i] - set2[j]) <= 1) {
	adjMat[i+1][j+1+n] = 1;
	insertOrAdd(i+1, j+1+n);
	insertOrAdd(j+1+n, i+1);
      }
    }					    
    adjMat[s][i+1] = 1;
    insertOrAdd(s, i+1);
    insertOrAdd(i+1, s);
  }

  for(int i = 0; i < m; i++) {
    adjMat[n+i+1][t] = 1;
    insertOrAdd(n+i+1, t);
    insertOrAdd(t, n+i+1);
  }

  // cout << "before max_flow: " << endl;
  // for(int i = s; i <= t; i++) {
  //   for(int j= s; j <= t; j++) {
  //     cout << adjMat[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int max_flow = 0;
  while(true) {
    f = 0;
    map<int, int> dist;
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      if(u == t)
	break;
      vector<int> uAdj = adjList[u];
      for(int i = 0; i < uAdj.size(); i++) {
	int v = uAdj[i];
	if(adjMat[u][v] > 0 && !dist.count(v)) {
	  dist[v] = dist[u] + 1;
	  p[v] = u;
	  q.push(v);
	}
      }
    }
    augmentPath(t, INF);
    if(f == 0)
      break;
    max_flow += f;
  }

  // cout << "after max_flow: " << endl;
  // for(int i = s; i <= t; i++) {
  //   for(int j= s; j <= t; j++) {
  //     cout << adjMat[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << max_flow << endl;
  return 0;
}
