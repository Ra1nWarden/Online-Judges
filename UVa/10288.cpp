#include <bits/stdc++.h>

using namespace std;

long long GreatestCommonDivisor(long long a, long long b);
long long LeastCommonMultiple(long long a, long long b);

struct Rational {
  long long num;
  long long denom;

  Rational();
  Rational(long long n, long long m);
  Rational operator=(const Rational& rhs);

  bool operator<(const Rational& rhs) const;
  bool operator>(const Rational& rhs) const;
  bool operator==(const Rational& rhs) const;
  bool operator<=(const Rational& rhs) const;
  bool operator>=(const Rational& rhs) const;
  bool operator!=(const Rational& rhs) const;

  Rational operator+(const Rational& rhs) const;
  Rational operator-(const Rational& rhs) const;
  Rational operator*(const Rational& rhs) const;
  Rational operator/(const Rational& rhs) const;
};

ostream& operator<<(ostream& oss, const Rational& rhs);

int main() {
  long long n;
  ios::sync_with_stdio(false);
  while(cin >> n) {
    Rational ans;
    ans.num = 0;
    for(long long i = 1; i <= n; i++) {
      Rational ans2 = ans + Rational(n, i);
      long long d = GreatestCommonDivisor(ans2.num, ans2.denom);
      ans.num = ans2.num / d;
      ans.denom = ans2.denom / d;
    }
    cout << ans << endl;
  }
  return 0;
}

Rational::Rational() {
  num = 1;
  denom = 1;
}

Rational::Rational(long long n, long long m) : num(n), denom(m) {
  assert(m != 0);
}

Rational Rational::operator=(const Rational& rhs) {
  Rational res;
  res.num = rhs.num;
  res.denom = rhs.denom;
  return res;
}

bool Rational::operator<(const Rational& rhs) const {
  long long common = LeastCommonMultiple(denom, rhs.denom);
  return num * (common / denom) < rhs.num * (common / rhs.denom);
}

bool Rational::operator>(const Rational& rhs) const {
  long long common = LeastCommonMultiple(denom, rhs.denom);
  return num * (common / denom) > rhs.num * (common / rhs.denom);
}

bool Rational::operator==(const Rational& rhs) const {
  long long selffactor = GreatestCommonDivisor(num, denom);
  long long rhsfactor = GreatestCommonDivisor(rhs.num, rhs.denom);
  return num / selffactor == rhs.num / rhsfactor && denom / selffactor == rhs.denom / rhsfactor;
}

bool Rational::operator<=(const Rational& rhs) const {
  return *this < rhs || *this == rhs;
}

bool Rational::operator>=(const Rational& rhs) const {
  return *this > rhs || *this == rhs;
}

bool Rational::operator!=(const Rational& rhs) const {
  return !(*this == rhs);
}

Rational Rational::operator+(const Rational& rhs) const {
  Rational res;
  res.denom = LeastCommonMultiple(denom, rhs.denom);
  res.num = num * (res.denom / denom) + rhs.num * (res.denom / rhs.denom);
  //cout << num << " / " << denom << " + " << rhs.num << " / " << rhs.denom << endl;
  //cout << res.num << " / " << res.denom << endl; 
  return res;
}

Rational Rational::operator-(const Rational& rhs) const {
  Rational res;
  res.denom = LeastCommonMultiple(denom, rhs.denom);
  res.num = num * res.denom / denom - rhs.num * res.denom / rhs.denom;
  return res;
}

Rational Rational::operator*(const Rational& rhs) const {
  Rational res;
  res.num = num * rhs.num;
  res.denom = denom * rhs.denom;
  long long common = GreatestCommonDivisor(res.num, res.denom);
  res.num /= common;
  res.denom /= common;
  return res;
}

Rational Rational::operator/(const Rational& rhs) const {
  assert(rhs.num != 0);
  Rational rhscpy = rhs;
  swap(rhscpy.num, rhscpy.denom);
  return (*this) * rhscpy;
}

ostream& operator<<(ostream& oss, const Rational& rhs) {
  long long whole = rhs.num / rhs.denom;
  long long x = rhs.num % rhs.denom;
  if(x == 0) {
    oss << whole;
    return oss;
  }
  long long wc = whole;
  while(wc > 0) {
    oss << " ";
    wc /= 10;
  }
  if(whole == 0)
    oss << x << endl;
  else 
    oss << " " << x << endl;
  if(whole != 0)
    oss << whole << " ";
  long long nc = rhs.denom;
  while(nc > 0) {
    oss << "-";
    nc /= 10;
  }
  oss << endl;
  wc = whole;
  while(wc > 0) {
    oss << " ";
    wc /= 10;
  }
  if(whole == 0)
    oss << rhs.denom;
  else
    oss << " " << rhs.denom;
  return oss;
}

long long GreatestCommonDivisor(long long a, long long b) {
  return b == 0 ? a : GreatestCommonDivisor(b, a % b);
}

long long LeastCommonMultiple(long long a, long long b) {
  return a * (b / GreatestCommonDivisor(a, b));
}
