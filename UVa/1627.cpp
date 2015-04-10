#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <cstring>
#include <cmath>
#define MAXN 105

using namespace std;

int n;
bool adjMat[MAXN][MAXN];
vector<int> adjList[MAXN];
bool visited[MAXN];
int dp[MAXN][MAXN];
int take[MAXN][MAXN];

struct CC {
  CC() {
    a.clear();
    b.clear();
  }
  set<int> a, b;
};

vector<CC> v;

typedef pair<int, bool> Node;

bool dfs(int u, CC& c) {
  //printf("dfs from %d\n", u);
  visited[u] = true;
  Node node;
  node.first = u;
  node.second = true;
  c.a.insert(u);
  //printf("%d in group 0\n", u);
  stack<Node> s;
  s.push(node);
  while(!s.empty()) {
    Node next = s.top();
    s.pop();
    for(int i = 0; i < adjList[next.first].size(); i++) {
      int uu = adjList[next.first][i];
      if(!visited[uu]) {
	Node nnode;
	nnode.first = uu;
	nnode.second = !next.second;
	if(nnode.second) {
	  //printf("%d in group 0\n", uu);
	  c.a.insert(uu);
	} else {
	  //printf("%d in group 1\n", uu);
	  c.b.insert(uu);
	}
	visited[uu] = true;
	s.push(nnode);
      } else {
	if(next.second) {
	  // uu should be in b
	  if(c.a.count(uu) != 0)
	    return false;
	} else {
	  // uu should be in a
	  if(c.b.count(uu) != 0)
	    return false;
	}
      }
    }
  }
  return true;
}

int f(int x, int y) {
  // first x component, y items in group 0
  if(dp[x][y] != -1)
    return dp[x][y];
  if(x == v.size()) {
    return dp[x][y] = abs(y - n + y);
  }
  CC next = v[x];
  // take a
  int takea = f(x+1, y + next.a.size());
  int takeb = f(x+1, y + next.b.size());
  if(takea < takeb) {
    take[x][y] = 0;
  } else {
    take[x][y] = 1;
  }
  //printf("dp[%d][%d]=%d\n", x, y, min(takea, takeb));
  return dp[x][y] = min(takea, takeb);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    memset(adjMat, false, sizeof adjMat);
    for(int i = 1; i <= n; i++) {
      int u;
      while(scanf("%d", &u) != EOF) {
	if(u == 0)
	  break;
	adjMat[i][u] = true;
      }
      adjList[i].clear();
    }
    for(int i = 1; i <= n; i++) {
      for(int j = i+1; j <= n; j++) {
	if(!(adjMat[i][j] && adjMat[j][i])) {
	  //printf("%d and %d are connected\n", i, j);
	  adjList[i].push_back(j);
	  adjList[j].push_back(i);
	}
      }
    }
    v.clear();
    memset(visited, false, sizeof visited);
    bool has_solution = true;
    for(int i = 1; i <= n; i++) {
      CC next;
      if(!visited[i]) {
	has_solution = dfs(i, next);
	v.push_back(next);
      }
      if(!has_solution) {
	break;
      }
    }
    if(!has_solution) {
      printf("No solution\n");
      if(tc != 0) {
	printf("\n");
      }
      continue;
    }
    memset(dp, -1, sizeof dp);
    memset(take, -1, sizeof dp);
    f(0, 0);
    vector<int> group0;
    vector<int> group1;
    
    int x = 0;
    int y = 0;
    while(x < v.size()) {
      if(take[x][y] == 0) {
	for(set<int>::iterator itr = v[x].a.begin(); itr != v[x].a.end(); itr++) {
	  group0.push_back(*itr);
	}
	for(set<int>::iterator itr = v[x].b.begin(); itr != v[x].b.end(); itr++) {
	  group1.push_back(*itr);
	}
	y += v[x].a.size();
      } else {
	for(set<int>::iterator itr = v[x].a.begin(); itr != v[x].a.end(); itr++) {
	  group1.push_back(*itr);
	}
	for(set<int>::iterator itr = v[x].b.begin(); itr != v[x].b.end(); itr++) {
	  group0.push_back(*itr);
	}
	y += v[x].b.size();
      }
      x++;
    }


    printf("%d", group0.size());
    for(int i = 0; i < group0.size(); i++)
      printf(" %d", group0[i]);
    printf("\n");
    printf("%d", group1.size());
    for(int i = 0; i < group1.size(); i++)
      printf(" %d", group1[i]);
    printf("\n");
    if(tc != 0) {
      printf("\n");
    }
  }
  return 0;
}
