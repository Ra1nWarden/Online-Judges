#include <iostream>
#include <map>
#define MOD 1000000007
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

typedef pair<int, int> ii;
map<ii, int> dp;

int f(int a, int b) {
  ii tuple = make_pair(a, b);
  if(dp.count(tuple))
    return dp[tuple];
  if(b < 0 || a < b)
    return dp[make_pair(a, b)] = 0;
  if(a == b)
    return dp[make_pair(a, b)] = 1;
  return dp[make_pair(a, b)] = (f(a - 1, b + 1) + f(a - 1, b - 1)) % MOD;
}

int main() {
  int n;
  string line;
  while(cin >> n) {
    getline(cin, line);
    getline(cin, line);
    int balance = 0;
    for(int i = 0; i < line.length(); i++) {
      if(line[i] == '(')
	balance++;
      else
	balance--;
    }
    int slots = n - line.length();
    if(balance < 0 || slots < balance)
      printf("0\n");
    else
      printf("%d\n", f(slots, balance));
  }
  return 0;
}
