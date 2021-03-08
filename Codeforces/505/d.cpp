#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 700;
vector<int> dp[maxn+5][maxn+5];
int n;
int v[maxn+5];

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

bool check(int i, int root, int j) {
  if(root > i) {
    bool ok = false;
    for(int each : dp[i][root-1]) {
      if(gcd(each, v[root]) > 1) {
	ok = true;
	break;
      }
    }
    if(!ok)
      return false;
  }
  if(j > root) {
    bool ok = false;
    for(int each : dp[root+1][j]) {
      if(gcd(each, v[root]) > 1) {
	ok = true;
	break;
      }
    }
    if(!ok)
      return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++)
    dp[i][i].push_back(v[i]);
  for(int len = 2; len <= n; len++) {
    for(int i = 0; i + len <= n; i++) {
      for(int root = i; root <= i + len - 1; root++) {
	if(check(i, root, i+len-1)) {
	  dp[i][i+len-1].push_back(root);
	}
      }
    }
  }
  printf("%s\n", dp[0][n-1].empty() ? "No" : "Yes");
  return 0;
}
