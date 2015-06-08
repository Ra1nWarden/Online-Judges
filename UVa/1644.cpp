#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1300000

using namespace std;

bool check[MAXN+5];
int prime[MAXN];
int pi;

int main() {
  memset(check, false, sizeof check);
  pi = 0;
  for(int i = 2; i <= MAXN; i++) {
    if(!check[i]) {
      prime[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(i * prime[j] > MAXN)
	break;
      check[i * prime[j]] = true;
      if(i % prime[j] == 0)
	break;
    }
  }
  int num;
  while(scanf("%d", &num) != EOF && num) {
    int idx = lower_bound(prime, prime+pi, num) - prime;
    int large = prime[idx];
    if(large == num) {
      printf("0\n");
      continue;
    }
    int small = prime[idx - 1];
    printf("%d\n", large - small);
  }
  return 0;
}
