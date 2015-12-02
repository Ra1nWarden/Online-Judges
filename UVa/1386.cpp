#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 500;
long long v[maxn+1];
int n, m, d, k;
typedef long long Matrix[maxn+1][maxn+1];
Matrix AA;
Matrix powered;

void matrix_mult(Matrix A, Matrix B, Matrix C) {
  Matrix D;
  memset(D, 0, sizeof D);
  for(int j = 0; j < n; j++) {
    for(int kk = 0; kk < n; kk++) {
      D[0][j] = (D[0][j] + A[0][kk] * B[kk][j]) % m;
    }
  }
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n; j++) {
      D[i][j] = D[i-1][(j-1+n)%n];
    }
  }
  memcpy(C, D, sizeof D);
}

void matrix_pow(Matrix A, int p, Matrix res) {
  Matrix B;
  memset(B, 0, sizeof B);
  for(int i = 0; i < n; i++)
    B[i][i] = 1;
  Matrix C;
  memcpy(C, A, sizeof C);
  while(p) {
    if(p&1) {
      matrix_mult(B, C, B);
    }
    p >>= 1;
    matrix_mult(C, C, C);
  }
  memcpy(res, B, sizeof B);
}

int main() {
  while(scanf("%d%d%d%d", &n, &m, &d, &k) != EOF) {
    for(int i = 0; i < n; i++) {
      scanf("%lld", &v[i]);
    }
    memset(AA, 0, sizeof AA);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	int sep = i - j < 0 ? j - i : i - j;
	if(min(sep, n - sep) <= d)
	  AA[i][j] = 1;
      }
    }
    matrix_pow(AA, k, powered);
    for(int i = 0; i < n; i++) {
      if(i > 0)
	printf(" ");
      long long num = 0;
      for(int j = 0; j < n; j++) {
	num = (num + powered[i][j] * v[j]) % m;
      }
      printf("%lld", num);
    }
    printf("\n");
  }
  return 0;
}
