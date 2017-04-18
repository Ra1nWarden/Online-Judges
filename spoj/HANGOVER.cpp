#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const int maxn = 300;
double len[maxn+5];

void init() {
  len[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    len[i] = len[i-1] + (1.0 / (i + 1));
  }
}

int main() {
  init();
  double l;
  while(scanf("%lf", &l)) {
    if(fabs(l - 0) < eps) {
      break;
    }
    int ans = lower_bound(len+1, len+maxn, l) - len;
    printf("%d card(s)\n", ans);
  }
  return 0;
}
