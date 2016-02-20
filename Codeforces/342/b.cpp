#include <cstdio>
#include <cstring>

const int maxm = 100000;
const int maxn = 30;
char mstr[maxm+5];
char nstr[maxn+5];
int m, n;

using namespace std;

int main() {
  scanf("%s\n%s", mstr, nstr);
  m = strlen(mstr), n = strlen(nstr);
  int ans = 0;
  for(int i = 0; i + n <= m; i++) {
    bool matched = true;
    int j;
    int ii = i;
    for(j = 0; j < n; j++, ii++) {
      if(mstr[ii] != nstr[j]) {
	matched = false;
	break;
      }
    }
    if(matched) {
      ans++;
      i += j - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}
