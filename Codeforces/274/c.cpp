#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#define MAXN 5005

using namespace std;

typedef pair<int, int> II;
int n;

II v[MAXN];
int dp[MAXN][2];

bool _cmp(const II& a, const II& b) {
  if(a.first != b.first)
    return a.first < b.first;
  return a.second < b.second;
}

int f(int l, int day) {
  if(dp[l][day] != -1)
    return dp[l][day];
  if(l == 1)
    return dp[l][day] = 1;
  else {
    int time = day ? v[l-1].second : v[l-1].first;
    if(time < v[l-2].second && time < v[l-2].first)
      return dp[l][day] = 0;
    dp[l][day] = 0;
    if(time >= v[l-2].second)
      dp[l][day] = f(l-1, 1);
    if(dp[l][day])
      return dp[l][day];
    if(time >= v[l-2].first)
      return dp[l][day] = f(l-1, 0);
    else
      return dp[l][day] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d %d", &v[i].first, &v[i].second);
  sort(v, v+n, _cmp);
  memset(dp, -1, sizeof dp);
  if(f(n, 1))
    printf("%d\n", v[n-1].second);
  else
    printf("%d\n", v[n-1].first);
  return 0;
}
