#include <cstdio>
#include <algorithm>

using namespace std;

int x1, x2, x3, x4, y1, y2, y3, y4, n, m;

long long calc() {
  if(x3 > x2 || x4 < x1 || y3 > y2 || y4 < y1)
    return 0;
  int x5 = min(x4, x2);
  int x6 = max(x3, x1);
  int y5 = min(y4, y2);
  int y6 = max(y3, y1);
  long long black = (x5 - x6 + 1) * 1LL * (y5 - y6 + 1);
  if(black & 1LL) {
    black /= 2;
    if((x5 + y5) & 1LL)
      black++;
  } else {
    black /= 2;
  }
  return black;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    long long black = n * 1LL * m / 2;
    long long black_sub = (x2 - x1 + 1) * 1LL * (y2 - y1 + 1);
    if(black_sub & 1LL) {
      black_sub /= 2;
      if((x1 + y1) & 1LL) {
	black_sub++;
      }
    } else {
      black_sub /= 2;
    }
    black -= black_sub;
    long long black_add = (x4 - x3 + 1) * 1LL * (y4 - y3 + 1);
    if(black_add & 1LL) {
      black_add /= 2;
      if(!((x3 + y3) & 1LL)) {
	black_add++;
      }
    } else {
      black_add /= 2;
    }
    black += black_add;
    black += calc();
    printf("%lld %lld\n", n * 1LL * m - black, black);
  }
  return 0;
}
