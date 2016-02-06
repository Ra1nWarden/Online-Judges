#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 20;
const int maxm = 100;
bool ok[maxn * maxm +5];
int v[maxn];
int n;

void init(int sum) {
  memset(ok, false, sizeof ok);
  for(int i = 0; i < n; i++) {
    queue<int> q;
    int cur = v[i];
    if(!ok[cur])
      q.push(cur);
    for(int m = 0; m <= sum; m++) {
      if(ok[m]) {
	if(m + cur <= sum && !ok[m + cur])
	  q.push(m + cur);
	if(m - cur >= 0 && !ok[m - cur])
	  q.push(m - cur);
      }
    }
    while(!q.empty()) {
      ok[q.front()] = true;
      q.pop();
    }
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    init(sum);
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
      int q;
      scanf("%d", &q);
      bool ans = false;
      if(q <= maxm * maxn)
	ans = ok[q];
      printf("%s\n", ans ? "YES" : "NO");
    }
  }
  return 0;
}
