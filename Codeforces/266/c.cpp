#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 500005

using namespace std;

long long prefix_sum[MAXN];
long long v[MAXN];
int n;
vector<int> left, right;

int main() {
  scanf("%d", &n);
  prefix_sum[0] = 0;
  for(int i = 0; i < n; i++) {
    scanf("%I64d", &v[i]);
    prefix_sum[i+1] = v[i];
    prefix_sum[i+1] += prefix_sum[i];
  }
  if(prefix_sum[n] % 3 != 0) {
    printf("0\n");
    return 0;
  }
  long long sum = prefix_sum[n] / 3;
  left.clear();
  right.clear();
  for(int i = 1; i <= n; i++) {
    if(prefix_sum[i] == sum)
      left.push_back(i);
    if(prefix_sum[n] - prefix_sum[i-1] == sum)
      right.push_back(i);
  }
  
  long long ans = 0;
  
  for(int i = 0; i < left.size(); i++) {
    ans += (long long) right.size() - (upper_bound(right.begin(), right.end(), left[i] + 1) - right.begin());
  }

  printf("%I64d\n", ans);
  
  return 0;
}
