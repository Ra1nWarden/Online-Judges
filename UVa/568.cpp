#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int digit[10001];

int main() {
  memset(digit, 0, sizeof digit);
  digit[0] = 1;
  digit[1] = 1;
  int prod = 1;
  for(int i = 2; i < 10001; i++) {
    prod = prod * i;
    while(prod % 10 == 0)
      prod /= 10;
    prod %= 100000;
    digit[i] = prod % 10;
  }
  int x;
  while(cin >> x) {
    cout << right << setw(5) << x << " -> " << digit[x] << endl;
  }
  
  return 0;
}
