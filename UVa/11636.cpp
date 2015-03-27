#include <cstdio>
#include <algorithm>
#define INF 2e9

using namespace std;

int main() {
  int n;
  int bits[10005];
  bits[1] = 0;
  for(int i= 2; i <= 10000; i++) {
    int start = i % 2 == 0 ? i / 2 : i / 2 + 1;
    int minval = INF;
    for(int j = start; j < i; j++) {
      minval = min(minval, bits[j]);
    }
    bits[i] = minval + 1;
  }
  int kase = 1;
  while(scanf("%d", &n) != EOF && n >= 0) {
    printf("Case %d: %d\n", kase++, bits[n]);
  }
  return 0;
}
