#include <cstdio>
#include <utility>

using namespace std;

const int maxn = 1000;
int xs[maxn+5];
int ys[maxn+5];
int m, n;

pair<int, int> find_max(int* arr, int start, int end) {
  int maxval = 0;
  int maxidx = -1;
  for(int i = start; i < end; i++) {
    if(arr[i] > maxval) {
      maxval = arr[i];
      maxidx = i;
    }
  }
  return make_pair(maxval, maxidx);
}

int solve(int x0, int x1, int y0, int y1) {
  int ans = 0;
  if(x0 == x1) {
    for(int i = y0; i < y1; i++) {
      ans += ys[i];
    }
    return ans;
  }
  if(y0 == y1) {
    for(int i = x0; i < x1; i++) {
      ans += xs[i];
    }
    return ans;
  }

  pair<int, int> xmax = find_max(xs, x0, x1);
  pair<int, int> ymax = find_max(ys, y0, y1);

  if(xmax.first > ymax.first) {
    return xs[xmax.second] + solve(x0, xmax.second, y0, y1) + solve(xmax.second + 1, x1, y0, y1);
  } else {
    return ys[ymax.second] + solve(x0, x1, y0, ymax.second) + solve(x0, x1, ymax.second + 1, y1);
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &m, &n);
    m--, n--;
    for(int i = 0; i < m; i++)
      scanf("%d", &xs[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &ys[i]);
    printf("%d\n", solve(0, m, 0, n));
  }
  return 0;
}
