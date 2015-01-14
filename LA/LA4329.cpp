#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

int A[MAXN];
int C[MAXN];
int L[MAXN];
int R[MAXN];
int n;

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int ret = 0;
  while(x > 0) {
    ret += C[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while(x <= 100000) {
    C[x] += d;
    x += lowbit(x);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    memset(A, 0, sizeof A);
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
    }
    memset(C, 0, sizeof C);
    for(int i = 1; i <= n; i++) {
      add(A[i], 1);
      L[i] = sum(A[i] - 1);
    }
    memset(C, 0, sizeof C);
    for(int i = n; i >= 1; i--) {
      add(A[i], 1);
      R[i] = sum(A[i] - 1);
    }

    long long result = 0;
    for(int i = 2; i < n; i++) {
      result += (long long)L[i] * (n - i - R[i]) + (long long)R[i] * (i - L[i] - 1);
    }
    
    printf("%lld\n", result);
  }
  return 0;
}
