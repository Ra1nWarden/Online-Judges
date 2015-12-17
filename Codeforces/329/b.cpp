#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 100000;
typedef long long LL;
typedef pair<int, int> Line;
LL left[maxn+1];
LL right[maxn+1];
Line lines[maxn+1];
int n;
int x1, x2;

int main() {
  scanf("%d", &n);
  scanf("%d%d", &x1, &x2);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &lines[i].first, &lines[i].second);
    left[i] = x1 * 1LL * lines[i].first + lines[i].second;
    right[i] = x2 * 1LL * lines[i].first + lines[i].second;
  }
  sort(left, left+n);
  sort(right, right+n);
  bool ok = false;
  for(int i = 0; i < n; i++) {
    LL lv = lines[i].first * 1LL * x1 + lines[i].second;
    LL rv = lines[i].first * 1LL * x2 + lines[i].second;
    int ls = lower_bound(left, left+n, lv) - left;
    int le = upper_bound(left, left+n, lv) - left - 1;
    int rs = lower_bound(right, right+n, rv) - right;
    int re = upper_bound(right, right+n, rv) - right - 1;
    if(rs > le || ls > re) {
      ok = true;
      break;
    }      
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
