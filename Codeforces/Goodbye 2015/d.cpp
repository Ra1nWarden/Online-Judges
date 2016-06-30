#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 5000;
int n;
char digits[maxn+5];
const int mod = 1000000007;
const int inf = 2000000000;
int dp[maxn+1][maxn+1];
int diff[maxn+1][maxn+1];

int g(int prev, int start) {
  if(diff[prev][start] != -1)
    return diff[prev][start];
  if(start == n) {
    return diff[prev][start] = inf;
  }
  if(digits[prev] == digits[start])
    return diff[prev][start] = g(prev+1, start+1) + 1;
  else
    return diff[prev][start] = 0;
}

int f(int prev, int start) {
  //printf("calling f(%d, %d)\n", prev, start);
  if(dp[prev][start] != -1)
    return dp[prev][start];
  if(start == n)
    return dp[prev][start] = 1;
  if(n - start < start - prev)
    return dp[prev][start] = 0;
  if(digits[start] == '0')
    return dp[prev][start] = 0;
  int ans = 0;
  int diff_idx = g(prev, start);
  bool larger = false;
  if(diff_idx < start - prev) {
    larger = digits[start + diff_idx] > digits[prev + diff_idx];
  }
  if(larger || n - start > start - prev)
    ans++;
  for(int new_start = larger ? start + start - prev : start + start - prev + 1; n - new_start >= new_start - start ; new_start++) {
    ans = ((long long) ans + (long long) f(start, new_start)) % mod;
  }
  return dp[prev][start] = ans;
}

int main() {
  scanf("%d\n", &n);
  scanf("%s", digits);
  memset(dp, -1, sizeof dp);
  memset(diff, -1, sizeof diff);
  printf("%d\n", f(0, 0));
  return 0;
}
