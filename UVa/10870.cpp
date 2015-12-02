#include <cstdio>
#include <cstring>

using namespace std;

const int maxd = 20;
int d, n, m;
int a[maxd], f[maxd];

typedef long long Matrix[maxd][maxd];

void matrix_mult(Matrix A, Matrix B, Matrix res) {
  Matrix C;
  memset(C, 0, sizeof(C));
  for(int i = 1; i <= d; i++)
    for(int j = 1; j <= d; j++)
      for(int k = 1; k <= d; k++)
	C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
  memcpy(res, C, sizeof(C));
}

void matrix_pow(Matrix A, int p, Matrix res) {
  Matrix aa, rr;
  memcpy(aa, A, sizeof(aa));
  memset(rr, 0, sizeof(rr));
  for(int i = 1; i <= d; i++)
    rr[i][i] = 1;
  while(p) {
    if(p&1) {
      matrix_mult(rr, aa, rr);
    }
    p >>= 1;
    matrix_mult(aa, aa, aa);
  }
  memcpy(res, rr, sizeof(rr));
}

int main() {
  while(scanf("%d%d%d", &d, &n, &m) != EOF && (d || n || m)) {
    for(int i = 1; i <= d; i++) {
      scanf("%d", &a[i]);
      a[i] %= m;
    }
    for(int i = 1; i <= d; i++) {
      scanf("%d", &f[i]);
      f[i] %= m;
    }
    if(n <= d) {
      printf("%d\n", f[n]);
      continue;
    }
    Matrix A;
    memset(A, 0, sizeof(A));
    for(int i = 1; i < d; i++)
      A[i][i+1] = 1;
    for(int i = 1; i <= d; i++)
      A[d][i] = a[d-i+1];
    Matrix powered;
    matrix_pow(A, n - d, powered);
    long long ans = 0;
    for(int i = 1; i <= d; i++)
      ans = (ans + powered[d][i] * f[i]) % m;
    printf("%lld\n", ans);
  }
  return 0;
}
