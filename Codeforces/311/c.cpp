#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 205
#define MAXL 100005
#define INF 1000000000

using namespace std;

typedef pair<int, int> II;
int cnt[MAXN];
int buffer[MAXN];
II legs[MAXL];
int dp[2];
int n;
int cnt_sum;

bool _cmp(const II& a, const II& b) {
  if(a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int calc(int prev_sum, int more_half) {
  int ans = 0;
  int cost_i = 1;
  while(prev_sum >= more_half) {
    if(cnt[cost_i] != 0) {
      if(prev_sum - cnt[cost_i] >= more_half) {
	prev_sum -= cnt[cost_i];
	ans += cnt[cost_i] * cost_i;
      } else {
	ans += cost_i * (prev_sum - more_half + 1);
	break;
      }
    }
    cost_i++;
  }
  return ans;
}

int main() {
  dp[0] = dp[1] = INF;
  scanf("%d",&n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &legs[i].first);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &legs[i].second);
  }
  sort(legs, legs+n, _cmp);
  memset(cnt, 0, sizeof cnt);
  int prev = -1;
  int dpi = 0;
  cnt_sum = 0;
  for(int i = 0; i < n; i++) {
    if(legs[i].first != prev) {
      memset(buffer, 0, sizeof buffer);
      int remove_sum = 0;
      prev = legs[i].first;
      int add_cnt = 0;
      while(i < n && legs[i].first == prev) {
	remove_sum += legs[i].second;
	buffer[legs[i].second]++;
	i++;
	add_cnt++;
      }
      i--;
      int dpc = dpi^1;
      dp[dpi] = min(dp[dpc] + remove_sum, calc(cnt_sum, add_cnt));
      dpi = dpc;
      cnt_sum += add_cnt;
      for(int j = 1; j <= 200; j++) {
	cnt[j] += buffer[j];
      }
    }
  }
  printf("%d\n", dp[dpi^1]);
  return 0;
}
