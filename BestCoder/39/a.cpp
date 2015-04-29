#include <cstdio>
#include <cstring>
#define MAXN 105

using namespace std;

int n, k;
int v[MAXN];
int count[MAXN];
int unique_num;

int main() {
  while(scanf("%d", &n) != EOF) {
    memset(count, 0, sizeof count);
    unique_num = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      if(count[v[i]] == 0)
	unique_num++;
      count[v[i]]++;
    }
    scanf("%d", &k);
    int repeated = n - unique_num;
    if(k > repeated)
      printf("%d\n", unique_num - (k - repeated));
    else
      printf("%d\n", unique_num);
  }
  return 0;
}
