#include <iostream>
#include <string>

using namespace std;

string solve(long long n, string prefix) {
  if(n == 0)
    return prefix + "";
  if(n == 1)
    return prefix + "5";
  if(n == 2)
    return prefix + "6";
  long long sum = 0;
  long long add = 2LL;
  while(n > sum + add) {
    sum += add;
    add <<= 1;
  }
  if(n - sum <= add / 2) {
    return solve(n - add / 2, prefix + "5");
  } else {
    return solve(n - add, prefix + "6");
  }
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    long long k;
    cin >> k;
    cout << solve(k, "") << endl;
  }
  return 0;
}
