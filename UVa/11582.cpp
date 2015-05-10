#include <iostream>
#define MAXN 1005

using namespace std;

typedef unsigned long long ULL;
int f[MAXN][MAXN*6], period[MAXN];

int pow_mod(ULL a, ULL b, int n) {
  if(!b)
    return 1;
  int k = pow_mod(a, b/2, n);
  k = k * k % n;
  if(b % 2)
    k = (k * a) % n;
  return k;
}

int solve(ULL a, ULL b, int n) {
  //cout << "solve " << a << " and " << b << " and " << n << endl;
  if(n == 1 || a == 0)
    return 0;
  int p = pow_mod(a % period[n], b, period[n]);
  return f[n][p];
}

int main() {
  for(int n = 2; n <= 1000; n++) {
    f[n][0] = 0;
    f[n][1] = 1;
    for(int i = 2;; i++) {
      //printf("n=%d i=%d\n", n, i);
      f[n][i] = (f[n][i-1] + f[n][i-2])%n;
      if(f[n][i-1] == 0 && f[n][i] == 1) {
	period[n] = i - 1;
	break;
      }
    }
  }
  int tc;
  ios::sync_with_stdio(false);
  cin >> tc;
  //cout << "tc is " << tc << endl;
  while(tc--) {
    ULL a, b;
    int n;
    //cout << "before cin " << endl;
    cin >> a >> b >> n;
    //cout << "read numbers " << endl;
    cout << solve(a, b, n) << endl;;
  }
  return 0;
}
