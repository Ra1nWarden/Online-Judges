#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 30005

using namespace std;

int dp[MAXN][500];
int gem[MAXN];
int d;

int f(int x, int y) {
  if(dp[x][y] != -1)
    return dp[x][y];
  int res = gem[x];
  int step = y - 250 + d;
  if(step - 1 > 0  && x + step - 1 <= 30000) {
    res = max(res, gem[x] + f(x+step-1, y-1));
  }
  if(x + step <= 30000) {
    res = max(res, gem[x] + f(x+step, y));
  }
  if(x+step+1 <= 30000) {
    res = max(res, gem[x] + f(x+step+1, y+1));
  }
  return dp[x][y] = res;
}

int main() {
  int n;
  scanf("%d %d", &n, &d);
  memset(gem, 0, sizeof gem);
  for(int i = 0; i < n; i++) {
    int index;
    scanf("%d", &index);
    gem[index]++;
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", f(d, 250));
  return 0;
}
