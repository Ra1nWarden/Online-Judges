#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 45
#define PI acos(-1)

using namespace std;

double v[MAXN];
double dp[MAXN][MAXN][MAXN];
int n, m;

double calc(double i, double j, double k) {
  double a = j - i < 0 ? j - i + 1 : j - i;
  double b = k - j < 0 ? k - j + 1 : k - j;
  double c = i - k < 0 ? i - k + 1 : i - k;
  double ans = 0.5 * sin(a * 2 * PI) + 0.5 * sin(b * 2 * PI) + 0.5 * sin(c * 2 * PI);
  return ans;
}

int main() {
  while(scanf("%d%d", &n, &m) != EOF && (n || m)) {
    for(int i = 0; i < n; i++)
      scanf("%lf", &v[i]);
    for(int k = 3; k <= n; k++) {
      for(int i = 0; i + k - 1 < n; i++) {
	for(int j = i + k - 1; j < n; j++) {
	  dp[i][j][k] = 0;
	  if(k == 3) {
	    for(int mid = i + 1; mid < j; mid++) {
	      dp[i][j][3] = max(dp[i][j][3], calc(v[i], v[mid], v[j]));
	    }
	  } else {
	    for(int mid = i + (k - 2); mid < j; mid++) {
	      dp[i][j][k] = max(dp[i][j][k], dp[i][mid][k-1] + calc(v[mid], v[j], v[i]));
	    }
	  }
	}
      }
    }
    double ans = -1;
    for(int i = 0; i + (m - 1) < n; i++) {
      for(int j = i + (m - 1); j < n; j++) {
	ans = max(ans, dp[i][j][m]);
      }
    }
    printf("%6lf\n", ans);
  }
  return 0;
}
