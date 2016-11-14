#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 500;
int n, k;
bool dp[2][maxn+5][maxn+5];
int v[maxn+5];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  memset(dp, false, sizeof dp);
  dp[0][0][0] = true;
  for(int i = 1; i <= n; i++) {
    int ii = i&1;
    int hh = ii^1;
    for(int j = 0; j <= k; j++) {
      for(int kk = 0; kk <= j; kk++) {
	bool ok = dp[hh][j][kk];
	if(j >= v[i-1]) {
	  ok = ok || dp[hh][j-v[i-1]][kk];
	  if(kk >= v[i-1])
	    ok = ok || dp[hh][j-v[i-1]][kk-v[i-1]];
	}
	dp[ii][j][kk] = ok;
      }
    }
  }
  int ii = n & 1;
  vector<int> ans;
  for(int kk = 0; kk <= k; kk++) {
    if(dp[ii][k][kk]) {
      ans.push_back(kk);
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
