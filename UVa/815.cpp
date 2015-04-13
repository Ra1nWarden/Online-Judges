#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 32
#define EPS 1e-6
#define INF 2e9

using namespace std;

int m, n;
int heights[MAXN][MAXN];
int v;

int main() {
  int kase = 1;
  while(scanf("%d %d", &m, &n) != EOF && (m || n)) {
    int maxh = -1;
    int minh = INF;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
	scanf("%d", &heights[i][j]);
	maxh = max(maxh, heights[i][j]);
	minh = min(minh, heights[i][j]);
      }
    }
    scanf("%d", &v);
    double right = maxh + (double) v / (m * n * 100);
    double left = minh;
    int cover = 0;
    while(fabs(right - left) > EPS) {
      cover = 0;
      double mid = (left + right) / 2;
      //printf("mid is %.2f\n",mid);
      double water = 0;
      for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; j++) {
	  if(mid + EPS > heights[i][j]) {
	    cover++;
	    water += 100 * (mid - heights[i][j]);
	  }
	}
      }
      //printf("water is %.2f\n", water);
      if(water + EPS < v) {
	left = mid;
      } else {
	right = mid;
      }
    }
    printf("Region %d\n", kase++);
    printf("Water level is %.2f meters.\n", left);
    printf("%.2f percent of the region is under water.\n\n", (double) cover / (m * n) * 100);
  }
  return 0;
}
