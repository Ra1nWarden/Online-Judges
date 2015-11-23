#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 4000000;

long long phi[maxn+1];
long long f[maxn+1];
long long s[maxn+1];

void init() {
  for(int i = 1; i <= maxn; i++)
    phi[i] = i;
  for(int i = 2; i <= maxn; i++) {
    if(phi[i] == i) {
      for(int j = i; j <= maxn; j+=i) {
	phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
  memset(f, 0, sizeof f);
  for(int i = 1; i <= maxn; i++) {
    for(int n = i * 2; n <= maxn; n += i) {
      f[n] += i * phi[n / i];
    }
  }
  s[2] = f[2];
  for(int i = 3; i <= maxn; i++) {
    s[i] = s[i-1] + f[i];
  }
}

int main() {
  init();
  int n;
  while(scanf("%d", &n) != EOF && n) {
    printf("%lld\n", s[n]);
  }
  return 0;
}
