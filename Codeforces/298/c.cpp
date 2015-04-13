#include <cstdio>
#include <algorithm>
#define MAXN 200005

using namespace std;

int n;
long long a;
int v[MAXN];
long long prefix[MAXN];

int main() {
  scanf("%d %I64d", &n, &a);
  prefix[0] = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    prefix[i+1] = prefix[i] + v[i];
  }
  for(int i = 0; i < n; i++) {
    if(i > 0)
      printf(" ");
    int minVal = (int) max(1LL, a - prefix[i] - prefix[n] + prefix[i+1]);
    int maxVal = (int) min((long long) v[i],  a - (n - 1));
    printf("%d", v[i] - maxVal + minVal - 1);
  }
  printf("\n");
  return 0;
}
