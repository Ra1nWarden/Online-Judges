#include <cstdio>
#include <cstring>
#define MAXN 1005
#define MOD 1000000007

using namespace std;

int ans[MAXN];

void init() {
  ans[1] = 1;
  for(int num = 2; num <= 1000; num++) {
    ans[num] = ans[num-1];
    for(int branch = 2; branch <= num - 1; branch++) {
      if((num - 1) % branch == 0)
	ans[num] = (ans[num] + ans[(num-1)/branch]) % MOD;
    }
  }
}

int main() {
  init();
  int tc = 1;
  int num;
  while(scanf("%d", &num) != EOF)
    printf("Case %d: %d\n", tc++, ans[num]);
  return 0;
}
