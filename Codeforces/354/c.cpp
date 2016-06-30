#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
int n, k, ans;

void two_pointer(char c) {
  int l = 0, r= 0;
  int cur = 0;
  int t = 0;
  while(l < n) {
    while(r < n) {
      if(t == k && str[r] != c) {
	break;
      }
      if(str[r] != c) {
	t++;
      }
      r++;
    }
    if(l < r) {
      ans = max(ans, r - l);
      if(str[l] != c) {
	t--;
      }
    }
    l++;
    if(r < l) {
      r = l;
    }
  }
  ans = max(ans, r - l);
}

int main() {
  scanf("%d%d\n", &n, &k);
  scanf("%s", str);
  ans = 0;
  two_pointer('a');
  two_pointer('b');
  printf("%d\n", ans);
  return 0;
}
