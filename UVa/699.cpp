#include <cstdio>
#include <cstring>
#define MAXN 205

using namespace std;

int sum[MAXN];

void build(int p) {
  int next;
  scanf("%d",&next);
  if(next == -1)
    return;
  sum[p] += next;
  build(p-1);
  build(p+1);
}

bool init() {
  int next;
  scanf("%d", &next);
  if(next == -1)
    return false;
  memset(sum, 0, sizeof sum);
  int p = MAXN / 2;
  sum[p] = next;
  build(p-1);
  build(p+1);
}

int main() {
  int kase = 1;
  while(init()) {
    int p = 0;
    while(sum[p] == 0)
      p++;
    printf("Case %d:\n%d", kase++, sum[p++]);
    while(sum[p] != 0)
      printf(" %d", sum[p++]);
    printf("\n\n");
  }
  return 0;
}
