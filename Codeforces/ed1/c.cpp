#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100000;
const double pi = acos(-1);

typedef pair<double, int> Vec;
Vec v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    double rad = atan2(b, a);
    if(rad < 0)
      rad += 2 * pi;
    v[i] = make_pair(rad, i+1);
  }
  sort(v, v+n);
  double min_angle = 3 * pi;
  int idx1, idx2;
  for(int i = 0; i < n; i++) {
    double cur_angle;
    if(i == n - 1) {
      cur_angle = v[0].first - v[i].first + (2 * pi);
    } else {
      cur_angle = v[i+1].first - v[i].first;
    }
    if(cur_angle < min_angle) {
      min_angle = cur_angle;
      idx1 = v[i].second;
      idx2 = v[i+1].second;
    }
  }
  printf("%d %d\n", idx1, idx2);
  return 0;
}
