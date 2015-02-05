#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 50001
#define MAXA 32769

using namespace std;

int C[MAXA];
int A[MAXN];
int L[MAXN];
int R[MAXN];
int n;

int lowbit(int x) {
  return x & (-x);
}

void add(int x, int d) {
  while(x < MAXA) {
    C[x] += d;
    x += lowbit(x);
  }
}

int sum(int x) {
  int res = 0;
  while(x > 0) {
    res += C[x];
    x -= lowbit(x);
  }
  return res;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    memset(A, 0, sizeof A);
    for(int i = 1; i <= n; i++) {
      scanf("%d", &A[i]);
    }
    memset(C, 0, sizeof C);
    for(int i = 1; i <= n; i++) {
      add(A[i]+1, 1);
      L[i] = sum(A[i]);
    }
    memset(C, 0, sizeof C);
    for(int i = n; i >= 1; i--) {
      add(A[i]+1, 1);
      R[i] = sum(A[i]);
    }
    long long result = 0;
    for(int i = 1; i <= n; i++) {
      result += L[i] * R[i];
    }
    printf("%lld\n", result);
  }
  return 0;
}
