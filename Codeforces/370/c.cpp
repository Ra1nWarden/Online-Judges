#include <cstdio>
#include <algorithm>

using namespace std;

int v[3];

int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  v[0] = v[1] = v[2] = y;
  int ans = 0;
  for(int i = 0; !(v[0] == x && v[1] == x && v[2] == x); i = (i + 1) % 3) {
    int change = min((v[0] + v[1] + v[2] - v[i]) - 1, x);
    if(change != v[i]) {
      ans++;
      v[i] = change;
    }
  }
  printf("%d\n", ans);
  return 0;
}
