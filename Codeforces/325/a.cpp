#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  int idle = 0;
  bool start = false;
  for(int i = 0; i < n; i++) {
    int block;
    scanf("%d", &block);
    if(!start && block == 0)
      continue;
    start = true;
    if(block) {
      ans++;
      idle = 0;
    } else {
      if(idle) {
	ans--;
	start = false;
      } else if(i != n - 1) {
	ans++;
	idle++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
