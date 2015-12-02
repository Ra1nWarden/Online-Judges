#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
int n;

int main() {
  scanf("%d\n", &n);
  scanf("%s", str);
  int delta = 0;
  int ans = 1;
  int idx = 1;
  while(idx < n) {
    if(str[idx] == str[idx-1]) {
      delta++;
    } else {
      ans++;
    }
    idx++;
  }
  printf("%d\n", ans + min(delta, 2));
  return 0;
}
