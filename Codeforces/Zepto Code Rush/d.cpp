#include <cstdio>
#define MAXL 1000005

using namespace std;

char str[MAXL];
int f[MAXL];
int n, k;

int main() {
  scanf("%d %d\n", &n, &k);
  scanf("%s", str);
  f[0] = f[1] = 0;
  for(int i = 1; i < n; i++) {
    int j = f[i];
    while(j && str[i] != str[j])
      j = f[j];
    f[i+1] = str[i] == str[j] ? j + 1 : 0;
  }
  for(int i = 0; i <= n; i++)
    printf("f[%d]=%d\n", i , f[i]);  
  return 0;
}
