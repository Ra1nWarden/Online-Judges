#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 200;
const int maxk = 10;
const int inf = 1000000000;

bool v[maxn+1][maxk+1][maxk+1][3];
int dp[maxn+1][maxk+1][maxk+1][3];
int n, k;
int vv[maxn+1];

int f(int idx, int up, int down, int state) {
  if(v[idx][up][down][state]) {
    return dp[idx][up][down][state];
  }
  if(idx == n) {
    v[idx][up][down][state] = true;
    if(up == down && state) {
      return dp[idx][up][down][state] = 0;
    } else {
      return dp[idx][up][down][state] = -inf;
    }
  }
  int ret = -inf;
  if(state == 0) {
    ret = max(ret, f(idx+1, up+1, down, 1));
    ret = max(ret, f(idx+1, up, down, 0));
    ret = max(ret, f(idx+1, up, down, 1) + vv[idx]);
    if(down < k) {
      ret = max(ret, f(idx+1, up, down+1, 0) + vv[idx]);
    }
  } else if(state == 1) {
    ret = max(ret, f(idx+1, up, down, 2));
    ret = max(ret, f(idx+1, up, down, 1) + vv[idx]);
    if(up < k) {
      ret = max(ret, f(idx+1, up+1, down, 1));
    }
  } else {
    ret = max(ret, f(idx+1, up, down, 2));
    if(down < k) {
      ret = max(ret, f(idx+1, up, down+1, 2) + vv[idx]);
    }
  }
  v[idx][up][down][state] = true;
  return dp[idx][up][down][state] = ret;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &vv[i]);
  }
  memset(v, false, sizeof v);
  printf("%d\n", f(0, 0, 0, 0));
  return 0;
}
