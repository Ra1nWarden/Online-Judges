#include <cstdio>

using namespace std;

int ans[17]={0,1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};

int main() {
  int tc;
  scanf("%d", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    int q;
    scanf("%d", &q);
    printf("Case #%d: %d\n", kase, ans[q]);
  }
  return 0;
}
