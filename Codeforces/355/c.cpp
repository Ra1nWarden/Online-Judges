#include <cstring>
#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;
const int maxl = 100000;
char str[maxl+5];
int dp[64];

int encode(char ch) {
  if(ch == '-')
    return 62;
  if(ch == '_')
    return 63;
  if(ch >= 'a' && ch <= 'z')
    return 36 + (ch - 'a');
  if(ch >= 'A' && ch <= 'Z')
    return 10 + (ch - 'A');
  return ch - '0';
}

int f(int num) {
  if(dp[num] != -1)
    return dp[num];
  int b = 1;
  int ans = 1;
  while(b < 64) {
    if((b & num) == 0) {
      ans = (ans * 1LL * 3) % mod;
    }
    b <<= 1;
  }
  return dp[num] = ans;
}

int main() {
  scanf("%s", str);
  memset(dp, -1, sizeof dp);
  int ans = 1;
  for(int i = 0; i > -1; i++) {
    if(str[i] == '\0')
      break;
    ans = (ans * 1LL * f(encode(str[i]))) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
