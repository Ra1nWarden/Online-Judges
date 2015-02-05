#include <iostream>
#include <bitset>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int tc;
  cin >> tc >> ws;
  for(int c = 1; c <= tc; c++) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bitset<30> n1(s1);
    bitset<30> n2(s2);
    cout << "Pair #" << c << ": ";
    cout << (gcd(n1.to_ulong(), n2.to_ulong()) != 1 ? "All you need is love!" : "Love is not all you need!") << endl;
  }
  return 0;
}
