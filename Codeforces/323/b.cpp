#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int v[maxn+5];
int used[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int task = 0;
  int ans;
  for(ans = 0; task != n; ans++) {
    if(ans % 2 == 0) {
      for(int j = 0; j < n; j++) {
	if(!used[j] && v[j] <= task) {
	  used[j] = true;
	  task++;
	}
      }
    } else {
      for(int j = n-1; j >= 0; j--) {
	if(!used[j] && v[j] <= task) {
	  used[j] = true;
	  task++;
	}
      }
    }
  }
  printf("%d\n", ans-1);
  return 0;
}
