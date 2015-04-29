#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 205

using namespace std;

bool visited[MAXN][MAXN];
int cap[3];
int ans[MAXN];

struct Node {
  int v[3], dist;
  bool operator<(const Node& rhs) const {
    return dist > rhs.dist;
  }
};

void update_ans(const Node& u) {
  for(int i = 0; i < 3; i++) {
    int d = u.v[i];
    if(ans[d] < 0)
      ans[d] = u.dist;
  }
}

void solve(int a, int b, int c, int d) {
  priority_queue<Node> pq;
  Node start;
  start.dist = 0;
  start.v[0] = 0;
  start.v[1] = 0;
  start.v[2] = c;
  pq.push(start);
  while(!pq.empty()) {
    Node u = pq.top();
    pq.pop();
    update_ans(u);
    if(ans[d] >= 0)
      break;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++){
	if(i != j) {
	  if(u.v[i] == 0 || u.v[j] == cap[j])
	    continue;
	  int amt = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
	  Node u2;
	  memcpy(&u2, &u, sizeof u);
	  u2.dist = u.dist + amt;
	  u2.v[i] -= amt;
	  u2.v[j] += amt;
	  if(!visited[u2.v[0]][u2.v[1]]) {
	    visited[u2.v[0]][u2.v[1]] = true;
	    pq.push(u2);
	  }
	}
      }
    }
  }
  while(d >= 0) {
    if(ans[d] >= 0) {
      printf("%d %d\n", ans[d], d);
      break;
    }
    d--;
  }
}

int main() {
  int tc, a, b, c, d;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    cap[0] = a;
    cap[1] = b;
    cap[2] = c;
    memset(visited, false, sizeof visited);
    memset(ans, -1, sizeof ans);
    solve(a, b, c, d);
  }
  return 0;
}
