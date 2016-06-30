#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 1030;
double v[2][maxl];

int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  int len = 1;
  v[0][0] = t;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    memset(v[(i&1)^1], 0, sizeof(double) * maxl);
    for(int j = 0; j < len; j++) {
      if(v[i&1][j] >= 1) {
	ans++;
	double left = v[i&1][j] - 1;
	v[(i&1)^1][j] += left / 2;
	v[(i&1)^1][j+1] += left / 2;
      }
    }
    len = len << 1;
  }
  printf("%d\n", ans);
  return 0;
}
