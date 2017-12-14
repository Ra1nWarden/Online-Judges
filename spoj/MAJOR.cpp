#include <cstdio>
#include <map>

using namespace std;

int main() {
  int tc, n;
  scanf("%d", &tc);
  while(tc--) {
    int num;
    scanf("%d", &n);
    map<int, int> m;
    bool found = false;
    int ans;
    for(int i = 0; i < n; i++) {
      scanf("%d", &num);
      if(m.count(num)) {
	m[num]++;
      } else {
	m[num] = 1;
      }
      if(m[num] > n / 2) {
	found = true;
	ans = num;
      }
    }
    if(found)
      printf("YES %d\n", ans);
    else
      printf("NO\n");
  }
  return 0;
}
