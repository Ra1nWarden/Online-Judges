#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXL 200010
#define MAXM 100005

using namespace std;

char str[MAXL];
int m;
int C[MAXM];
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
  while(x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}

int main() {
  scanf("%s\n", str);
  scanf("%d\n", &m);
  memset(C, 0, sizeof C);
  int l = strlen(str);
  n = l / 2;
  for(int i = 0; i < m; i++) {
    int index;
    scanf("%d", &index);
    add(index, 1);
  }

  for(int i = 0; i < l / 2; i++) {
    if(sum(i+1) % 2 == 1)
      swap(str[i], str[l - 1 - i]);
  }
  printf("%s\n", str);
  return 0;
}
