#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void trim(vector<int>& digits) {
  bool removed = false;
  for(int i = digits.size() - 1; i >= 0; i--) {
    if(digits[i] != 0) {
      digits.resize(i + 1);
      removed = true;
      break;
    }
  }
  if(!removed)
    digits.resize(1);
}

struct BigInteger {
  vector<int> digits;
  bool positive;
  BigInteger() {
    digits.push_back(0);
    positive = true;
  }
  BigInteger(long long num) {
    positive = num >= 0;
    while(num) {
      digits.push_back(num % 10);
      num /= 10;
    }
  }
  BigInteger& operator=(const BigInteger& rhs) {
    positive = rhs.positive;
    digits = rhs.digits;
    return *this;
  }
  BigInteger operator*(const BigInteger& rhs) const {
      BigInteger result;
  result.positive = positive == rhs.positive ? true : false;
  for(int i = 0; i < rhs.digits.size(); i++) {
    int dig = rhs.digits[i];
    vector<int> step(digits.size());
    for(int j = 0; j < digits.size(); j++) {
      step[j] = digits[j] * dig;
    }
    result.digits.resize(i + step.size() + 1, 0);
    for(int j = 0; j < step.size(); j++) {
      result.digits[i + j] += step[j];
    }
  }
  int carry = 0;
  for(int i = 0; i < result.digits.size(); i++) {
    result.digits[i] += carry;
    carry = result.digits[i] / 10;
    result.digits[i] %= 10;
  }
  trim(result.digits);
  while(carry != 0) {
    int nextdig = carry % 10;
    carry /= 10;
    result.digits.push_back(nextdig);
  }
  return result;
  }
};

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    BigInteger num(1);
    long long x;
    scanf("%lld", &x);
    while(x) {
      BigInteger fact(x);
      num = num * fact;
      x--;
    }
    for(int i = num.digits.size() - 1; i >= 0; i--)
      printf("%d", num.digits[i]);
    printf("\n");
  }
  return 0;
}
