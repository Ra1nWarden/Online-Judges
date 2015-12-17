#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
double p;
int n, h;
int pos[maxn+1];
int left[maxn+1];
int right[maxn+1];
double dp[maxn+1][maxn+1][4];

// 00 -> first fall second fall

double f(int a, int b, int s) {
  if(a > b || a < 0 || b >= n || b < 0 || a >= n)
    return 0;
  if(dp[a][b][s] > -1)
    return dp[a][b][s];
  double ans = 0;
  if(s < 2) {
    ans += 0.5 * p * (f(a + 1, b, s & 1) + (a == 0 ? h : min(pos[a] - pos[a - 1], h)));
  } else {
    ans += 0.5 * p * (f(a + 1, b, s & 1) + min(pos[a] - pos[a - 1] - h, h));
  }
  if(s % 2 == 0) {
    ans += 0.5 * (1 - p) * (f(a, b - 1, s & 2) + (b == n - 1 ? h : min(pos[b + 1] - pos[b], h)));
  } else {
    ans += 0.5 * (1 - p) * (f(a, b - 1, s & 2) + min(pos[b + 1] - pos[b] - h, h));
  }
  int c = min(b + 1, right[a]);
  //printf("1 a=%d b=%d s=%d c=%d\n", a, b, s, c);
  if(c == b + 1 && s % 2) {
    ans += 0.5 * (1 - p) * (pos[c - 1] - pos[a] + min(h, pos[c] - pos[c - 1] - h));
  } else {
    ans += 0.5 * (1 - p) * (pos[c - 1] - pos[a] + (c < n ? min(h, pos[c] - pos[c - 1]) : h) + f(c, b, s | 2));
  }
  c = max(a - 1, left[b]);
  //printf("2 a=%d b=%d s=%d c=%d\n", a, b, s, c);
  if(c == a - 1 && s >= 2) {
    ans += 0.5 * p * (pos[b] - pos[c + 1] + min(pos[c + 1] - pos[c] - h, h));
  } else {
    ans += 0.5 * p * (pos[b] - pos[c + 1] + (c >= 0 ? min(h, pos[c + 1] - pos[c]) : h) + f(a, c, s | 1));
  }
  return dp[a][b][s] = ans;
}

int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d%lf", &n, &h, &p);
  for(int i = 0; i < n; i++)
    scanf("%d", &pos[i]);
  sort(pos, pos+n);
  int idx = -1;
  left[0] = -1;
  for(int i = 1; i < n; i++) {
    if(pos[i] - pos[i-1] >= h) {
      idx = i - 1;
    }
    left[i] = idx;
  }
  idx = n;
  right[n-1] = n;
  for(int i = n - 2; i > -1; i--) {
    if(pos[i+1] - pos[i] >= h) {
      idx = i + 1;
    }
    right[i] = idx;
  }
  printf("%.8lf\n", f(0, n-1, 0));
  return 0;
}
