#include <cstdio>
#include <cstring>
#define MAXN 1000005

using namespace std;

int n1[MAXN], n2[MAXN];
int n1i, n2i;
int t1, t2;

int main() {
  int m, h1, a1, x1, y1, h2, a2, x2, y2;
  scanf("%d%d%d%d%d%d%d%d%d", &m, &h1, &a1, &x1, &y1, &h2, &a2, &x2, &y2);
  t1 = t2 = -1;
  n1i = n2i = 0;
  if(h1 == a1)
    t1 = 0;
  if(h2 == a2)
    t2 = 0;
  int h1c = h1;
  int h2c = h2;
  n1i++;
  n2i++;
  while(true) {
    h1 = (x1 * 1LL * h1 + y1) % m;
    if(h1 == h1c)
      break;
    if(h1 == a1)
      t1 = n1i;
    n1i++;
  }
  while(true) {
    h2 = (x2 * 1LL * h2 + y2) % m;
    if(h2 == h2c)
      break;
    if(h2 == a2)
      t2 = n2i;
    n2i++;
  }
  if(t1 == -1 || t2 == -1) {
    printf("-1\n");
    return 0;
  }
  t1++;
  t2++;
  long long remainder = t1 % n2i == 0 ? n2i : t1 % n2i;
  if(remainder == t2) {
    printf("%lld\n", t1-1);
    return 0;
  }
  for(long long ans = t1 + n1i; ans > 0; ans += n1i) {
    long long next_remainder = ans % n2i == 0 ? n2i : ans % n2i;
    if(next_remainder == remainder) {
      break;
    }
    if(next_remainder == t2) {
      printf("%lld\n", ans-1);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
