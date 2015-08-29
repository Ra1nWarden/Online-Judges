#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 100005

using namespace std;

typedef pair<int, int> Node;
int v[MAXN];
int n;
int maxval;
int sm[MAXN];
int m[MAXN];
int vis[MAXN];

int main() {
  memset(m, 0, sizeof m);
  memset(sm, 0, sizeof sm);
  memset(vis, -1, sizeof vis);
  maxval = -1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    maxval = max(maxval, v[i]);
  }
  for(int i = 0; i < n; i++) {
    int num = v[i];
    m[num]++;
    queue<Node> q;
    q.push(make_pair(num, 0));
    vis[num] = i;
    while(!q.empty()) {
      Node u = q.front();
      q.pop();
      int number = u.first;
      int step = u.second;
      if((number << 1) <= maxval && vis[number << 1] != i) {
	vis[number << 1] = i;
	m[number << 1]++;
	sm[number << 1] += step + 1;
	q.push(make_pair(number << 1, step + 1));
      }
      if(vis[number >> 1] != i) {
	vis[number >> 1] = i;
	m[number >> 1]++;
	sm[number >> 1] += step + 1;
	q.push(make_pair(number >> 1, step + 1));
      }
    }
  }
  int ans = 1000000000;
  for(int i = 0; i <= maxval; i++) {
    if(m[i] == n) {
      ans = min(ans, sm[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
