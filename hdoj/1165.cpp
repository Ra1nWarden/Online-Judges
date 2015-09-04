#include<cstdio>

int dp[4][1000005];

using namespace std;

int main() {
  int i,j;
  for(i=0;i<=1000005;i++)
    dp[1][i]=i+2;
  for(i=0;i<=1000005;i++)
    dp[2][i]=i*2+3;
  dp[3][0]=5;
  for(i=1;i<=24;i++)
    dp[3][i]=2*dp[3][i-1]+3;
  while(~scanf("%d%d",&i,&j)) {
    printf("%d\n",dp[i][j]);
  }
  return 0;
}
