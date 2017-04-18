#include <cstdio>

using namespace std;

const int maxl = 100000;
int v[maxl+5];
int n;

int main() {
  while(scanf("%d", &n)) {
    if(n == 0)
      break;
    for(int i = 1; i <= n; i++)
      scanf("%d", &v[i]);
    bool ok = true;
    for(int i = 1; i <= n; i++) {
      if(i != v[v[i]]) {
	ok = false;
	break;
      }
    }
    printf("%s\n", ok ? "ambiguous" : "not ambiguous");
  }
  return 0;
}
