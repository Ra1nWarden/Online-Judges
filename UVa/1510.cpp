#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000;
int cnt[maxn+1];
int n;

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    int flg;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
	scanf("%d", &flg);
	if(flg) {
	  cnt[i]++;
	  cnt[j]++;
	}
      }
    }
    int total = n * (n - 1) * (n - 2) / 6;
    int illegal = 0;
    for(int i = 0; i < n; i++) {
      illegal += cnt[i] * (n - 1 - cnt[i]);
    }
    illegal >>= 1;
    printf("%d\n", total - illegal);
  }
  return 0;
}
