#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>
#define MAXN 200005

using namespace std;

bool has_cat[MAXN];
bool visited[MAXN];
vector<int> adjList[MAXN];
int n, m;
typedef pair<int, int> Node;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    int cat;
    scanf("%d", &cat);
    has_cat[i] = cat == 1;
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  memset(visited, false, sizeof visited);
  stack<Node> s;
  visited[1] = true;
  int cat_n = 0;
  int ans = 0;
  if(has_cat[1])
    cat_n = 1;
  if(cat_n <= m)
    s.push(make_pair(1, cat_n));
  while(!s.empty()) {
    Node u = s.top();
    s.pop();
    bool leaf = true;
    for(int i = 0; i < adjList[u.first].size(); i++) {
      int v = adjList[u.first][i];
      if(visited[v])
	continue;
      leaf = false;
      if(has_cat[v]) {
	if(u.second + 1 <= m) {
	  visited[v] = true;
	  s.push(make_pair(v, u.second + 1));
	}
      } else {
	visited[v] = true;
	s.push(make_pair(v, 0));
      }
    }
    if(leaf)
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
