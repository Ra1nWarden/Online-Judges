#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1030

using namespace std;

int A[MAXN][MAXN];
int C[MAXN][MAXN];
int s;

int lowbit(int x) {
  return x & (-x);
}

void add(int x, int y, int d) {
  A[x][y] += d;
  for(int i = x; i <= s; i += lowbit(i)) {
    for(int j = y; j <= s; j += lowbit(j)) {
      C[i][j] += d;
    }
  }
}

int sum(int x, int y) {
  int result = 0;
  for(int i = x; i > 0; i -= lowbit(i)) {
    for(int j = y; j > 0; j -= lowbit(j)) {
      result += C[i][j];
    }
  }
  return result;
}

int query(int left, int top, int right, int bottom) {
  return sum(right, bottom) - sum(right, top - 1) - sum(left - 1, bottom) + sum(left - 1, top - 1);
}

int main() {
  int i;
  while(scanf("%d", &i) != EOF) {
    if(i == 0) {
      scanf("%d", &s);
      memset(A, 0, sizeof A);
      memset(C, 0, sizeof C);
    }
    else if(i == 1) {
      int x, y, a;
      scanf("%d %d %d", &x, &y, &a);
      add(x+1, y+1, a);
    } else if (i == 2) {
      int l, b, r, t;
      scanf("%d %d %d %d", &l, &b, &r, &t);
      printf("%d\n", query(l+1, b+1, r+1, t+1));
    }
  }
  return 0;
}
