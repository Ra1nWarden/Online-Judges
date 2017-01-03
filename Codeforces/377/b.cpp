#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 500;
int v[maxn+5];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  int prev = v[0];
  int add = 0;
  for(int i = 1; i < n; i++) {
    int sum = prev + v[i];
    int delta = max(0, k - sum);
    v[i] += delta;
    add += delta;
    prev = v[i];
  }
  printf("%d\n", add);
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
