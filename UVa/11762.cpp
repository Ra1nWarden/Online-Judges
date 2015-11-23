#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
int primes[80000];
double ans[maxn+1];
bool visited[maxn+1];
int pi;

void init() {
  pi = 0;
  bool check[maxn+5];
  memset(check, false, sizeof check);
  memset(visited, false, sizeof visited);
  for(int i = 2; i <= maxn; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(i * primes[j] > maxn)
	break;
      check[i * primes[j]] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

double f(int num) {
  if(visited[num])
    return ans[num];
  if(num == 1) {
    visited[num] = true;
    return ans[num] = 0;
  }
  double ret = 0;
  int p = 0;
  int q = 0;
  for(int i = 0; i < pi; i++) {
    if(primes[i] > num)
      break;
    if(num % primes[i] == 0)
      p++;
    q++;
  }
  double exp = 1.0;
  for(int i = 0; i < pi; i++) {
    if(primes[i] > num)
      break;
    if(num % primes[i] == 0) {
      exp += f(num / primes[i]) / q;
    }
  }
  visited[num] = true;
  return ans[num] = exp * q / p;
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int num;
    scanf("%d", &num);
    printf("Case %d: %.9lf\n", kase, f(num));
  }
  return 0;
}
