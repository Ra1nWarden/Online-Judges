#include <cstdio>
#include <algorithm>
#define MAXN 20

using namespace std;

int v[MAXN];
int n;

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF) {
    for(int i = 0; i < n; i++)
      scanf("%d", &v[i]);
    long long maxVal = 0;
    for(int i = 0; i < n; i++) {
      long long prod = (long long) v[i];
      maxVal = max(maxVal, prod);
      for(int j = i+1; j < n; j++) {
	prod *= v[j];
	maxVal = max(maxVal, prod);
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", kase++, maxVal);
  }
  return 0;
}
