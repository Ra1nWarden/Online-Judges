#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int primes[1300];
int pi;
const int maxn = 10000;
bool check[maxn+5];

void init() {
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i]) {
      primes[pi++] = i;
    }
    for(int j = 0; j < pi; j++) {
      if(i * primes[j] > maxn)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int count(int num) {
  int ans = 0;
  for(int i = 0; i < pi; i++) {
    while(num % primes[i] == 0) {
      ans++;
      num /= primes[i];
    }
  }
  return ans;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int m, n;
    scanf("%d%d", &m, &n);
    int nim = 0;
    for(int i = 0; i < m; i++) {
      int sum = 0;
      for(int j = 0; j < n; j++) {
	int num;
	scanf("%d", &num);
	sum += count(num);
      }
      nim ^= sum;
    }
    printf("Case #%d: %s\n", kase, nim == 0 ? "NO" : "YES");
  }
  return 0;
}
