#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 2000;
int v[maxn+5];
map<int, int> cnt;

void inc(int num) {
  if(cnt.count(num))
    cnt[num] = cnt[num]+1;
  else
    cnt[num] = 1;
}

void dec(int num) {
  cnt[num] = cnt[num] - 1;
}

int query(int num) {
  if(cnt.count(num))
    return cnt[num];
  else
    return 0;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    inc(v[i]);
  }
  int avg = n / m;
  int delta = 0;
  int fill = 1;
  for(int i = 1; i <= n; i++) {
    if(v[i] > m || query(v[i]) > avg) {
      while(fill <= n && query(fill) >= avg) {
	fill++;
      }
      if(fill == m + 1)
	break;
      dec(v[i]);
      v[i] = fill;
      inc(fill);
      delta++;
    }
  }
  printf("%d %d\n", avg, delta);
  for(int i = 1; i <= n; i++) {
    if(i > 1)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
