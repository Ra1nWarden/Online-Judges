#include <cstdio>

using namespace std;

const int maxn = 1000000;
bool v[maxn+5];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      int light;
      scanf("%d", &light);
      v[i] = light;
    }
    bool ok = true;
    for(int i = 0; i < n; i++) {
      if(v[i])
	continue;
      else if (i < n - 1) {
	v[i+1] = !v[i+1];
      } else {
	ok = false;
	break;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
