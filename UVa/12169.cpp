#include <cstdio>
#define MAXN 10005
#define MOD 10001

using namespace std;

int v[MAXN];
int t;

int main() {
  scanf("%d", &t);
  for(int i = 1; i <= 2 * t; i += 2) {
    scanf("%d", &v[i]);
  }
  bool found = false;
  for(int a = 0; a < 10001; a++) {
    for(int b = 0; b < 10001; b++) {
      bool ok = true;
      for(int i = 2; i <= 2 * t; i++) {
	if(i % 2 == 0) {
	  v[i] = (a * v[i-1] + b) % MOD;
	} else {
	  if(v[i] != (a * v[i-1] + b) % MOD) {
	    ok = false;
	    break;
	  }
	}
      }
      if(ok) {
	found = true;
	break;
      }
    }
    if(found)
      break;
  }
  for(int i = 2; i <= 2 * t; i += 2) {
    printf("%d\n", v[i]);
  }
  return 0;
}
