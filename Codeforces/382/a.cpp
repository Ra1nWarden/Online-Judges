#include <cstdio>

using namespace std;

const int maxn = 100;
char str[maxn+5];
int n, k, gi, ti;

int main() {
  scanf("%d%d\n", &n, &k);
  scanf("%s", str);
  for(int i = 0; i < n; i++) {
    if(str[i] == 'G') {
      gi = i;
    }
    if(str[i] == 'T') {
      ti = i;
    }
  }
  int cur = gi;
  bool ok = false;
  if(gi > ti) {
    while(cur > ti) {
      cur -= k;
      if(cur >= 0) {
	if(cur == ti) {
	  ok = true;
	  break;
	} else if(str[cur] == '#') {
	  break;
	}
      }
    }
  } else {
    while(cur < ti) {
      cur += k;
      if(cur < n) {
	if(cur == ti) {
	  ok = true;
	  break;
	} else if(str[cur] == '#') {
	  break;
	}
      }
    }
  }
  printf("%s\n", ok ? "YES" : "NO");
  return 0;
}
