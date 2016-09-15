#include <cstdio>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;
int ans[maxn+5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int prev = 0;
  for(int i = n-1; i >= 0; i--) {
    ans[i] = prev + v[i];
    prev = v[i];
  }
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
