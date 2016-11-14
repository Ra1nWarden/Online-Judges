#include <cstdio>

using namespace std;

const int maxn = 200000;
int v[maxn+5];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if(v[i] > 2) {
      v[i] = (v[i] & 1) ? 1 : 2;
    }
  }
  bool ok = true;
  for(int i = 0; i < n; i++) {
    if(v[i] == 0 || v[i] == 2)
      continue;
    else if(v[i] == 1) {
      if(i == n - 1) {
	ok = false;
	break;
      }
      else {
	v[i]--;
	v[i+1]--;
      }
    } else {
      ok = false;
      break;
    }
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
