#include <cstdio>
#include <cstring>
#define MAXN 5000005

using namespace std;

int primes[MAXN];
int pi;
int count[MAXN];
bool check[MAXN];
int sum[MAXN];

int main() {
  memset(check, false, sizeof check);
  memset(count, 0, sizeof count);
  for(int i = 2; i <= 5000000; i++) {
    if(!check[i]) {
      primes[pi++] = i;
      count[i] = 1;
    }
    for(int j = 0; j < pi; j++) {
      if(i * primes[j] > 5000000)
	break;
      check[i * primes[j]] = true;
      count[i * primes[j]] = count[i] + 1; 
      if(i % primes[j] == 0)
	break;
    }
  }
  sum[1] = 0;
  for(int i = 2; i <= 5000000; i++)
    sum[i] = sum[i-1] + count[i];
  int t;
  scanf("%d", &t);
  while(t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", sum[a] - sum[b]);
  }
  return 0;
}
