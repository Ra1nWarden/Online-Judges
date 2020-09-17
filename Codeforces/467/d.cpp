#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int maxn = 100000;
vector<int> adjMat[maxn+5];
int n, m, s;
typedef pair<int, bool> Node;
set<Node> visited;

bool dfs(int u, int depth, map<int, vector<int> >& vis, bool& draw) {
  //printf("dfs visit %d at depth %d\n", u, depth);
  if(adjMat[u].empty()) {
    return (depth & 1);
  }
  for(int i = 0; i < adjMat[u].size(); i++) {
    int v = adjMat[u][i];
    //printf("checking %d\n", v);
    vector<int> path = {};
    if(vis.count(v)) {
      path = vis[v];
    }

    if(!path.empty()) {
      draw = true;
    }

    if(visited.count(make_pair(v, (depth + 1) & 1))) {
      continue;
    }
    
    bool ok = true;
    for(int j = 0; j < path.size(); j++) {
      int len = path[j];
      if((len & 1) == ((depth + 1) & 1)) {
	ok = false;
      }
    }
    
    if(ok) {
      if(vis.count(v)) {
	vis[v].push_back(depth + 1);
      } else {
	vis[v] = {depth + 1};
      }
      visited.insert(make_pair(v, (depth + 1) & 1));
      if(dfs(v, depth + 1, vis, draw)) {
	return true;
      }
      vis[v].pop_back();
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    int cnt;
    scanf("%d", &cnt);
    while(cnt--) {
      int j;
      scanf("%d", &j);
      adjMat[i].push_back(j);
    }
  }
  scanf("%d", &s);
  map<int, vector<int> > vis;
  vis[s] = {0};
  bool draw = false;
  visited.insert(make_pair(s, false));
  if(dfs(s, 0, vis, draw)) {
    printf("Win\n");
    map<int, int> sorted;
    for(map<int, vector<int> >::iterator itr = vis.begin(); itr != vis.end(); itr++) {
      for(int i = 0; i < itr->second.size(); i++) {
	sorted[itr->second[i]] = itr->first;
      }
    }
    bool start = true;
    for(map<int, int>::iterator itr = sorted.begin(); itr != sorted.end(); itr++) {
      if(!start)
	printf(" ");
      printf("%d", itr->second);
      start = false;
    }
    printf("\n");
  } else {
    printf("%s\n", draw ? "Draw" : "Lose");
  }
 
  return 0;
}
