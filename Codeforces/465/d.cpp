#include <cstdio>

using namespace std;

int n, m;
const int mod = 1e9 + 7;
const int maxn = 100000;
int s1[maxn+5], s2[maxn+5];

int mult_mod(int a, int b) {
  return (a * 1LL * b) % mod;
}

int add_mod(int a, int b) {
  return (a + b) % mod;
}

int inverse_mod(int a) {
  if(a == 1)
    return 1;
  return (inverse_mod(mod % a) * 1LL * (mod - mod / a)) % mod;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++)
    scanf("%d", &s1[i]);
  for(int i = 0; i < n; i++)
    scanf("%d", &s2[i]);

  int sum = 0;
  int total = 1;
  for(int i = n - 1; i >= 0; i--) {
    if(s1[i] == 0 && s2[i] == 0) {
      sum = add_mod(mult_mod(m, sum), mult_mod(mult_mod(mult_mod(m, m - 1), 500000004), total));
      total = mult_mod(m, mult_mod(total, m));
    } else if(s1[i] == 0) {
      if(s2[i] < m) {
	sum = add_mod(sum, mult_mod(m - s2[i], total));
      }
      total = mult_mod(total, m);
    } else if(s2[i] == 0) {
      if(s1[i] > 1) {
	sum = add_mod(sum, mult_mod(s1[i] - 1, total));
      }
      total = mult_mod(total, m);
    } else {
      if(s1[i] > s2[i]) {
	sum = total;
      } else if(s1[i] < s2[i]) {
	sum = 0;
      }
    }
  }
  
  printf("%d\n", mult_mod(sum, inverse_mod(total)));
  return 0;
}
