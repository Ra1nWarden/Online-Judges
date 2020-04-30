#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 30000;
const int sqrtn = 170;

int v[maxn+5];
int vv[maxn+5];
int ra[maxn+5];
int dp[maxn/sqrtn+5][maxn+5];
int n, q;

int main() {
  scanf("%d", &n);
  map<int, queue<int> > index;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    vv[i] = v[i];
    if(index.count(v[i])) {
      index[v[i]].push(i);
    } else {
      queue<int> q;
      q.push(i);
      index[v[i]] = q;
    }
  }

  sort(vv+1, vv+n+1);
  for(int i = 1; i <= n; i++) {
    ra[i] = index[vv[i]].front();
    index[vv[i]].pop();
  }

  memset(dp, 0, sizeof dp);

  for(int i = 1; i <= n; i++) {
    dp[i/sqrtn][ra[i]]++;
  }

  for(int i = 0; i <= n/sqrtn; i++) {
    for(int j = 1; j <= n; j++) {
      dp[i][j] += dp[i][j-1];
    }
  }

  scanf("%d", &q);

  while(q--) {
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    int idx = upper_bound(vv+1, vv+n+1, k) - vv;
    int ans = 0;
    for(int cur = idx; cur / sqrtn == idx / sqrtn; cur++) {
      if(ra[cur] >= i && ra[cur] <= j)
	ans++;
    }
    for(int blk = idx / sqrtn + 1; blk <= n/sqrtn; blk++) {
      ans += dp[blk][j] - dp[blk][i-1];
    }
    printf("%d\n", ans);
  }

  return 0;
}
