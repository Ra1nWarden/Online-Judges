#include <iostream>

using namespace std;

bool DEBUG = false;

struct Fraction {
  int d, n;
  Fraction(int a, int b) : n(a), d(b) {}
  bool operator<(const Fraction& another) const {
    if (d == 0)
      return false;
    else if (another.d == 0)
      return true;
    return n * another.d < another.n * d;
  }
  bool operator>(const Fraction& another) const {
    if (another.d == 0) {
      return false;
    }
    else if (d == 0) {
      return true;
    }
    return n * another.d > another.n * d;
  }
};

ostream& operator<<(ostream& oss, const Fraction& frac) {
  oss << frac.n << " / " << frac.d << endl;
  return oss;
}

void binaryFind(Fraction f, Fraction start, Fraction end) {
  Fraction mid(start.n + end.n, start.d + end.d);
  if (DEBUG) {
    cout << "f is  "<< f << endl;
    cout << "mid is " << mid << endl;
  }
  if (f > mid) {
    cout << 'R';
    binaryFind(f, mid, end);
  } else if (f < mid) {
    cout << 'L';
    binaryFind(f, start, mid);
  } else
    return;
}

int main() {
  int n, d;
  Fraction start(0, 1);
  Fraction end(1, 0);
  Fraction identity(1, 1);
  while(cin >> n >> d && !cin.eof()) {
    Fraction f(n, d);
    if (n > d) {
      cout << 'R';
      binaryFind(f, identity, end);
    }
    else if (n < d) {
      cout << 'L';
      binaryFind(f, start, identity);
    }
    else
      cout << "I";
    cout << endl;
  }
  return 0;
}
