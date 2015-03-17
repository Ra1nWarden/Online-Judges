#include <cstdio>
#define MAXN 65

using namespace std;

int n;
int start[MAXN];
int end[MAXN];

long long f(int* v, int k, int pos) {
  if(k == 0)
    return 0;
  if(v[k - 1] == pos)
    return f(v, k - 1, pos);
  return f(v, k - 1, 6 - pos - v[k - 1]) + (1LL << (k-1));
}

int main() {
  int tc = 1;
  while(scanf("%d", &n) != EOF && n) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &start[i]);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", &end[i]);
    }
    int k = n - 1;
    while(start[k] == end[k] && k > -1)
      k--;
    if(k == -1) {
      printf("Case %d: 0\n", tc++);
    } else {
      printf("Case %d: %lld\n", tc++, f(start, k, 6 - start[k] - end[k]) + f(end, k, 6 - start[k] - end[k]) + 1);
    }
  }
  return 0;
}
