#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int n, m;
set<int> rows, cols;

int main() {
  scanf("%d%d", &n, &m);
  long long ans = n * 1LL * n;
  for(int i = 0; i < m; i++) {
    if(i)
      printf(" ");
    int x, y;
    scanf("%d%d", &x, &y);
    int destroy = 0;
    if(!rows.count(x)) {
      destroy += n - cols.size();
    }
    if(!cols.count(y)) {
      destroy += n - rows.size();
    }
    if(!rows.count(x) && !cols.count(y)) {
      destroy--;
    }
    rows.insert(x);
    cols.insert(y);
    ans -= destroy;
    printf("%I64d", ans);
  }
  printf("\n");
  return 0;
}
