#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 5000;
int row[maxn+5], col[maxn+5];
int ri[maxn+5], ci[maxn+5];
int n, m, k;

int main() {
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  memset(ri, -1, sizeof ri);
  memset(ci, -1, sizeof ci);
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < k; i++) {
    int t, idx, c;
    scanf("%d%d%d", &t, &idx, &c);
    if(t == 1) {
      row[idx] = c;
      ri[idx] = i;
    } else if(t == 2) {
      col[idx] = c;
      ci[idx] = i;
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(j > 1)
	printf(" ");
      int num = 0, change = -1;
      if(ri[i] > change) {
	num = row[i];
	change = ri[i];
      }
      if(ci[j] > change) {
	num = col[j];
	change = ci[j];
      }
      printf("%d", num);
    }
    printf("\n");
  }
  return 0;
}
