#include <iostream>

using namespace std;

long long SG(long long x) {
  return x % 2 == 0 ? x / 2 : SG(x / 2);
}

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    long long a, v = 0;
    cin >> n;
    while(n--) {
      cin >> a;
      v ^= SG(a);
    }
    if(v)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
