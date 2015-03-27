#include <cstdio>
#include <algorithm>
#define MAXN 200005

using namespace std;
int n;
int sum[MAXN];
int diff[MAXN];
typedef pair<int, int> II;
II v[MAXN];

bool _cmp(II& one, II& two) {
  return one.first < two.first;
}

int main() {
  scanf("%d", &n);
  int index = 0;
  while(n--) {
    int x, w;
    scanf("%d %d", &x, &w);
    v[index].first = x;
    v[index].second = w;
    index++;
  }
  sort(v, v+n, _cmp);
  for(int i = 0; i < n; i++) {
    sum[i] = v[i].first = v[i].second;
    diff[i] = v[i].first - v[i].second;
  }
  
}
