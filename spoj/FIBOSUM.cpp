#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;

void multiply(int f[2][2], int m[2][2]) {
  int n[2][2];
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      int sum = 0;
      for(int k = 0; k < 2; k++) {
	sum = (sum + (f[i][k] * 1LL * m[k][j]) % mod) % mod;
      }
      n[i][j] = sum;
    }
  }
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      f[i][j] = n[i][j];
}

void power(int f[2][2], int n) {
  if(n == 1)
    return;
  int g[2][2];
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      g[i][j] = f[i][j];
  power(g, n / 2);
  multiply(g, g);
  if(n & 1) {
    multiply(g, f);
  }
  for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
      f[i][j] = g[i][j];
}

int fib(int n) {
  int f[2][2] = {{1, 1}, {1, 0}};
  power(f, n);
  return f[0][1];
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (fib(b + 2) - fib(a + 1) + mod) % mod);
  }
  return 0;
}
