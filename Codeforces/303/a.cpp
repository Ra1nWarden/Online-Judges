#include <cstdio>
#define MAXN 105

using namespace std;

int v[MAXN][MAXN];
int n;
int ans[MAXN];
int ai;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d", &v[i][j]);
  ai = 0;
  for(int i = 0; i < n; i++) {
    bool ok = true;
    for(int j = 0; j < n; j++) {
      if(v[i][j] == 1 || v[i][j] == 3) {
	ok = false;
	break;
      }
    }
    if(ok)
      ans[ai++] = i+1;
  }
  printf("%d\n", ai);
  for(int i = 0; i < ai; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", ans[i]);
  }
  if(ai > 0)
    printf("\n");
  return 0;
}
