#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#define MAXL 105

using namespace std;

string str;
int dp[MAXL][MAXL];
int len;

bool match(char a, char b) {
  return (a == '(' && b == ')') || (a == '[' && b == ']');
}

void print(int i, int j) {
  if(i > j)
    return;
  if(match(str[i], str[j]) && dp[i][j] == dp[i+1][j-1]) {
    printf("%c", str[i]);
    print(i+1, j-1);
    printf("%c", str[j]);
    return;
  }
  if(i == j) {
    if(str[i] == '(' || str[i] == ')')
      printf("()");
    else
      printf("[]");
    return;
  }
  for(int k = i; k < j; k++) {
    if(dp[i][j] == dp[i][k] + dp[k+1][j]) {
      print(i, k);
      print(k+1, j);
      return;
    }
  }
}

int main() {
  int tc;
  cin >> tc;
  getline(cin, str);
  for(int kase = 0; kase < tc; kase++) {
    if(kase > 0)
      printf("\n");
    getline(cin, str);
    getline(cin, str);
    len = str.length();
    memset(dp, 0, sizeof dp);
    for(int diff = 0; diff < len; diff++) {
      for(int i = 0; i + diff < len; i++) {
    	if(diff == 0)
    	  dp[i][i+diff] = 1;
    	else {
    	  dp[i][i+diff] = diff + 1;
    	  if(match(str[i], str[i+diff])) {
    	    dp[i][i+diff] = min(dp[i][i+diff], dp[i+1][i+diff-1]);
    	  }
    	  for(int j = i; j < i+diff; j++) {
    	    dp[i][i+diff] = min(dp[i][i+diff], dp[i][j] + dp[j+1][i+diff]);
    	  }
    	}
      }
    }

    // for(int i = 0; i < len; i++) {
    //   dp[i+1][i] = 0;
    //   dp[i][i] = 1;
    // }
    // for(int i = len-2; i >= 0; i--)
    //   for(int j = i+1; j < len; j++) {
    // 	dp[i][j] = len;
    // 	if(match(str[i], str[j]))
    // 	  dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
    // 	for(int k = i; k < j; k++)
    // 	  dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
    //   }


    if(len == 0)
      printf("\n");
    else {
      print(0, len - 1);
      printf("\n");
    }
  }
  return 0;
}
