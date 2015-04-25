#include <cstdio>
#include <algorithm>
#define MAXN 100005
#define INF 2000000000

using namespace std;

int v[MAXN];
int diff[MAXN];
int n, m, w;

bool ok(int x) {
  long long count = 0;
  int cover = 0;
  for(int i = 0; i < n; i++) {
    if(i >= w) {
      cover -= diff[i - w];
    }
    diff[i] = max(0, x - v[i]);
    if(cover < diff[i]) {
      count += (diff[i] - cover);
      diff[i] -= cover;
      cover += diff[i];
    } else {
      diff[i] = 0;
    }
  }
  return count <= (long long) m;
}

int main() {
  scanf("%d %d %d", &n, &m, &w);
  int minVal = INF;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    minVal = min(minVal, v[i]);
  }
  int left = minVal;
  int right = minVal + m;
  while(left != right) {
    int mid = ((left + right) >> 1) + 1;
    if(ok(mid)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }
  printf("%d\n", left);
  return 0;
}
