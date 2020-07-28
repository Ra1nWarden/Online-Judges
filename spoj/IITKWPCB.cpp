#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while(tc--) {
    long long n;
    cin >> n;
    if(n & 1) {
      cout << n / 2 << endl;
    } else {
      long long ans = n / 2 - 1;
      if(!(ans & 1)) {
	ans == 0 ? ans++ : ans--;
      }
      cout << ans << endl;
    }
  }
  return 0 ;
}
