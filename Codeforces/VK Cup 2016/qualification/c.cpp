#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int n;
char code[maxn][7];

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%s\n", code[i]);
  int ans = 6;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      int cur = 0;
      for(int k = 0; k < 6; k++) {
	if(code[i][k] != code[j][k])
	  cur++;
      }
      ans = min(ans, (cur - 1) / 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
