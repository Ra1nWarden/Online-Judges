#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 105
#define INF 2e9

using namespace std;

double v[MAXN];
double dp[MAXN][MAXN];
bool dpv[MAXN][MAXN];
int n, w;

double f(int l, int g) {
  //printf("calling f(%d, %d)\n", l, g);
  if(dpv[l][g])
    return dp[l][g];
  if(g > l) {
    dpv[l][g] = true;
    return dpv[l][g] = INF;
  }
  if(g == 1) {
    double sum = 0.0;
    for(int i = 0; i < l; i++) {
      sum += v[i];
    }
    dpv[l][g] =true;
    return dp[l][g] = sum * l;
  }
  double ans = INF;
  double sum = 0.0;
  for(int i = g - 1; i < l; i++)
    sum += v[i];
  for(int i = g - 1; i < l; i++) {
    double subres = f(i, g - 1);
    subres += sum * l;
    ans = min(ans, subres);
    sum -= v[i];
  }
  dpv[l][g] = true;
  return dp[l][g] = ans;
}

bool _cmp(double a, double b) {
  return a > b;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &w);
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
      scanf("%lf", &v[i]);
      sum += v[i];
    }
    for(int i = 0; i < n; i++) {
      v[i] /= sum;
    }
    sort(v, v+n, _cmp);
    memset(dpv, false, sizeof dpv);
    printf("%.4f\n", f(n, w));
  }
  return 0;
}
