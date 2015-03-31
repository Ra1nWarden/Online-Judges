#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 1005

using namespace std;

int n;
int v[MAXN][2];
double dp[MAXN][MAXN];
bool dpv[MAXN][MAXN];

double dist(int i, int j) {
  return sqrt(pow(v[i-1][0] - v[j-1][0], 2) + pow(v[i-1][1] - v[j-1][1], 2));
}

double f(int i, int j) {
  if(i > j)
    swap(i, j);
  if(dpv[i][j])
    return dp[i][j];
  if(j == n) {
    dpv[i][j] = true;
    return dp[i][j] = dist(i, j);
  }
  dpv[i][j] = true;
  return dp[i][j] = min(f(i, j+1) + dist(j, j+1), f(j, j+1) + dist(i, j+1));
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%d %d", &v[i][0], &v[i][1]);
    memset(dpv, false, sizeof dpv);
    printf("%.2f\n", f(1, 1));
  }
  return 0;
}
