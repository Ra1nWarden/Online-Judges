#include <iostream>
#define MOD 1000000007

using namespace std;

long long choose(long long n, long long c) {
  long long result = 1;
  if(c == 0)
    return 1;
  if(c > n / 2)
    return choose(n, n-c);
  for(int i = 1; i <= c; i++) {
    result *= n;
    result /= i;
    result %= MOD;
    n--;
  }
  return result;
}

long long chooseSum(long long n, long long c, long long overflow) {
  long long bitNum = 1;
  long long result = overflow * choose(n, c) % MOD;
  for(long long i = 0; i < n; i++) {
    result +=  (choose(n-1, c-1) * bitNum % MOD);
    result %= MOD;
    bitNum <<= 1;
  }
  return result;
}

int main() {
  long long c;
  string r;
  cin >> c >> r;
  long long result = 0;
  long long overflow = 0;
  if(c == 0) {
    cout << 0 << endl;
    return 0;
  }
  for(int i= 0; i < r.length(); i++) {
    if(r[i] == '1') {
      result += chooseSum(r.length() - 1 - i, c, overflow);
      result %= MOD;
      overflow += (1 << (r.length() - 1 - i));
      overflow %= MOD;
      c--;
      if(c == 0) {
	bool fullCheck = true;
	for(int j= i+1; j < r.length(); j++) {
	  if(r[j] == '1') {
	    fullCheck = false;
	    break;
	  }
	}
	if(!fullCheck) {
	  result += overflow;
	  result %= MOD;
	}
	break;
      }
    }
  }
  cout << result << endl;
  return 0;
}
