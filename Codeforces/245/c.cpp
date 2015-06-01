#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#define MAXN 100005

using namespace std;

map<int, vector<int> > adjList;
int n;
bool visited[MAXN];
bool change[MAXN];

struct Node {
  Node(int a, int b, int c) {
    n = a;
    e = b;
    o = c;
  }
  int n, e, o;
};

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n -1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    int bit;
    scanf("%d", &bit);
    change[i] = bit;
  }
  for(int i = 1; i <= n; i++) {
    int bit;
    scanf("%d", &bit);
    if((change[i] && bit == 1) || (!change[i] && bit == 0))
      change[i] = false;
    else
      change[i] = true;
  }
  memset(visited, false, sizeof visited);
  queue<Node> q;
  q.push(Node(1, 0, 0));
  visited[1] = true;
  vector<int> ans;
  while(!q.empty()) {
    Node next = q.front();
    q.pop();
    int u = next.n;
    bool flip = false;
    if((change[u] && next.e % 2 == 0) || (!change[u] && next.e % 2 == 1)) {
      ans.push_back(u);
      flip = true;
    }
    for(int i = 0; i < adjList[u].size(); i++) {
      int v = adjList[u][i];
      if(!visited[v]) {
	visited[v] = true;
	q.push(Node(v, next.o, flip ? next.e + 1 : next.e));
      }
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++)
    printf("%d\n", ans[i]);
  return 0;
}
