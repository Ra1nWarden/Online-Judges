#include <cstdio>

using namespace std;

int n, t;
const int inf = 1500000000;
const int maxn = 200000;
char str[maxn+5];
int dp[maxn+5];

int main() {
  scanf("%d%d\n", &n, &t);
  scanf("%s", str+1);
  int i;
  for(i = 1; i <= n; i++) {
    if(str[i] == '.')
      break;
  }
  int j;
  for(j = n; j > i; j--) {
    if(str[j] == '4') {
      dp[j] = j == n ? inf : dp[j+1] + 1;
    } else if(str[j] < '4') {
      dp[j] = inf;
    } else {
      dp[j] = 1;
    }
  }
  for(j = i+1; j <= n; j++) {
    if(dp[j] <= t) {
      break;
    }
  }
  if(j == n + 1) {
    printf("%s\n", str+1);
    return 0;
  }
  str[j] = '\0';
  j--;
  int start = 1;
  while(j >= 0) {
    if(j == i) {
      str[j] = '\0';
    } else if(j > i) {
      if(str[j] == '9') {
	str[j] = '\0';
      } else {
	str[j]++;
	break;
      }
    } else {
      if(j == 0) {
	str[j] = '1';
	start = 0;
      } else if(str[j] == '9') {
	str[j] = '0';
      } else {
	str[j]++;
	break;
      }
    }
    j--;
  }
  printf("%s\n", str+start);
  return 0;
}
