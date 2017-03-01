#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000;
char str[maxn+5];
int n;
const int alpha = 26;
int v[alpha+5];
const int mod = 1e9+7;
int dp[maxn+5];

int calc1() {
  dp[0] = 1;
  for(int i = 1; i < n; i++) {
    int ans = 0;
    int len = maxn;
    for(int j = i; j >= 0; j--) {
      int c = str[j] - 'a';
      len = min(len, v[c]);
      if(i - j + 1 <= len) {
	if(j)
	  ans = (ans + dp[j - 1]) % mod;
	else
	  ans = (ans + 1) % mod;
      }
    }
    dp[i] = ans;
  }
  return dp[n-1];
}

int calc2() {
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int len = maxn;
    for(int j = i; j < n; j++) {
      int c = str[j] - 'a';
      len = min(len, v[c]);
      if(j - i + 1 <= len) {
	ans = max(ans, j - i + 1);
      } else {
	break;
      }
    }
  }
  return ans;
}

int calc3() {
  int ans = 0;
  int idx = 0;
  int l = 0;
  int len = maxn;
  while(idx < n) {
    int c = str[idx] - 'a';
    l++;
    len = min(len, v[c]);
    if(l > len) {
      ans++;
      l = 1;
      len = v[c];
    }
    idx++;
  }
  return ans + 1;
}

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", str);
  for(int i = 0; i < alpha; i++) {
    scanf("%d", &v[i]);
  }
  printf("%d\n", calc1());
  printf("%d\n", calc2());
  printf("%d\n", calc3());
  return 0;
}
