#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 1000000007;
const int maxl = 1000000;
char str[maxl+5];
int l;

int main() {
  scanf("%s", str);
  l = strlen(str);
  long long b = 0;
  long long ans = 0;
  for(int i = l - 1; i >= 0; i--) {
    if(str[i] == 'b') {
      b++;
    } else {
      ans = (b + ans) % mod;
      b = (b * 2) % mod;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
