#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 100005

using namespace std;

int n;
typedef pair<int, int> II;
II v[MAXN];
bool neg[MAXN];

int main() {
  while(scanf("%d", &n) != EOF) {
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      int num;
      scanf("%d", &num);
      sum += num;
      v[i] = make_pair(num, i);
    }
    sort(v, v+n);
    if(sum % 2 == 1) {
      printf("No\n");
      continue;
    }
    sum /= 2;
    memset(neg, false, sizeof neg);
    for(int i = n-1; i > -1; i--) {
      if(v[i].first <= sum) {
	sum -= v[i].first;
	neg[v[i].second] = true;
      }
    }
    printf("Yes\n");
    for(int i = 0; i < n; i++) {
      if(i > 0)
	printf(" ");
      printf("%d", neg[i] ? -1 : 1);
    }
    printf("\n");
  }
  return 0;
}
