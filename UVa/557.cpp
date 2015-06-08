#include <cstdio>
#include <cstring>
#define MAXN 50005

using namespace std;

double ans[MAXN];

int main() {
  ans[0] = 1;
  for(long long i = 1; i < 50000; i++) {
    ans[i] = 0.25 * ans[i-1] * (i * 2) * (i * 2 - 1) / (i * i);
  }
  int tc;
  int n2;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n2);
    printf("%.4f\n", 1-ans[n2/2 - 1]);
  }
  return 0;
}
