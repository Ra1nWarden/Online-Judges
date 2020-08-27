#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int cv[maxn+5];
int iv[maxn+5];
int dp[maxn+5][20];
int n, ii;

void init_rmq() {
  for(int i = 0; i < ii; i++) {
    dp[i][0] = cv[i];
  }
  for(int j = 1; (1 << j) <= ii; j++) {
    for(int i = 0; i + (1 << j) - 1 < ii; i++) {
      dp[i][j] = max(dp[i][j-1], dp[i+(1 << (j-1))][j-1]);
    }
  }
}

int rmq_query(int l, int r) {
  int k = 0;
  while((1 << (k+1)) <= r - l + 1)
    k++;
  return max(dp[l][k], dp[r - (1<<k) + 1][k]);
}

int main() {
  int q;
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    scanf("%d", &q);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }

    ii = 0;
    iv[ii++] = 0;
    for(int i = 1; i < n; i++) {
      if(v[i] != v[i-1]) {
	iv[ii++] = i;
      }
    }
    
    for(int i = 0; i < ii - 1; i++) {
      cv[i] = iv[i+1] - iv[i];
    }
    cv[ii-1] = n - iv[ii-1];
    
    init_rmq();
    
    int l, r;
    while(q--) {
      scanf("%d%d", &l, &r);
      l--, r--;
      int ri = upper_bound(iv, iv + ii, r) - iv;
      int li = upper_bound(iv, iv + ii, l) - iv;
      int ans;
      if(li == ri) {
	ans = r - l + 1;
      } else {
	ans = max(iv[li] - l, r - iv[ri-1] + 1);
	if(li < ri - 1) {
	  ans = max(ans, rmq_query(li, ri-2));
	}
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
