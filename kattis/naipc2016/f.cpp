#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxl = 10000;
const int mod = 1000000007;
int dp[maxl+5][maxn+5];
bool visited[maxl+5][maxn+5];
int n, w, h;

int f(int a, int b) {
  if(visited[a][b]) {
    return dp[a][b];
  }
  if(b == 0) {
    return 1;
  }
  if(b == 1) {
    return min(h + 1, a + 1);
  }
  int ans = 0;
  for(int c = 0; c <= h; c++) {
    if(a < c)
      break;
    ans = ((long long) f(a - c, b - 1) + ans) % mod;
  }
  visited[a][b] = true;
  return dp[a][b] = ans;
}

int main() {
  scanf("%d%d%d", &n, &w, &h);
  memset(visited, false, sizeof visited);
  printf("%d\n", ((long long) f(n, w)  + mod - (min(n / w, h) + 1)) % mod);
  return 0;
}
