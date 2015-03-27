#include <cstdio>
#include <cstring>
#define MAXN 100005
#define MOD 1000000007

using namespace std;

int n;
char str[MAXN];
int count[26];

long long power(int base, int po) {
  long long res = 1;
  for(int i = 0; i < po; i++) {
    res = res * base;
    res %= MOD;
  }
  return res;
}

int main() {
  scanf("%d\n", &n);
  scanf("%s\n", str);
  memset(count, 0, sizeof count);
  for(int i = 0; i < n; i++) {
    count[str[i] - 'A']++;
  }
  int maxcount = -1, maxsize = 0;
  for(int i = 0; i < 26; i++) {
    if(count[i] > maxcount) {
      maxcount = count[i];
      maxsize = 1;
    }
    else if(count[i] == maxcount)
      maxsize++;
  }
  printf("%d\n", (int) power(maxsize, n));
  return 0;
}
