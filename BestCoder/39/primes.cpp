#include <cstdio>
#include <cstring>
#define MAXN 10005

using namespace std;

int main() {
  
  bool p[MAXN];
  int primes[MAXN];
  memset(p, true, sizeof p);
  int pn = 0;
  for(int i = 2; i <= 10000; i++) {
    if(p[i]) {
      primes[pn++] = i;
      for(int j = i + i; j <= 10000; j += i)
	p[j] = false;
    }
  }

  printf("{");
  for(int i = 0; i < pn; i++)
    printf("%d,", primes[i]);
  printf("}\n");
  printf("%d\n", pn);

}
