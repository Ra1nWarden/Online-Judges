#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
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
  } else {
    adjList[u].push_back(v);
  }
}

void augmentPath(int u, int minEdge) {
  if(u == s) {
    f = minEdge;
    return;
  } else if (p.count(u)) {
    augmentPath(p[u], min(minEdge, adjMat[p[u]][u]));
    adjMat[u][p[u]] += f;
    adjMat[p[u]][u] -= f;
  }
}

int main() {
  int tc;
  cin >> tc;
  for(int caseNo = 1; caseNo <= tc; caseNo++) {
    p.clear();
    memset(adjMat, 0, sizeof adjMat);
    adjList.clear();
    int n;
    cin >> n;
    vector<int> s1;
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      s1.push_back(x);
    } 
    int m;
    cin >> m;
    vector<int> s2;
    for(int i = 0; i < m; i++) {
      int x;
      cin >> x;
      s2.push_back(x);
    }

    s = 0;
    t = m+n+1;
    
    for(int i= 0; i < s1.size(); i++) {
      int x = s1[i];
      for(int j= 0; j < s2.size(); j++) {
	int y = s2[j];
	if((x == 0 && y == 0) || (x != 0 && y % x == 0)) {
	  adjMat[i+1][n+j+1] = 1;
	  insertOrAdd(i+1, n+j+1);
	  insertOrAdd(n+j+1, i+1);
	}
      }
      adjMat[s][i+1] = 1;
      insertOrAdd(s, i+1);
      insertOrAdd(i+1, s);
    }

    for(int i = 0; i < s2.size(); i++) {
      adjMat[i+n+1][t] = 1;
      insertOrAdd(i+n+1, t);
      insertOrAdd(t, i+n+1);
    }

    // cout << "before max flow: " << endl;
    // for(int i = s; i <= t; i++) {
    //   for(int j = s; j <= t; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int max_flow = 0;
    while(true) {
      map<int, int> dist;
      queue<int> q;
      q.push(s);
      dist[s] = 0;
      while(!q.empty()) {
	int u = q.front();
	q.pop();
	if(u == t)
	  break;
	vector<int> uAdj = adjList[u];
	for(int i= 0; i < uAdj.size(); i++) {
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

    // cout << "after max flow: " << endl;
    // for(int i = s; i <= t; i++) {
    //   for(int j = s; j <= t; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    printf("Case %d: %d\n", caseNo, max_flow);

  }
  return 0;
}
