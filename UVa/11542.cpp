#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxp = 100;
const int maxn = 100;
int primes[maxp];
int factor[maxn+5][maxp];
int pi, n;
typedef int Matrix[maxn+5][maxn+5];
Matrix mat;

int rank(int m) {
  int i = 0, j = 0, k, r, u;
  while(i < m && j < n) {
    r = i;
    for(k = i; k < m; k++) {
      if(mat[k][j]) {
	r = k;
	break;
      }
    }
    if(mat[r][j]) {
      if(r != i) {
	for(k = 0; k <= n; k++)
	swap(mat[r][k], mat[i][k]);
      }
      for(u = i + 1; u < m; u++) {
	if(mat[u][j]) {
	  for(k = i; k <= n; k++)
	    mat[u][k] ^= mat[i][k];
	} 
      }
      i++;
    }
    j++;
  }
  return i;
}

void init() {
  bool check[505];
  pi = 0;
  memset(check, false, sizeof check);
  for(int i = 2; i <= 500; i++) {
    if(!check[i])
      primes[pi++] = i;
    for(int j = 0; j < pi; j++) {
      if(primes[j] * i > 500)
	break;
      check[primes[j] * i] = true;
      if(i % primes[j] == 0)
	break;
    }
  }
}

int main() {
  init();
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(factor, 0, sizeof factor);
    memset(mat, 0, sizeof mat);
    scanf("%d", &n);
    int pf = 0;
    for(int i = 0; i < n; i++) {
      long long num;
      scanf("%lld", &num);
      for(int j = 0; j < pi; j++) {
	int cnt = 0;
	while(num % primes[j] == 0) {
	  cnt++;
	  num /= primes[j];
	}
	if(cnt) {
	  pf = max(pf, j);
	}
	if(cnt & 1) {
	  factor[i][j] = 1;
	}
      }
    }
    for(int i = 0; i <= pf; i++) {
      for(int j = 0; j < n; j++) {
	if(factor[j][i])
	  mat[i][j] = 1;
      }
    }
    int r = rank(pf+1);
    printf("%lld\n", (1LL << (n - r)) - 1);
  }
}
