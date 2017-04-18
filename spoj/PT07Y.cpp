#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 10000;
vector<int> adjMat[maxn+5];
bool visited[maxn+5];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if(m != n - 1) {
    printf("NO\n");
    return 0;
  }
  int u, v;
  for(int i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    adjMat[u].push_back(v);
    adjMat[v].push_back(u);
  }
  memset(visited, false, sizeof visited);
  stack<int> s;
  s.push(1);
  int total = 0;
  visited[1] = true;
  total++;
  while(!s.empty()) {
    int u = s.top();
    s.pop();
    for(int i = 0; i < adjMat[u].size(); i++) {
      int v = adjMat[u][i];
      if(!visited[v]) {
	s.push(v);
	total++;
	visited[v] = true;
      }
    }
  }
  printf("%s\n", total == n ? "YES" : "NO");
  return 0;
}
