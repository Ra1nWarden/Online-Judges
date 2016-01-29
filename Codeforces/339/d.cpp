#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100000;
int v[maxn+5];
int n;
int a, cf, cm;
long long m;
typedef pair<int, int> Node;
Node nodes[maxn+1];
long long extra[maxn+1];

int main() {
  scanf("%d%d%d%d%I64d", &n, &a, &cf, &cm, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    nodes[i] = make_pair(v[i], i);
  }
  if(n == 1) {
    int val = min(v[0] + m, (long long) a);
    long long ans = cm * 1LL * val + (val == a ? cf : 0);
    printf("%I64d\n%d\n", ans, val);
    return 0;
  }
  sort(nodes, nodes+n);
  for(int i = 0; i < n - 1; i++) {
    extra[i] = (nodes[i + 1].first - nodes[i].first) * 1LL * (i + 1);
    if(i)
      extra[i] += extra[i-1];
  }
  int full_cnt = 0;
  for(int i = n - 1; i > - 1; i--) {
    if(nodes[i].first != a)
      break;
    full_cnt++;
  }
  int filled = upper_bound(extra, extra + n - 1, m) - extra;
  int lower = nodes[filled].first;
  if(filled > 0) {
    lower += min((long long) a - lower, (m - extra[filled - 1]) / (filled + 1));
  }
  lower = min(lower, a);
  if(lower == a)
    full_cnt = n;
  long long maxans =  cf * 1LL * full_cnt + cm * 1LL * lower;
  int idx = n;
  int fill_idx = filled;
  int fill_h = lower;
  //printf("start maxans=%I64d lower=%d fill_idx=%d fill_h=%d\n", maxans, lower, fill_idx, fill_h);
  for(int i = n - 1; i > -1; i--) {
    if(i - 1 > -1 && nodes[i - 1].first == a)
      continue;
    m -= a - nodes[i].first;
    if(m < 0)
      break;
    filled = upper_bound(extra, extra + n - 1, m) - extra;
    lower = nodes[filled].first;
    if(filled > 0) {
      lower += (m - extra[filled - 1]) / (filled + 1);
    }
    lower = min(lower, a);
    long long val =  cf * 1LL * (n - i) + cm * 1LL * lower;
    //printf("i=%d lower=%d val=%I64d\n", i, lower, val);
    if(val > maxans) {
      maxans = val;
      idx = i;
      fill_idx = filled;
      fill_h = lower;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i <= fill_idx)
      v[nodes[i].second] = fill_h;
    else if(i >= idx)
      v[nodes[i].second] = a;
    else
      v[nodes[i].second] = nodes[i].first;
  }
  printf("%I64d\n", maxans);
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
