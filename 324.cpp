#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct BigInteger {
  vector<int> digits;
  bool positive;

  BigInteger();
  BigInteger(string num);
  BigInteger(long long num);
  BigInteger operator=(const BigInteger& rhs);
  
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
};

ostream& operator<<(ostream& oss, const BigInteger& rhs) {
  if(!rhs.positive)
    oss << "-";
  for(int i = 0; i < rhs.digits.size(); i++) {
    oss << rhs.digits[rhs.digits.size() - i - 1];
  }
  return oss;
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
}

BigInteger::BigInteger(long long num) {
  stringstream ss;
  ss << num;
  BigInteger dummy(ss.str());
  positive = dummy.positive;
  digits = dummy.digits;
}

BigInteger BigInteger::operator=(const BigInteger& rhs) {
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

ostream& operator<<(ostream& oss, const BigInteger& rhs);

int main() {
  int x;
  vector<int> v;
  while(cin >> x && x) {
    v.push_back(x);
  }
  map<int, vector<int> > m;
  vector<int> sorted = v;
  sort(sorted.begin(), sorted.end());
  BigInteger prod(1);
  BigInteger elem(1);
  for(int i = 0; i < sorted.size(); i++) {
    BigInteger threshold(sorted[i]);
    while(elem <= threshold) {
      prod = prod * elem;
      elem++;
    }
    vector<int> value(10, 0);
    for(int j = 0; j < prod.digits.size(); j++) {
      value[prod.digits[j]]++;
    }
    m[sorted[i]] = value;
  }
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << "! --" << endl;
    vector<int> printv = m[v[i]];
    for(int j = 0; j < printv.size(); j++) {
      if(j == 5)
	cout << endl;
      if(j != 0 && j != 5)
	cout <<  " ";
      cout << "(" << j << ")" << " " << printv[j];  
    }
    cout << endl;
  }
  return 0;
}
