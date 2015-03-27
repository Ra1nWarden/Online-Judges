#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 200001

using namespace std;

int n;
int C[MAXN];

int lowbit(int x) {
  return x & (-x);
}

int sum(int x) {
  int res = 0;
  while(x > 0) {
    res += C[x];
    x -= lowbit(x);
  }
  return res;
}

void add(int x, int d) {
  while(x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}


int main() {
  scanf("%d", &n);
  memset(C, 0, sizeof C);
  for(int i = 1; i <= n; i++) {
    add(i, 1);
  }
  int x;
  int v1[n];
  int v2[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    v1[i] = sum(x);
    add(x+1, -1);
  }
  memset(C, 0, sizeof C);
  for(int i = 1; i <= n; i++) {
    add(i, 1);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &x);
    v2[i] = sum(x);
    add(x+1, -1);
  }
  int v3[n];
  int carry = 0;
  for(int i = n - 1; i >= 0; i--) {
    int sum = v1[i] + v2[i] + carry;
    carry = sum / (n - i);
    v3[i] = sum % (n - i);
  }
  memset(C, 0, sizeof C);
  for(int i = 0; i < n; i++) {
    if(i != 0)
      printf(" ");
    int l = 1, r = n, mid;
    while(l < r) {
      mid = l + (r - l) / 2;
      if (mid - 1 - sum(mid) < v3[i])
	l = mid + 1;
      else r = mid ;
    }
    add(l, 1);
    printf("%d", --l);
  }
  printf("\n");
  return 0;
}
