#include <iostream>

using namespace std;

int main() {
  long long n, k;
  while(cin >> n >> k) {
    long long result = 0;
    long long remain = 0;
    do {
      result += n;
      remain += n;
      n = remain / k;
      remain = remain % k;
    } while(n != 0);
    cout << result << endl;
  }
  return 0;
}
