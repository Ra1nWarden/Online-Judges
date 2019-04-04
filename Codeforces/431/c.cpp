#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1000;
int v[maxn+5];

int main() {
  v[0] = 0;
  for(int i = 1; i <= maxn; i++) {
    v[i] = v[i-1] + i;
  }
  int n;
  scanf("%d", &n);
  string ans = "a";
  char c = 'b';
  while(n) {
    int cnt = upper_bound(v, v+maxn, n) - v - 1;
    ans += string(cnt+1, c);
    c++;
    n -= v[cnt];
  }
  printf("%s\n", ans.c_str());
  return 0;
}
