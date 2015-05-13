#include <cstdio>
#include <cstring>
#define MOD 100000007LL
#define MAXN 10000001

using namespace std;

int n, m;
bool prime[MAXN];
int pn[MAXN];
int pi;
int phifac[MAXN];

void init() {
  memset(prime, true, sizeof prime);
  pi = 0;
  prime[0] = prime[1] = false;
  for(int i = 2; i < MAXN; i++) {
    if(prime[i]) {
      pn[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(pn[j] * i >= MAXN)
	break;
      prime[pn[j] * i] = false;
      if(i % pn[j] == 0)
	break;
    }
  }

  phifac[1] = phifac[2] = 1;
  for(int i = 3; i < MAXN; i++) {
    if(prime[i])
      phifac[i] = (int) ((phifac[i-1] * 1LL * (i - 1)) % MOD);
    else
      phifac[i] = (int) ((phifac[i-1] * 1LL * i) % MOD);
    //printf("phifac[%d]=%d\n", i, phifac[i]);
  }
}

int solve() {
  int ans = phifac[m];
  for(int i = m + 1; i <= n; i++) {
    ans = (int) ((ans * 1LL * i) % MOD);
  }
  return ans;
}

int main() {
  init();
  while(scanf("%d %d", &n, &m) != EOF && (n || m)) {
    printf("%d\n", solve() - 1);
  }
  return 0;
}
