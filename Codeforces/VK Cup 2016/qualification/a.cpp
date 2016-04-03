#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
int count[maxn+5];

int main() {
  int maxval = 0;
  memset(count, 0, sizeof count);
  int n;
  scanf("%d", &n);
  int ans = -1;
  while(n--) {
    int id;
    scanf("%d", &id);
    count[id]++;
    if(count[id] > maxval) {
      ans = id;
      maxval = count[id];
    }
  }
  printf("%d\n", ans);
  return 0;
}
