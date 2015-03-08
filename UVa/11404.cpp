#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAXN 1005

using namespace std;

char str[MAXN];
int n;
string dp[MAXN][MAXN]; // 0 -> not picking i and 1 -> picking i as the mid point
bool dpv[MAXN][MAXN];

string g(int a, int b) {
  //printf("calling g(%d, %d)\n", a, b);
  if(dpv[a][b])
    return dp[a][b];
  if(a == 0 || b == 0) {
    dpv[a][b] = true;
    return dp[a][b] = "";
  }
  string res = "";
  string subres;
  if(str[a - 1] == str[n - b]) {
    subres = g(a - 1, b - 1) + str[a-1];
    if(subres.length() > res.length() || (subres.length() == res.length() && subres < res))
      res = subres;
  }
  subres = g(a - 1, b);
  if(subres.length() > res.length() || (subres.length() == res.length() && subres < res))
    res = subres;
  subres = g(a, b - 1);
  if(subres.length() > res.length() || (subres.length() == res.length() && subres < res))
    res = subres;
  dpv[a][b] = true;
  return dp[a][b] = res;
}

string f(int len, int use) {
  string res;
  if(use == 0) {
    res = g(len, n - len);
  } else {
    if(len > 0)
      res = g(len - 1, n - len);
  }
  return res;
}

int main() {
  while(scanf("%s", str) != EOF) {
    n = strlen(str);
    memset(dpv, false, sizeof dpv);
    string res = "";
    for(int i = 0; i < n; i++) {
      string res1 = f(i+1, 0);
      string res2 = f(i+1, 1);
      string res1cpy = res1;
      reverse(res1cpy.begin(), res1cpy.end());
      res1 = res1 + res1cpy;
      string res2cpy = res2;
      reverse(res2cpy.begin(), res2cpy.end());
      res2 = res2 + str[i] + res2cpy;
      //printf("res1 is %s and res2 is %s\n", res1.c_str(), res2.c_str());
      if(res1.length() > res.length() || (res1.length() == res.length() && res1 < res)) {
	res = res1;
      }
      if(res2.length() > res.length() || (res2.length() == res.length() && res2 < res)) {
	res = res2;
      }
    }
    printf("%s\n", res.c_str());
  }
  return 0;
}
