#include <cstdio>

using namespace std;

const int maxn = 100;
char v[maxn+1][maxn+5];
int n;

int main() {
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%s\n", v[i]);
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    long long cnt = 0;
    for(int j = 0; j < n; j++) {
      if(v[i][j] == 'C')
	cnt++;
    }
    ans += (cnt * (cnt - 1)) >> 1;
  }
  for(int j = 0; j < n; j++) {
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
      if(v[i][j] == 'C')
	cnt++;
    }
    ans += (cnt * (cnt - 1)) >> 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
