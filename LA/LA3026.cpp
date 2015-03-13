#include <cstdio>
#define MAXN 1000005

using namespace std;

char str[MAXN];
int f[MAXN];
int n;

void pre_kmp() {
  f[0] = f[1] = 0;
  for(int i = 1; i < n; i++) {
    int j = f[i];
    while(j && str[i] != str[j])
      j = f[j];
    f[i+1] = str[i] == str[j] ? j + 1 : 0;
  }
}

void countTotal() {
  for(int i = 2; i <= n; i++) {
    if(f[i] > 0 && (i % (i - f[i]) == 0))
      printf("%d %d\n", i, i / (i - f[i]));
  }
}

int main() {
  int tc = 1;
  while(scanf("%d\n", &n) != EOF && n) {
    scanf("%s\n", str);
    pre_kmp();
    printf("Test case #%d\n", tc++);
    countTotal();
    printf("\n");
  }
  return 0;
}
