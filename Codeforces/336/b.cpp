#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 10;
int adig[maxn];
const int maxl = 200000;
char a[maxl+5];
char b[maxl+5];
int m, n;

int main() {
  scanf("%s\n", a);
  scanf("%s\n", b);
  m = strlen(a);
  n = strlen(b);
  memset(adig, 0, sizeof adig);
  long long ans = 0;
  int ai = 0;
  int bi = 0;
  for(int i = 0; i < n; i++) {
    if(i < m) {
      adig[a[ai++] - '0']++;
    }
    if(i + m - 1 >= n) {
      adig[a[bi++] - '0']--;
    }
    for(char j = 0; j <= 9; j++) {
      if(adig[j]) {
	ans += adig[j] * abs(j - (b[i] - '0'));
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
