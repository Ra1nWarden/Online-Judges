#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

const int maxn = 2005;
int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

struct BigInteger {
  vector<int> digits;
  bool positive;

  BigInteger();
  BigInteger(string num);
  BigInteger(long long num);
  BigInteger& operator=(const BigInteger& rhs);
  
  bool operator<(const BigInteger& rhs) const;
  bool operator>(const BigInteger& rhs) const;
  bool operator<=(const BigInteger& rhs) const;
  bool operator>=(const BigInteger& rhs) const;
  bool operator!=(const BigInteger& rhs) const;
  bool operator==(const BigInteger& rhs) const;

  BigInteger& operator++();
  BigInteger operator++(int);
  BigInteger& operator--();
  BigInteger operator--(int);
  BigInteger operator-();
  BigInteger operator+(const BigInteger& rhs) const;
  BigInteger operator-(const BigInteger& rhs) const;
  BigInteger operator*(const BigInteger& rhs) const;
  BigInteger operator/(const BigInteger& rhs) const;
  BigInteger operator%(const BigInteger& rhs) const;
  BigInteger& operator+=(const BigInteger& rhs);
  BigInteger& operator-=(const BigInteger& rhs);
  BigInteger& operator*=(const BigInteger& rhs);
  BigInteger& operator/=(const BigInteger& rhs);
  BigInteger& operator%=(const BigInteger& rhs);
};

ostream& operator<<(ostream& oss, const BigInteger& rhs);
istream& operator>>(istream& iss, BigInteger& rhs);

BigInteger dp[maxn];

void init() {
  dp[0] = BigInteger(1);
  for(int i = 0; i <= 2000; i++) {
    for(int j = 0; j < 10; j++) {
      if(!(i == 0 && j == 0) && i + cost[j] <= 2000)
	dp[i + cost[j]] += dp[i];
    }
  }
  for(int i = 2; i <= 2000; i++) {
    dp[i] += dp[i-1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  init();
  int n;
  while(cin >> n) {
    BigInteger res = dp[n];
    if(n >= 6)
      res = res + BigInteger(1);
    cout << res << endl;
  }
  return 0;
}

ostream& operator<<(ostream& oss, const BigInteger& rhs) {
  if(!rhs.positive)
    oss << "-";
  for(int i = 0; i < rhs.digits.size(); i++) {
    oss << rhs.digits[rhs.digits.size() - i - 1];
  }
  return oss;
}

istream& operator>>(istream& iss, BigInteger& rhs) {
  string s;
  if(!(iss >> s))
    return iss;
  rhs = BigInteger(s);
  return iss;
}

void RemoveLeadingZeros(vector<int>& digits) {
  bool removed = false;
  for(int i = digits.size() - 1; i >= 0; i--) {
    if(digits[i] != 0) {
      digits.resize(i + 1);
      removed = true;
      break;
    }
  }
  if(!removed) {
    digits.resize(1);
  }
} 

// Initialize to zero, positive is default to true
BigInteger::BigInteger() {
  digits.push_back(0);
  positive = true;
}

BigInteger::BigInteger(string num) {
  positive = num[0] == '-' ? false : true;
  if(!positive)
    num = num.substr(1);
  digits.resize(num.length());
  for(int i = 0; i < num.length(); i++) {
    digits[num.length() - i - 1] = atoi(num.substr(i, 1).c_str());
  }
  RemoveLeadingZeros(digits);
}

BigInteger::BigInteger(long long num) {
  stringstream ss;
  ss << num;
  BigInteger dummy(ss.str());
  positive = dummy.positive;
  digits = dummy.digits;
}

BigInteger& BigInteger::operator=(const BigInteger& rhs) {
  positive = rhs.positive;
  digits = rhs.digits;
  return *this;
}

bool BigInteger::operator<(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      if(digits.size() != rhs.digits.size()) {
	return digits.size() < rhs.digits.size();
      } else {
	for(int i = digits.size() - 1; i >= 0; i--) {
	  if(digits[i] != rhs.digits[i])
	    return digits[i] < rhs.digits[i];
	}
	return false;
      }
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummylhs > dummyrhs;
    }
  } else {
    return !positive;
  }
}

bool BigInteger::operator>(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      if(digits.size() != rhs.digits.size()) {
	return digits.size() > rhs.digits.size();
      } else {
	for(int i = digits.size() - 1; i >= 0; i--) {
	  if(digits[i] != rhs.digits[i])
	    return digits[i] > rhs.digits[i];
	}
	return false;
      }
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummylhs < dummyrhs;
    }
  } else {
    return positive;
  }
}

bool BigInteger::operator==(const BigInteger& rhs) const {
  if(digits.size() == 1 && digits[0] == 0 && rhs.digits.size() == 1 && rhs.digits[0] == 0) {
    return true;
  }
  return positive == rhs.positive && digits == rhs.digits;
}

