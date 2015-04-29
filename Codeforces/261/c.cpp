#include <cstdio>
#define MAXN 1005

using namespace std;

int v[MAXN][MAXN];

int main() {
  int n, k, d;
  scanf("%d %d %d", &n, &k, &d);
  long long maxVal = 1;
  for(int i = 0; i < d; i++) {
    maxVal *= k;
    if(maxVal < 0) {
      break;
    }
  }
  if(n > maxVal && maxVal > 0) {
    printf("-1\n");
  } else {
    for(int i = 0; i < n; i++) {
      int num = i;
      for(int j = 0; j < d; j++) {
	v[i][j] = (num % k) + 1;
	num /= k;
      }
    }
    for(int i = 0; i < d; i++) {
      for(int j = 0; j < n; j++) {
	if(j > 0)
	  printf(" ");
	printf("%d", v[j][i]);
      }
      printf("\n");
    }
  }
  return 0;
}
