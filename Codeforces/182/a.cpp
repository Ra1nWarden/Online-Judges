#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d",&n, &m);
  int pos = 0, neg = 0;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    if(num > 0)
      pos++;
    else
      neg++;
  }
  for(int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    if((r - l + 1) % 2) {
      printf("0\n");
    } else {
      int half = (r - l + 1) / 2;
      if(half <= min(pos, neg)) {
	printf("1\n");
      } else {
	printf("0\n");
      }
    }
  }
  return 0;
}
