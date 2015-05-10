#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXM 30000000

using namespace std;

int ans[MAXM+5];

int main() {
  memset(ans, 0, sizeof ans);
  for(int c = 1; c <= MAXM; c++) {
    for(int a = c*2; a <= MAXM; a += c) {
      int b = a-c;
      if(c == (a^b)) {
	ans[a]++;
      }
    }
  }
  for(int c = 1; c <= MAXM; c++)
    ans[c] += ans[c-1];
  int tc;
  scanf("%d", &tc);
  int kase = 1;
  while(tc--) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", kase++, ans[n]);
  }
}
