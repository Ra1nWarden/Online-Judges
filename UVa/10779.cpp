#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <queue>
#define INF 2e8

using namespace std;

int n, m, s, t, f;
int adjMat[40][40];
map<int, int> p;
map<int, set<int> > adjList;

void initOrAdd(int x, int y) {
  if(adjList.count(x) == 0) {
    set<int> singleton;
    singleton.insert(y);
    adjList[x] = singleton;
  }
  else {
    adjList[x].insert(y);
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
  int tc;
  cin >> tc;
  for(int caseNo = 1; caseNo <= tc; caseNo++) {
    cin >> n >> m;
    memset(adjMat, -1, sizeof adjMat);
    adjList.clear();
    p.clear();
    // nodes start from sticker number, then people, then source
    for(int i= m+1; i <= m+n; i++) {
      int count;
      cin >> count;
      vector<int> stickers(m+1, 0);
      for(int j= 0; j < count; j++) {
	int type;
	cin >> type;
	stickers[type]++;
      }
      if(i != m+1) {
	for(int k = 1; k <= m; k++) {
	  if(stickers[k] == 0) {
	    adjMat[k][i] = 1;
	    adjMat[i][k] = 0;
	    initOrAdd(k, i);
	    initOrAdd(i, k);
	  }
	  else if (stickers[k] > 1) {
	    adjMat[i][k] = stickers[k] - 1;
	    adjMat[k][i] = 0;
	    initOrAdd(i, k);
	    initOrAdd(k, i);
	  }
	}
      }
      else {
	for(int k = 1; k <= m; k++) {
	  if(stickers[k] > 0) {
	    adjMat[i][k] = stickers[k];
	    adjMat[k][i] = 0;
	    initOrAdd(i, k);
	    initOrAdd(k, i);
	  }
	}
      }
    }

    s = m+1;
    t = m+n+1;

    //cout << "source is " << s << " sink is "  << t << endl;
    
    for(int i = 1; i <= m; i++) {
      adjMat[i][t] = 1;
      initOrAdd(i, t);
    }

    // cout << "adj matrix: " << endl;
    // for(int i= 1; i <= m+n+1; i++) {
    //   for(int j= 1; j <= m+n+1; j++) {
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
	//cout << "front of queue is " << u << endl;
	if(u == t) {
	  break;
	}
	set<int> adj = adjList[u];
	for(set<int>::iterator itr = adj.begin(); itr != adj.end(); itr++) {
	  if(adjMat[u][*itr] > 0 && !dist.count(*itr)) {
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

    printf("Case #%d: %d\n", caseNo, max_flow);
    
  }
  return 0;
}
