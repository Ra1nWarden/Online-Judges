#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
char mat[maxn+5][maxn+5];
int n, d;

int main() {
  scanf("%d%d\n", &n, &d);
  for(int i = 0; i < d; i++)
    scanf("%s\n", mat[i]);
  int ans = 0;
  int cur = 0;
  for(int i = 0; i < d; i++) {
    bool ok = true;
    for(int j = 0; j < n; j++) {
      if(mat[i][j] == '0') {
	ok = false;
	break;
      }
    }
    if(!ok)
      cur++;
    else {
      ans = max(ans, cur);
      cur = 0;
    }
  }
  printf("%d\n", max(ans, cur));
  return 0;
}
