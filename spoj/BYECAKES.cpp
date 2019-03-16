#include <cstdio>
#include <algorithm>

using namespace std;

int e, f, s, m, ee, ff, ss, mm;

int main() {
  while(scanf("%d%d%d%d%d%d%d%d", &e, &f, &s, &m, &ee, &ff, &ss, &mm)) {
    if(e == -1)
      break;
    int maxcnt = 0;
    maxcnt = max(maxcnt, (e + ee - 1) / ee);
    maxcnt = max(maxcnt, (f + ff - 1) / ff);
    maxcnt = max(maxcnt, (s + ss - 1) / ss);
    maxcnt = max(maxcnt, (m + mm - 1) / mm);
    printf("%d %d %d %d\n", maxcnt * ee - e, maxcnt * ff - f, maxcnt * ss - s, maxcnt * mm - m);
  }
  return 0;
}
