#include <cstdio>
#define MAXN 500005

using namespace std;
int n, k;
int f[MAXN];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d %d", &n, &k);
    for(int a = 3; a >= 1; a--) {
      f[a] = (k - 1) % a;
      for(int i = a + 1; i <= n; i++)
	f[i] = (f[i-1] + k) % i;
      printf("%d", f[n] + 1);
      if(a == 1)
	printf("\n");
      else
	printf(" ");
    }
  }
  return 0;
}
