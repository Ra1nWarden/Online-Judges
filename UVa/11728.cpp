#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int ans[maxn+1];

int main() {
  memset(ans, -1, sizeof ans);
  ans[1] = 1;
  for(int i = 2; i <= maxn; i++) {
    int sum = 0;
    for(int p = 1; p * p <= i; p++) {
      if(p * p == i) {
	sum += p;
      } else if(i % p == 0) {
	sum += p;
	sum += (i / p);
      }
      if(sum > 1000)
	break;
    }
    if(sum <= 1000)
      ans[sum] = i;
  }
  int kase = 1;
  int query;
  while(scanf("%d", &query) != EOF && query) {
    printf("Case %d: %d\n", kase++, ans[query]);
  }
  return 0;
}
