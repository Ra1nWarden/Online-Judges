#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 300000;
long long prefix[maxn+5];
long long suffix[2][maxn+5];
long long right[2][maxn+5];
long long left[2][maxn+5];
int n;
long long v[2][maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%lld", &v[i][j]);
    }
  }

  memset(prefix, 0, sizeof prefix);
  // prefix
  for(int i = 0; i < n; i++) {
    if(i & 1) {
      // odd
      prefix[i] = (i * 2) * 1LL * v[1][i] + (i * 2 + 1) * 1LL * v[0][i];
    } else {
      // even
      prefix[i] = (i * 2) * 1LL * v[0][i] + (i * 2 + 1) * 1LL * v[1][i];
    }
    if(i)
      prefix[i] += prefix[i-1];
  }

  memset(suffix, 0, sizeof suffix);
  // suffix
  for(int i = n - 1; i >= 0; i--) {
    suffix[0][i] = v[0][i];
    suffix[1][i] = v[1][i];
    if(i+1 < n) {
      suffix[0][i] += suffix[0][i+1];
      suffix[1][i] += suffix[1][i+1];
    }
  }

  memset(left, 0, sizeof left);
  // left
  for(int i = 0; i < 2; i++) {
    for(int j = n - 2; j >=0; j--) {
      left[i][j] = (n - 1 - j) * v[i][j];
      if(j+1 < n) {
	left[i][j] += left[i][j+1];
      }
    }
  }

  memset(right, 0, sizeof right);
  // right
  for(int i = 0; i < 2; i++) {
    for(int j = n - 2; j >= 0; j--) {
      right[i][j] = right[i][j+1] + suffix[i][j+1];
    }
  }

  long long ans = right[0][0] + left[1][0] + n * 1LL * suffix[1][0];
  ans = max(ans, prefix[n-1]);

  for(int i = 0; i < n-1; i++) {
    long long cur = prefix[i] + (i + 1) * 2LL * (suffix[0][i+1] + suffix[1][i+1]);
    if(i & 1) {
      cur += right[0][i+1];
      cur += (n - 1 - i) * 1LL * suffix[1][i+1];
      cur += left[1][i+1];
    } else {
      cur += right[1][i+1];
      cur += (n - 1 - i) * 1LL * suffix[0][i+1];
      cur += left[0][i+1];
    }
    ans = max(ans, cur);
  }

  printf("%lld\n", ans);
  return 0;
}
