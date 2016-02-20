#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int l = 0, r = 3000000;
  while(l < r) {
    int mid = (l + r) >> 1;
    int six = mid / 6;
    int two = mid / 2 - six;
    int three = mid / 3 - six;
    bool ok = ((max(0, n - two) + max(0, m - three)) <= six);
    if(ok) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}
