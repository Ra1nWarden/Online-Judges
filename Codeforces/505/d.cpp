#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 700;
int v[maxn+5];
bool dp[maxn+5][maxn+5][2];
int n;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  memset(dp, false, sizeof dp);
  for(int i = 0; i < n; i++) {
    if(i) {
      dp[i][i][0] |= gcd(v[i], v[i-1]) > 1;
    }
    if(i < n-1) {
      dp[i][i][1] |= gcd(v[i], v[i+1]) > 1;
    }
  }
  for(int len = 2; len < n; len++) {
    for(int i = 0; i + len <= n; i++) {
      for(int root = i; root < i + len; root++) {
	if(root > i && !dp[i][root-1][1]) {
	  continue;
	}
	if(root < i + len - 1 && !dp[root+1][i+len-1][0]) {
	  continue;
	}
	if(i) {
	  dp[i][i+len-1][0] |= gcd(v[root], v[i-1]) > 1;
	}
	if(i + len - 1 < n - 1) {
	  dp[i][i+len-1][1] |= gcd(v[root], v[i+len]) > 1;
	}
	if(dp[i][i+len-1][0] && dp[i][i+len-1][1]) {
	  break;
	}
      }
    }
  }
  bool ok = false;
  for(int root = 0; root < n; root++) {
    bool left = root == 0 || dp[0][root-1][1];
    bool right = root == n - 1 || dp[root+1][n-1][0];
    if(left && right) {
      ok = true;
      break;
    }
  }
  printf("%s\n", ok ? "Yes" : "No");
  return 0;
}
