#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int j;
  int tc = 1;
  while(cin >> j && j != -1) {
    string decimal;
    cin >> decimal;
    decimal = decimal.substr(2);
    int num, den, factor, k;
    if(j != 0) {
      k = decimal.length() - j;
      num = atoi(decimal.c_str()) - atoi(decimal.substr(0, k).c_str());
      den = pow(10, k+j) - pow(10, k);
    } else {
      num = atoi(decimal.c_str());
      den = pow(10, decimal.length());
    }
    factor = gcd(den, num);
    //cout << num << ", " << den << ", " << factor << endl;
    printf("Case %d: %d/%d\n", tc++, num/factor, den/factor);
  }
  return 0;
}
