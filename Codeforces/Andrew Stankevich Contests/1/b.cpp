#include <fstream>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#define INF 2e8

using namespace std;

typedef long long LL;

LL adjMat[202][202];
LL adjMatOrig[202][202];
map<int, set<int> > adjList;

map<LL, LL> p;
LL f, s, t;

void augmentPath(LL v, LL minEdge) {
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

void insertOrAdd(int u, int v) {
  if(adjList.count(u) == 0) {
    set<int> singleton;
    singleton.insert(v);
    adjList[u] = singleton;
  } else
    adjList[u].insert(v);
}

int main() {
  LL n, m;
  ifstream ifs("cooling.in");
  ofstream ofs("cooling.out");
  ifs >> n >> m;
  s = 0;
  t = n + 1;
  LL required = 0;
  memset(adjMat, 0, sizeof adjMat);
  vector<pair<LL, LL> > edges;
  vector<LL> minV;
  for(LL i= 0; i < m; i++) {
    LL x, y, b, c;
    ifs >> x >> y >> b >> c;
    required += b;
    edges.push_back(make_pair(x, y));
    minV.push_back(b);
    adjMat[x][y] += (c - b);
    //adjMat[y][x] = 0;
    insertOrAdd(x, y);
    insertOrAdd(y, x);
    adjMat[s][y] += b;
    insertOrAdd(s, y);
    //adjList[y][s] = true;
    //adjMat[y][s] = 0;
    adjMat[x][t] += b;
    insertOrAdd(x, t);
    //adjList[t][x] = true;
    //adjMat[t][x] = 0;
  }
  memcpy(adjMatOrig, adjMat, sizeof adjMat);
  LL max_flow = 0;
  while(true) {
    f = 0;
    queue<LL> q;
    map<LL, LL> dist;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
      LL u = q.front(); 
      q.pop();
      if(u == t)
	break;

      for(set<int>::iterator itr = adjList[u].begin(); itr != adjList[u].end(); itr++) {
	int v = *itr;
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
  

  if(max_flow < required)
    ofs << "NO" << endl;
  else {
    ofs << "YES" << endl;
    for(LL i= 0; i < edges.size(); i++) {
      LL x = edges[i].first;
      LL y = edges[i].second;
      ofs << minV[i] + abs(adjMatOrig[x][y] - adjMat[x][y]) << endl;
    }
  }
  ifs.close();
  ofs.close();
  
  return 0;
}
