#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#define MAXN 4000005
#define INF 2e9

using namespace std;

int n, m, s, t, f;
int adjMat[MAXN][MAXN];
map<int, int> p;
map<int, set<int> > adjList;
vector<string> board;

void initOrAdd(int x1, int y1, int x2, int y2) {
  int x = y1 * m + x1 + 1;
  int y = y2 * m + x2 + 1;
  if(adjList.count(x) == 0) {
    set<int> singleton;
    singleton.insert(y);
    adjList[x] = singleton;
  } else {
    adjList[x].insert(y);
  }
}

void augmenetPath(int v, int minEdge) {
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
  cin >> n >> m;
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++) {
    getline(cin, line);
    board.push_back(line);
  }
  memset(adjMat, -1, sizeof adjMat);
  adjList.clear();
  p.clear();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      
    }
  }

  return 0;
}
