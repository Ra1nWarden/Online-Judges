#include <iostream>
#include <cmath>

using namespace std;

long long n, k, d1, d2;

bool valid(long long num) {
  if(num < 0)
    return false;
  return num % 3 == 0;
}

bool valid2(long long num) {
  return num <= k && (k - num) % 3 == 0;
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n >> k >> d1 >> d2;
    long long left = n - k;
    left -= d1;
    bool ok = false;
    if(valid2(2 * d2 + d1)) {
      // w1 w2 w3
      ok = ok || valid(left - (d1 + d2));
    }
    if(valid2(d1 + d2)) {
      // w2 min
      ok = ok || (d2 > d1 ? valid(left - 2 * (d2 - d1)) : valid(left - (d1 - d2)));
    }
    if(valid2(2 * d1 + d2)) {
      // w3 w2 w1
      ok = ok || valid(left - 2 * d2);
    }
    if(valid2(max(d1, d2) + abs(d1 - d2))) {
      // w2 max
      ok = ok || valid(left - d2);
    }
    if(ok)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
