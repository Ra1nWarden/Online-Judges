#include <cstring>
#include <cstdio>
#define MAXN 10000

using namespace std;

bool check[MAXN+5];
int prime[MAXN];
int pi;
int ans[MAXN+5];

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i])
      prime[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(i * prime[j] > MAXN)
	break;
      check[i * prime[j]] = true;
      if(i % prime[j] == 0)
	break;
    }
  }
  memset(ans, 0, sizeof ans);
  for(int i = 0; i < pi; i++) {
    int sum = 0;
    for(int j = i; j < pi; j++) {
      sum += prime[j];
      if(sum > MAXN)
	break;
      ans[sum]++;
    }
  }
}

int main() {
  init();
  int num;
  while(scanf("%d", &num) != EOF && num)
    printf("%d\n", ans[num]);
  return 0;
}
