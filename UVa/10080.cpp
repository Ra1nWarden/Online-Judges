#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#define INF 2e9
#define EPS 1e-9

using namespace std;

typedef pair<double, double> coord;

int s, t, f;
map<int, int> p;
int adjMat[205][205];
map<int, vector<int> > adjList;

double distSquare(coord one, coord two) {
  return (one.first - two.first) * (one.first - two.first) + (one.second - two.second) * (one.second - two.second);
}

void insertOrAdd(int a, int b) {
  if(adjList.count(a) == 0) {
    vector<int> singleton;
    singleton.push_back(b);
    adjList[a] = singleton;
  } else {
    adjList[a].push_back(b);
  }
}

void augmentPath(int u, int minEdge) {
  if(u == s) {
    f = minEdge;
    return;
  } else if(p.count(u)) {
    augmentPath(p[u], min(minEdge, adjMat[p[u]][u]));
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
  }
}

int main() {
  int n, m;
  double time, v;
  while(cin >> n >> m >> time >> v) {
    vector<coord> gophers;
    vector<coord> holes;
    p.clear();
    memset(adjMat, 0, sizeof adjMat);
    for(int i= 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      gophers.push_back(make_pair(x, y));
    }
    for(int j= 0; j < m; j++) {
      double x, y;
      cin >> x >> y;
      holes.push_back(make_pair(x, y));
    }
    double limit = time * v * time * v;
    s = 0;
    t = m + n + 1;
    for(int i= 0; i < gophers.size(); i++) {
      coord gophCoord = gophers[i];
      for(int j= 0; j < holes.size(); j++) {
	coord holeCoord = holes[j];
	double dist = distSquare(gophCoord, holeCoord);
	if(dist < limit || fabs(limit - dist) < EPS) {
	  adjMat[i+1][j+n+1] = 1;
	  insertOrAdd(i+1, j+n+1);
	  insertOrAdd(j+n+1, i+1);
	}
      }
      adjMat[s][i+1] = 1;
      insertOrAdd(s, i+1);
      insertOrAdd(i+1, s);
    }

    for(int i= 0; i < holes.size(); i++) {
      
      //cout << i+n+1 << ", " << t << " is set to 1" << endl;
      adjMat[i+n+1][t] = 1;
      insertOrAdd(i+n+1, t);
      insertOrAdd(t, i+n+1);
    }

    // cout << "before max_flow: " << endl;
    // for(int i= 0; i <= t; i++) {
    //   for(int j= 0; j <= t; j++)
    // 	cout << adjMat[i][j] << " ";
    //   cout << endl;
    // }

    int max_flow = 0;
    while(true) {
      f= 0;
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
    // for(int i= 0; i <= t; i++) {
    //   for(int j= 0; j <= t; j++)
    // 	cout << adjMat[i][j] << " ";
    //   cout << endl;
    // }

    cout << n - max_flow << endl;

  }
  return 0;
}
