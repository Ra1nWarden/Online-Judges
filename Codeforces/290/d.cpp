#include <map>
#include <cstdio>
#define MAXN 301

using namespace std;

typedef pair<int, int> ii;

int n;
ii v[MAXN];
map<int, int> dp;

int gcd(int x, int y) {
  if(y == 0)
    return x;
  else if(x == 0)
    return y;
  else
    return gcd(y, x % y);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i].first);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i].second);
  dp[0] = 0;
  for(int i = 0; i < n; i++) {
    map<int, int>::iterator itr;
    for(itr = dp.begin(); itr != dp.end(); itr++) {
      int temp = gcd(itr->first, v[i].first);
      if(dp.count(temp) == 0)
	dp[temp] = itr->second + v[i].second;
      else
	dp[temp] = min(dp[temp], itr->second + v[i].second);
    }
  }
  if(dp.count(1) == 0)
    printf("-1\n");
  else
    printf("%d\n", dp[1]);
  return 0;
}
