#include <iostream>

using namespace std;

int main() {
  int n;
  while(cin >> n && n) {
    long long result = 0;
    long long carry = 0;
    for(int i= 0 ; i < n; i++) {
      long long x;
      cin >> x;
      result += (carry > 0 ? carry : -carry);
      carry += x;
    }
    cout << result << endl;
  }
  return 0;
}
