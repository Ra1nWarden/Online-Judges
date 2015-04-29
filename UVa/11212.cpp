#include <cstdio>
#include <cstring>
#define MAXN 10

using namespace std;

int n, a[MAXN], maxd;

bool sorted() {
  for(int i = 0; i < n; i++)
    if(a[i] != i+1)
      return false;
  return true;
}

int h() {
  int ans = 0;
  for(int i = 0; i < n - 1; i++) {
    if(a[i] + 1 != a[i+1])
      ans++;
  }
  return ans;
}

bool dfs(int d) {
  if(d > maxd)
    return false;
  if((maxd - d) * 3 < h())
    return false;
  if(sorted())
    return true;
  
  int seg[MAXN], acpy[MAXN];
  memcpy(acpy, a, sizeof a);
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int si = 0;
      for(int k = 0; k < n; k++) {
	if(k < i || k > j)
	  seg[si++] = acpy[k];
      }
      for(int k = 0; k <= si; k++) {
	int ai = 0;
	for(int l = 0; l < k; l++)
	  a[ai++] = seg[l];
	for(int l = i; l <= j; l++)
	  a[ai++] = acpy[l];
	for(int l = k; l < si; l++)
	  a[ai++] = seg[l];
	if(dfs(d+1))
	  return true;
      }
    }
  }
  return false;
}

int solve() {
  for(maxd = 0; maxd <= n; maxd++) {
    if(dfs(0))
      return maxd;
  }
  return n;
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i =0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    printf("Case %d: %d\n", kase++, solve());
  }
  return 0;
}
