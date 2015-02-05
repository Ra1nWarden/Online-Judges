#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#define INF 2e8
#define EPS 1e-20

using namespace std;

typedef pair<int, int> coord;

int adjMat[202][202];
map<int, vector<int> > adjList;
int s, t, f;
map<int, int> p;

double caldistance(coord a, coord b) {
  return sqrt((double) (a.first - b.first) * (double) (a.first - b.first)  + (double) (a.second - b.second) * (double) (a.second - b.second));
}

void insertOrAdd(int a, int b) {
  if(adjList.count(a) == 0) {
    vector<int> singleton;
    singleton.push_back(b);
    adjList[a] = singleton;
  } else
    adjList[a].push_back(b);
}

void augmentPath(int u, int minEdge) {
  if(u == s) {
    f = minEdge;
    return;
  } else if(p.count(u)) {
    augmentPath(p[u], adjMat[p[u]][u]);
    adjMat[p[u]][u] -= f;
    adjMat[u][p[u]] += f;
  }
}

ostream& operator<<(ostream& oss, const coord& c) {
  oss << c.first << " " << c.second;
  return oss;
}

int main() {
  int tc;
  cin >> tc;
  bool init = true;
  while(tc--) {
    if(!init)
      cout << endl;
    p.clear();
    adjList.clear();
    memset(adjMat, 0, sizeof adjMat);
    int n, m;
    cin >> n >> m;
    s = 0;
    t = m+n+1;
    vector<coord> bob;
    map<coord, int> indexMap;
    int runningIndex = 1;
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      bob.push_back(make_pair(x, y));
      indexMap[make_pair(x, y)] = runningIndex++;
    }
    vector<coord> interest;
    for(int j = 0; j < m; j++) {
      int x, y;
      cin >> x >> y;
      interest.push_back(make_pair(x, y));
      indexMap[make_pair(x, y)] = runningIndex++;
    }
    for(int i= 0; i < bob.size() - 1; i++) {
      coord start = bob[i];
      coord end = bob[i+1];
      double dist = caldistance(start, end);
      for(int j = 0; j < interest.size(); j++) {
	coord next = interest[j];
	double newDist = caldistance(start, next) + caldistance(next, end);
	//cout << newDist << " vs " << dist << endl;
	if(dist + dist >= newDist || fabs(dist + dist - newDist) < EPS) {
	  //cout << "connecting " << indexMap[start] << " with " << indexMap[next] << endl;
	  adjMat[indexMap[start]][indexMap[next]] = 1;
	  //adjMat[indexMap[next]][indexMap[start]] = 0;
	  insertOrAdd(indexMap[start], indexMap[next]);
	  insertOrAdd(indexMap[next], indexMap[start]);
	}
      }
    }
    
    for(int i= 1; i <= n; i++) {
      adjMat[s][i] = 1;
      //adjMat[i][0] = 0;
      insertOrAdd(s, i);
      insertOrAdd(i, s);
    }
    
    for(int j = n+1; j <= n+m; j++) {
      adjMat[j][t] = 1;
      //adjMat[m+n+1][j] = 0;
      insertOrAdd(j, t);
      insertOrAdd(t, j);
    }

    // for(int i = 0; i <= m+n+1; i++) {
    //   for(int j= 0; j <= m+n+1; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int max_flow = 0;
    while(true) {
      f = 0;
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
	    q.push(v);
	    p[v] = u;
	  }
	}
      }

      augmentPath(t, INF);
      if(f == 0)
	break;
      max_flow += f;
    }

    // cout << "after max flow: " << endl;
    
    // for(int i = 0; i <= m+n+1; i++) {
    //   for(int j= 0; j <= m+n+1; j++) {
    // 	cout << adjMat[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    
    vector<coord> result;
    for(int i= 0; i< bob.size(); i++) {
      coord next = bob[i];
      result.push_back(next);
      vector<int> nextAdj = adjList[indexMap[next]];
      for(int j = 0; j < nextAdj.size(); j++) {
	if(adjMat[indexMap[next]][nextAdj[j]] == 0 && adjMat[nextAdj[j]][indexMap[next]] == 1 && nextAdj[j] != s) {
	  result.push_back(interest[nextAdj[j] - n - 1]);
	  break;
	}
      }
    }

    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
      if(i != 0)
	cout << " ";
      cout << result[i].first << " " << result[i].second;
    }
    cout << endl;
    init = false;
    //cout << endl;
  }
  return 0;
}
