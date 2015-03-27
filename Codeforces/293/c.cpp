#include <cstdio>
#define MAXN 100005

int rank[MAXN];
int num[MAXN];

using namespace std;

int n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    rank[num[i]] = i;
  }
  long long res = 0;
  for(int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    res += (rank[q] / k + 1);
    if(rank[q] != 0) {
      int prev = num[rank[q] - 1];
      rank[q] = rank[q] - 1;
      rank[prev] = rank[prev] + 1;
      num[rank[q]] = q;
      num[rank[prev]] = prev;
    }
  }
  printf("%I64d\n", res);
  return 0;
}
