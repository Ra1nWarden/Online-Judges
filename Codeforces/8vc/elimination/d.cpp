#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20000;
int v[maxn+5];
int n;
const int maxdiff = 5000 - 1;
long long diff[maxdiff + 5];
long long diff2[maxdiff + 5];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  memset(diff, 0, sizeof diff);
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      diff[max(v[i], v[j]) - min(v[i], v[j])]++;
    }
  }
  memset(diff2, 0, sizeof diff2);
  long long total = n * 1LL * (n - 1) / 2;
  for(int i = 1; i < maxdiff; i++) {
    if(diff[i] == 0)
      continue;
    for(int j = 1; i + j < maxdiff; j++) {
      if(diff[j] == 0)
	continue;
      diff2[i + j] += diff[i] * diff[j];
    }
  }
  for(int i = maxdiff - 1; i > 0; i--) {
    diff[i] += diff[i+1];
  }
  long long ans_num = 0;
  for(int i = 2; i < maxdiff; i++) {
    ans_num += diff2[i] * 1LL * diff[i+1];
  }
  printf("%.10lf\n", (double) ans_num / (total * 1LL * total * total));
  return 0;
}
