#include <cstdio>

using namespace std;

const int maxl = 5000;
char str[maxl+5];
long long dp[maxl+5];

int main() {
  while(scanf("%s\n", str)) {
    if(str[0] == '0')
      break;
    dp[0] = 1;
    int len = 0;
    for(int i = 0; i >= 0; i++) {
      if(str[i] == '\0')
	break;
      len++;
      dp[i+1] = str[i] == '0' ? 0 : dp[i];
      if(i && str[i-1] != '0') {
	int c = (str[i-1] - '0') * 10 + (str[i] - '0');
	if(c >= 1 && c <= 26) {
	  dp[i+1] += dp[i-1];
	}
      }
    }
    printf("%lld\n", dp[len]);
  }
  return 0;
}