bool BigInteger::operator<=(const BigInteger& rhs) const {
  return *this < rhs || *this == rhs;
}

bool BigInteger::operator>=(const BigInteger& rhs) const {
  return *this > rhs || *this == rhs;
}

bool BigInteger::operator!=(const BigInteger& rhs) const {
  return !(*this == rhs);
}

BigInteger& BigInteger::operator++() {
  BigInteger one("1");
  BigInteger sum = (*this + one);
  positive = sum.positive;
  digits = sum.digits;
  return *this;
}

BigInteger BigInteger::operator++(int) {
  BigInteger copy = *this;
  operator++();
  return copy;
}

BigInteger& BigInteger::operator--() {
  BigInteger one("1");
  BigInteger sum = *this - one;
  positive = sum.positive;
  digits = sum.digits;
  return *this;
}

BigInteger BigInteger::operator--(int) {
  BigInteger copy = *this;
  operator--();
  return copy;
}

BigInteger BigInteger::operator-() {
  BigInteger result = *this;
  result.positive = !result.positive;
  return result;
}

BigInteger BigInteger::operator+(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    BigInteger result;
    result.positive = positive;
    result.digits.resize(max(digits.size(), rhs.digits.size()), 0);
    bool carry = false;
    for(int i = 0; i < result.digits.size(); i++) {
      result.digits[i] = 0;
      if(i < digits.size())
	result.digits[i] += digits[i];
      if(i < rhs.digits.size())
	result.digits[i] += rhs.digits[i];
      if(carry)
	result.digits[i]++;
      carry = result.digits[i] > 9;
      result.digits[i] %= 10;
    }
    if(carry)
      result.digits.push_back(1);
    return result;
  } else {
    if(positive) {
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return *this - dummyrhs;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      return rhs - dummylhs;
    }
  }
}

BigInteger BigInteger::operator-(const BigInteger& rhs) const {
  if(positive == rhs.positive) {
    if(positive) {
      BigInteger result;
      result.positive = *this >= rhs;
      result.digits.clear();
      BigInteger large = max(*this, rhs);
      BigInteger small = min(*this, rhs);
      bool reduce = false;
      for(int i = 0; i < large.digits.size(); i++) {
	int up = large.digits[i];
	int down = 0;
	if(i < small.digits.size())
	  down = small.digits[i];
	if(reduce) {
	  up--;
	  reduce = false;
	}
	if(up < down) {
	  up += 10;
	  reduce = true;
	}
	result.digits.push_back(up - down);
      }
      // Remove leading zeros
      RemoveLeadingZeros(result.digits);
      return result;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return dummyrhs - dummylhs;
    }
  } else {
    if(positive) {
      BigInteger dummyrhs = rhs;
      dummyrhs.positive = true;
      return *this + dummyrhs;
    } else {
      BigInteger dummylhs = *this;
      dummylhs.positive = true;
      return -(dummylhs + rhs);
    }
  }
}

BigInteger BigInteger::operator*(const BigInteger& rhs) const {
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
  RemoveLeadingZeros(result.digits);
  while(carry != 0) {
    int nextdig = carry % 10;
    carry /= 10;
    result.digits.push_back(nextdig);
  }
  return result;
}

BigInteger BigInteger::operator/(const BigInteger& rhs) const {
  int rwidth = digits.size() - rhs.digits.size() + 1;
  rwidth = rwidth < 1 ? 1 : rwidth;
  BigInteger result;
  result.positive = positive == rhs.positive ? true : false;
  result.digits.resize(rwidth, 0);
  BigInteger remain = *this;
  remain.positive = true;
  for(int i = rwidth - 1; i >= 0; i--) {
    BigInteger div = rhs;
    div.positive = true;
    for(int j = 0; j < i; j++) {
      div.digits.insert(div.digits.begin(), 0);
    }
    for(int j = 9; j >= 0; j--) {
      BigInteger mult(j);
      if(div * mult <= remain) {
	result.digits[i] = j;
	remain = remain - div * mult;
	break;
      }
    }
  }
  RemoveLeadingZeros(result.digits);
  return result;
}

BigInteger BigInteger::operator%(const BigInteger& rhs) const {
  BigInteger div = (*this) / rhs;
  return *this - div * rhs;
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs) {
  *this = *this + rhs;
  return *this;
}

BigInteger& BigInteger::operator-=(const BigInteger& rhs) {
  *this = *this - rhs;
  return *this;
}

BigInteger& BigInteger::operator*=(const BigInteger& rhs) {
  *this = *this * rhs;
  return *this;
}

BigInteger& BigInteger::operator/=(const BigInteger& rhs) {
  *this = *this / rhs;
  return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger& rhs) {
  *this = *this % rhs;
  return *this;
}
