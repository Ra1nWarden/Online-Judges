#include <cstdio>
#include <algorithm>
#define MAXN 200005

using namespace std;

long long prefix[MAXN];
long long postfix[MAXN];
long long v[MAXN];

int main() {
  long long n, k, x;
  scanf("%I64d%I64d%I64d", &n, &k, &x);
  long long num = 1;
  while(k--)
    num *= x;
  for(int i = 1; i <= n; i++)
    scanf("%I64d", &v[i]);
  prefix[0] = 0;
  for(int i = 1; i <= n; i++)
    prefix[i] = prefix[i-1] | v[i];
  postfix[n+1] = 0;
  for(int i = n; i >= 1; i--)
    postfix[i] = postfix[i+1] | v[i];
  long long ans = 0;
  for(int i = 1; i <= n; i++)
    ans = max(ans, prefix[i-1] | num * v[i] | postfix[i+1]);
  printf("%I64d\n", ans);
  return 0;
}
